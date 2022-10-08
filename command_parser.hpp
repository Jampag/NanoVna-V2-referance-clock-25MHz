#pragma once
#include <mculib/small_function.hpp>
#include <stdint.h>

/*
-- command types:
-- bytes (hex):
--  0  1  2  3  4  5
-- 00                   : nop
-- 0d                   : return ascii '2' (0x32)
-- 10 AA                : read register (address in AA)
-- 11 AA                : read 2-byte register (address in AA)
-- 12 AA                : read 4-byte register (address in AA)
-- 18 AA NN             : read up to N values from FIFO (bytes per value is implementation defined)
-- 20 AA XX             : write register (address in AA, value in XX)
-- 21 AA XX XX          : write 2-byte register (address in AA, values in XX)
-- 22 AA XX XX XX XX    : write 4-byte register (address in AA, values in XX)
-- 23 AA XX XX XX XX    : write 8-byte register (address in AA, values in XX)
-- 28 AA NN             : write N bytes into FIFO
*/
class CommandParser {
public:
	// user provided handlers

	// read fifo command handler
	small_function<void(int address, int nValues)> handleReadFIFO;

	// write fifo command handler.
	// nBytes is the number of bytes in data.
	// If nonzero, totalBytes is the total bytes in this transaction.
	// If totalValues is 0, this is a continuation of an earlier transaction.
	small_function<void(int address, int totalBytes, int nBytes, const uint8_t* data)> handleWriteFIFO;

	// called when a register is written
	small_function<void(int address)> handleWrite;

	// send data to the stream
	small_function<void(const uint8_t* s, int len)> send;

	// user provided registers area
	uint8_t* registers = nullptr;
	int registersSizeMask = 0; // size of registers - 1

	// process stream data
	void handleInput(const uint8_t* s, int len);

	// state variables
	int cmdPhase = 0;
	uint8_t cmdOpcode = 0;
	uint8_t cmdAddress = 0xff;
	uint8_t cmdEndAddress = 0xff;
	uint8_t cmdStartAddress = 0;
	int writeFIFOBytesLeft = 0;
};
