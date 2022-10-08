#include "synthesizers.hpp"
#include <board.hpp>
#include <mculib/si5351.hpp>
#include <mculib/printk.hpp>

using namespace board;

namespace synthesizers {
	bool si5351_setup() {
		using namespace Si5351;

		si5351.SetFieldsToDefault();	//initialize the structure with default "safe" values

		// hook up i2c
		uint8_t devAddr = 0xC0;
		si5351.ReadRegister = [devAddr](uint8_t addr) -> uint8_t {
			return si5351_i2c.read_si5351(devAddr, addr);
		};
		si5351.WriteRegister = [devAddr](uint8_t addr, uint8_t data) -> int {
			return si5351_i2c.write(devAddr, addr, data);
		};
		si5351.WriteRegisters = [devAddr](uint8_t* data, int len) -> int {
			return si5351_i2c.write(devAddr, data, len);
		};
		si5351.OSC.OSC_XTAL_Load = XTAL_Load_4_pF;	//use 4 pF load for crystal

		auto rPLL = si5351_rxPLL;
		auto tPLL = si5351_txPLL;
		auto rPort = si5351_rxPort;
		auto tPort = si5351_txPort;
		auto pPort = si5351_passthruPort;

		si5351.PLL[rPLL].PLL_Clock_Source = PLL_Clock_Source_XTAL;	//select xrystal as clock input for the PLL
		si5351.PLL[rPLL].PLL_Multiplier_Integer = 32*128;				//multiply the clock frequency by 32, this gets us 800 MHz clock
		si5351.PLL[rPLL].PLL_Multiplier_Numerator = 1*8;
		si5351.PLL[rPLL].PLL_Multiplier_Denominator = xtalFreqHz / 1000;

		si5351.PLL[tPLL].PLL_Clock_Source = PLL_Clock_Source_XTAL;
		si5351.PLL[tPLL].PLL_Multiplier_Integer = 32*128;
		si5351.PLL[tPLL].PLL_Multiplier_Numerator = 2*8;
		si5351.PLL[tPLL].PLL_Multiplier_Denominator = xtalFreqHz / 1000;

		si5351.MS[rPort].MS_Clock_Source = MS_Clock_Source_PLLA;
		si5351.MS[rPort].MS_Divider_Integer = 8; // divide pll frequency by 8

		si5351.MS[tPort].MS_Clock_Source = MS_Clock_Source_PLLA;
		si5351.MS[tPort].MS_Divider_Integer = 8; // divide pll frequency by 8

		si5351.CLK[rPort].CLK_R_Div = CLK_R_Div1; // divide by 1; 100MHz
		si5351.CLK[rPort].CLK_Enable = ON;	//turn on the output
		si5351.CLK[rPort].CLK_I_Drv = CLK_I_Drv_8mA;

		if(pPort >= 0) {
			si5351.CLK[pPort].CLK_Clock_Source = CLK_Clock_Source_XTAL;
			si5351.CLK[pPort].CLK_R_Div = CLK_R_Div1; // divide by 1; 24MHz
			si5351.CLK[pPort].CLK_Enable = ON;	//turn on the output
			si5351.CLK[pPort].CLK_I_Drv = CLK_I_Drv_2mA;
		}

		si5351.CLK[tPort].CLK_R_Div = CLK_R_Div1; // divide by 1; 100MHz
		si5351.CLK[tPort].CLK_Enable = ON;	//turn on the output
		si5351.CLK[tPort].CLK_I_Drv = CLK_I_Drv_2mA;

		return si5351.Init() == 0;
	}

	// Find better approximate values for n/d
	#define MAX_DENOMINATOR ((1 << 20) - 1)
	static inline void approximate_fraction(uint32_t *n, uint32_t *d)
	{
	  // cf. https://github.com/python/cpython/blob/master/Lib/fractions.py#L227
	  uint32_t denom = *d;
	  if (denom > MAX_DENOMINATOR) {
	    uint32_t num = *n;
	    uint32_t p0 = 0, q0 = 1, p1 = 1, q1 = 0;
	    while (denom != 0) {
	      uint32_t a = num / denom;
	      uint32_t b = num % denom;
	      uint32_t q2 = q0 + a*q1;
	      if (q2 > MAX_DENOMINATOR)
	        break;
	      uint32_t p2 = p0 + a*p1;
	      p0 = p1; q0 = q1; p1 = p2; q1 = q2;
	      num = denom; denom = b;
	    }
	    *n = p1;
	    *d = q1;
	  }
	}

