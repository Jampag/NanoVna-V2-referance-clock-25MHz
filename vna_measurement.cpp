#include "vna_measurement.hpp"

VNAMeasurement::VNAMeasurement(): sampleProcessor(_emitValue_t {this}) {

}

void VNAMeasurement::init() {
	sampleProcessor.init();
}
void VNAMeasurement::setCorrelationTable(const int16_t* table, int length) {
	sampleProcessor.setCorrelationTable(table, length);
	sampleProcessor.emitValue = _emitValue_t {this};
}
void VNAMeasurement::processSamples(uint16_t* buf, int len) {
	sampleProcessor.process(buf, len);
}

void VNAMeasurement::setSweep(freqHz_t startFreqHz, freqHz_t stepFreqHz, int points, int dataPointsPerFreq) {
	sweepStartHz = startFreqHz;
	sweepStepHz = stepFreqHz;
	sweepPoints = points;
	sweepDataPointsPerFreq = dataPointsPerFreq;
	resetSweep();
}

void VNAMeasurement::resetSweep() {
	__sync_synchronize();
	sweepCurrPoint = -1;
}


void VNAMeasurement::setMeasurementPhase(VNAMeasurementPhases ph) {
	phaseChanged(ph);
	measurementPhase = ph;
	periodCounterSwitch = 0;
	currDP = {0, 0};
}
static inline complexf to_complexf(VNAMeasurement::complexi value) {
	return {(float) value.real(), (float) value.imag()};
}

void VNAMeasurement::sweepAdvance() {
	sweepCurrPoint++;
	if(sweepCurrPoint >= sweepPoints)
		sweepCurrPoint = 0;

	currFreq = sweepStartHz + sweepStepHz*sweepCurrPoint;
	frequencyChanged(currFreq);

	periodCounterSynth = nWaitSynth;

	ecalCounterOffset++;
	if(ecalCounterOffset >= ecalIntervalPoints)
		ecalCounterOffset = 0;
	ecalCounter = ecalCounterOffset;
	if(sweepCurrPoint == 0) {
		periodCounterSynth *= 2;
		currGain = gainMax;
	}
}

void VNAMeasurement::sampleProcessor_emitValue(int32_t valRe, int32_t valIm, bool clipped) {
	auto currPoint = sweepCurrPoint;
	/* If -1 then we restart */
	if(currPoint == -1) {
		freqHz_t start = sweepStartHz;
		freqHz_t stop = start + sweepStepHz*sweepPoints;
		sweepSetupChanged(start, stop);
		dpCounterSynth = 0;
		setMeasurementPhase(VNAMeasurementPhases::REFERENCE);
		sweepAdvance();
		periodCounterSynth *= 2;
		return;
	}
	/* If periodCounterSynth not elapsed, decrement and wait for it */
	if(periodCounterSynth > 0) {
		// still waiting for synthesizer
		periodCounterSynth--;
		periodCounterSwitch = 0;
		gainChangeOccurred = false;
		return;
	}
	if(periodCounterSwitch >= nWaitSwitch) {
		currDP += complexi{valRe, valIm};

		if(measurementPhase == VNAMeasurementPhases::THRU) {
			if(clipped) {
				// ADC clip occurred during a measurement period
				if(currGain > gainMin) {
					// decrease gain and redo measurement
					currGain--;
					gainChanged(currGain);
					periodCounterSwitch = 0;
					currDP = {0, 0};
					sampleProcessor.clipFlag = false;
					gainChangeOccurred = true;
					return;
				}
			}
		}

		if(measurementPhase == VNAMeasurementPhases::THRU)
			clipFlag2 |= clipped;
		else clipFlag |= clipped;
	} else {
		sampleProcessor.clipFlag = false;
	}
	periodCounterSwitch++;

	/* If switch time not elapsed, wait some more */
	if(periodCounterSwitch < (nWaitSwitch + nPeriods*nPeriodsMultiplier)) {
		return;
	}

	// Loop through measurement phase
	switch(measurementPhase) {
		case VNAMeasurementPhases::REFERENCE:
			currFwd = currDP;
			setMeasurementPhase(VNAMeasurementPhases::REFL);
			break;
		case VNAMeasurementPhases::REFL:
			currRefl = currDP;
			setMeasurementPhase(VNAMeasurementPhases::THRU);
			gainChanged(currGain);
			break;
		case VNAMeasurementPhases::THRU:
			currThru = currDP;

			if(currGain < gainMax && !gainChangeOccurred) {
				float mag = abs(to_complexf(currThru));
				float fullScale = float(adcFullScale) * sampleProcessor.accumPeriod * nPeriods;
				if(mag < (fullScale * 0.15)) {
					// signal level too low; increase gain and retry
					currGain++;
					gainChanged(currGain);
					gainChangeOccurred = true;
					periodCounterSwitch = 0;
                    currDP = {0, 0};
					return;
				}
			}

			switch(measurement_mode) {
				case MEASURE_MODE_FULL:
					ecalCounter++;
					if(ecalCounter >= ecalIntervalPoints)
						ecalCounter = 0;
					if(ecalCounter == 0) {
#ifdef ECAL_PARTIAL
						setMeasurementPhase(VNAMeasurementPhases::ECALLOAD);
#else
						setMeasurementPhase(VNAMeasurementPhases::ECALTHRU);
#endif
						return;
					} else {
						setMeasurementPhase(VNAMeasurementPhases::REFERENCE);
					}
					break;
				case MEASURE_MODE_REFL_THRU_REFRENCE: /* AKA no ECAL */
					/* Go back to the start: REFERENCE */
					setMeasurementPhase(VNAMeasurementPhases::REFERENCE);
					break;
				case MEASURE_MODE_REFL_THRU:
					/* aka CW mode
					 * And keep the signal on the ouput */
					setMeasurementPhase(VNAMeasurementPhases::REFL);
					break;
			}
			doEmitValue(false);
			break;

		case VNAMeasurementPhases::ECALTHRU:
			ecal[2] = to_complexf(currDP);
			setMeasurementPhase(VNAMeasurementPhases::ECALLOAD);
			break;

		case VNAMeasurementPhases::ECALLOAD:
			ecal[0] = to_complexf(currDP);
#ifdef ECAL_PARTIAL
			/* Go back to the start: REFERENCE */
			setMeasurementPhase(VNAMeasurementPhases::REFERENCE);
			doEmitValue(true);
#else
			setMeasurementPhase(VNAMeasurementPhases::ECALSHORT);
#endif
			break;
		case VNAMeasurementPhases::ECALSHORT:
			ecal[1] = to_complexf(currDP);
			/* Go back to the start: REFERENCE */
			setMeasurementPhase(VNAMeasurementPhases::REFERENCE);
			doEmitValue(true);
			break;
	}
}

void VNAMeasurement::doEmitValue(bool ecal) {
	// emit new data point
	VNAObservationSet value = {to_complexf(currRefl), to_complexf(currFwd), to_complexf(currThru)};
	emitDataPoint(sweepCurrPoint, currFreq, value, ecal ? this->ecal : nullptr);

	clipFlag = false;
	clipFlag2 = false;
	dpCounterSynth++;
	if(int(dpCounterSynth) >= sweepDataPointsPerFreq && sweepPoints > 1) {
		dpCounterSynth = 0;
		sweepAdvance();
	}
}

void VNAMeasurement::_emitValue_t::operator()(int32_t* valRe, int32_t* valIm) {
	m->sampleProcessor_emitValue(*valRe, *valIm, m->sampleProcessor.clipFlag);
}
