#ifdef ESP32
#include "ESP32_Tone.h"

void tone(byte pin, int freq, unsigned long duration) {
	ledcSetup(0, 2000, 8);
	ledcAttachPin(pin, 0);
	ledcWriteTone(0, freq);
	
	if (duration > 0) {
		delay(duration);
		ledcWriteTone(0, 0);
	}
}

void noTone(byte pin) {
	tone(pin, 0);
}
#endif