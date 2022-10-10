#pragma once
#include <stdint.h>
#include <string_view>

namespace mculib {
	class MessageLog {
	public:
		char* buffer;
		uint32_t bufferSizeBytes;
		uint32_t bufferSizeMask;
		volatile uint32_t _wpos;
		
		// bufferSizeBytes must be a power of 2
		MessageLog(char* buffer, uint32_t bufferSizeBytes);

		// multiple simultaneous appends is supported
		void append(std::string_view message, bool newLine=false);

		void printf(const char* fmt, ...);

		// rotate the buffer so that the earliest message is at position 0,
		// and add null byte to the end
		void rotate();

		// returns a counter that counts the number of bytes written so far.
		// the value of the counter may jump if rotate() is called.
		uint32_t bytesWritten();
	};

	extern MessageLog messageLog;
	
};

extern "C" const char* dmesg();
extern "C" const char* dmesg1(uint32_t startPos);
