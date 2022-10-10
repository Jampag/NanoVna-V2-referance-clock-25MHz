#pragma once

#include <libopencm3/usb/usbd.h>
#include <mculib/small_function.hpp>
#include <mculib/itoa.hpp>
#include <string.h>


namespace usbSerial {
	extern small_function<void(uint8_t* s, int len)> _receiveCB;
	usbd_device* initUsbSerial(const usb_device_descriptor* descriptor = nullptr);
	void send(usbd_device* dev, const char* s, int len);
	bool send_noWait(usbd_device* dev, const char* s, int len);
}

namespace mculib {

	class USBSerial {
	public:
		usbd_device* acm_dev;
		small_function<void(uint8_t* s, int len)> _receiveCB;

		void begin(int baud) {
			acm_dev = usbSerial::initUsbSerial();
		}
		// usb serial specific init
		void begin(const usb_device_descriptor* descriptor) {
			acm_dev = usbSerial::initUsbSerial(descriptor);
		}
		bool trySend(const char* s, int len) {
			return usbSerial::send_noWait(acm_dev, s, len);
		}
		void _print(const char* s, int len) {
			usbSerial::send(acm_dev, s, len);
		}
		void print(const char* s, int len) {
			int chunkMaxSize=32;
			for(int i=0;i<len;i+=chunkMaxSize) {
				int chunkSize = len-i;
				if(chunkSize>chunkMaxSize) chunkSize = chunkMaxSize;
				_print(s+i, chunkSize);
			}
		}
		void print(const char* s) {
			print(s, strlen(s));
		}
		void println(const char* s) {
			print(s);
			print("\r\n", 2);
		}
		void print(int64_t i) {
			char tmp[21];
			itoa1(i, tmp);
			print(tmp);
		}
		void println(int64_t i) {
			print(i);
			print("\r\n", 2);
		}

		void setReceiveCallback(const small_function<void(uint8_t* s, int len)>& cb) {
			usbSerial::_receiveCB = cb;
			_receiveCB = cb;
		}
	};
}
