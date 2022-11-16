#include <Arduino.h>
#include "LDR.h"

#define PIN_LDR 5

LDR lightSensor(PIN_LDR);

void setup() {
	Serial.begin(9600);
	while (!Serial) {
		delay(10);
	}

	if (!lightSensor.begin()) {
		Serial.println(F("ERROR: Failed to init light sensor!"));
	}
}

void loop() {
	lightSensor.performReading();

	int brightnessPercent = lightSensor.readSensorBrightness();
	Serial.print(F("Brightness: "));
	Serial.print(brightnessPercent);
	Serial.println(F("%"));

	BrightnessLevel level = lightSensor.getBrightnessLevel();
	Serial.print(F("Brightness level: "));
	switch (level) {
		case BrightnessLevel::DARK:
			Serial.println(F("Dark"));
			break;
		case BrightnessLevel::DIM:
			Serial.println(F("Dim"));
			break;
		case BrightnessLevel::LIGHT:
			Serial.println(F("Light"));
			break;
		case BrightnessLevel::BRIGHT:
			Serial.println(F("Bright"));
			break;
		case BrightnessLevel::VERY_DARK:
			Serial.println(F("Very Dark"));
			break;
		default:
			break;
	}
	
	delay(5000);
}