	int si5351_set(uint32_t rxFreqHz, uint32_t txFreqHz) {
		using namespace Si5351;
		int ret = 0;
		CLKRDiv rDiv = CLK_R_Div1;

		// choose the same pll frequency and rdiv settings for both ports.
		// PLL should be configured between 600 and 900 MHz
		// Pick a multiple of 24Mhz. (The Xtal freq)
		uint32_t pllFreqHz = 888000000;
		uint32_t mult = pllFreqHz/xtalFreqHz;
		uint32_t N = mult * 128;

		pllFreqHz = xtalFreqHz * mult;

		uint32_t divInputFreqHz = pllFreqHz;

		if(rxFreqHz < 500000) { /* Below 500Khz */
			rDiv = CLK_R_Div128;
			divInputFreqHz /= 128;
		} else if(rxFreqHz < 1000000) { /* Between 500hz and 1 Mhz */
			rDiv = CLK_R_Div4;
			divInputFreqHz /= 4;
		} else if(rxFreqHz >= 100000000) { /* Above 100Mhz */
			// div by 6 mode
			int xtalFreqKHz = xtalFreqHz / 1000;
			for(int i=0; i<2; i++) {
				uint32_t freqHz = (i == 0) ? rxFreqHz : txFreqHz;
				int pll = (i == 0) ? si5351_rxPLL : si5351_txPLL;
				int port = (i == 0) ? si5351_rxPort : si5351_txPort;

				// set msdiv to 6
				if(si5351.MS[port].MS_Divider_Integer != 6
						|| si5351.MS[port].MS_Divider_Numerator != 0) {
					si5351.MS[port].MS_Divider_Integer = 6;
					si5351.MS[port].MS_Divider_Numerator = 0;
					si5351.MS[port].MS_Divider_Denominator = 1;
					si5351.MS[port].MS_Clock_Source = (i == 1) ? MS_Clock_Source_PLLB : MS_Clock_Source_PLLA;
					si5351.MSConfig((MSChannel) port);
				}

				if(si5351.CLK[port].CLK_R_Div != rDiv) {
					si5351.CLK[port].CLK_R_Div = rDiv;
					si5351.CLKConfig((CLKChannel) port);
				}

				// calculate pll settings
				uint32_t mult = uint32_t(uint64_t(freqHz)*6*128/1000);
				uint32_t N = mult/xtalFreqKHz;
				uint32_t frac = mult - N*xtalFreqKHz;

				si5351.PLL[pll].PLL_Multiplier_Integer = N;
				si5351.PLL[pll].PLL_Multiplier_Numerator = frac;
				si5351.PLL[pll].PLL_Multiplier_Denominator = xtalFreqKHz;

				si5351.PLLConfig((PLLChannel) pll);
			}
			si5351.PLLReset2();

			return 2;
		}


		if(si5351.PLL[si5351_rxPLL].PLL_Multiplier_Integer != N
				|| si5351.PLL[si5351_rxPLL].PLL_Multiplier_Numerator != 0) {
			si5351.PLL[si5351_rxPLL].PLL_Multiplier_Integer = N;
			si5351.PLL[si5351_rxPLL].PLL_Multiplier_Numerator = 0;
			si5351.PLL[si5351_rxPLL].PLL_Multiplier_Denominator = 1;
			si5351.PLLConfig((PLLChannel) si5351_rxPLL);
			si5351.PLLReset((PLLChannel) si5351_rxPLL);
			ret = 2;
		}

		for(int i=0; i<2; i++) {
			uint32_t freqHz = (i == 0) ? rxFreqHz : txFreqHz;
			int port = (i == 0) ? si5351_rxPort : si5351_txPort;

			uint32_t div = divInputFreqHz / freqHz; // range: 8 ~ 1800
			uint32_t num = divInputFreqHz % freqHz;
			uint32_t denom = freqHz;
			approximate_fraction(&num, &denom);

			// f = divInputFreqHz / (div + num/denom)
			// = divInputFreqHz / ((div*denom + num) / denom)
			// = divInputFreqHz * denom / (div*denom + num)
			//uint32_t f = uint32_t(uint64_t(divInputFreqHz) * denom / (uint64_t(div)*denom + num));

			si5351.MS[port].MS_Divider_Integer = div;
			si5351.MS[port].MS_Divider_Numerator = num;
			si5351.MS[port].MS_Divider_Denominator = denom;
			si5351.MS[port].MS_Clock_Source = (si5351_rxPLL == 1) ? MS_Clock_Source_PLLB : MS_Clock_Source_PLLA;
			si5351.MSConfig((MSChannel) port);
			//printk("freq %d, div %d, num %d, denom %d\n", freq_khz, div, num, denom);

			if(si5351.CLK[port].CLK_R_Div != rDiv) {
				si5351.CLK[port].CLK_R_Div = rDiv;
				si5351.CLKConfig((CLKChannel) port);
				if(ret < 1) ret = 1;
			}
		}
		return ret;
	}
}
