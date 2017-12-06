#include "Arduino.h"
#include "TemperatureSensor.h"

#define PIN_CLOCK 4
#define PIN_DATA 5
#define PIN_RESET 6

void tempChangeEventCallback(TemperatureEventInfo* eventInfo) {
    char scale;
    switch (eventInfo->scale) {
        case TEMP_SCALE_CELCIUS:
            scale = 'C';
            break;
        case TEMP_SCALE_FARENHEIT:
            scale = 'F';
            break;
        case TEMP_SCALE_KELVIN:
            scale = 'K';
            break;
        case TEMP_SCALE_RANKINE:
            scale = 'R';
            break;
    }

    Serial.print(F("Previous temp reading: "));
    Serial.print(eventInfo->oldTemp);
    Serial.println(scale);

    Serial.print(F("New temp reading: "));
    Serial.print(eventInfo->newTemp);
    Serial.println(scale);
    Serial.println();
}

TemperatureSensor sensor(PIN_CLOCK, PIN_DATA, PIN_RESET, tempChangeEventCallback);

void setup() {
    Serial.begin(9600);
    while (!Serial) {
        delay(1);
    }
}

void loop() {
    sensor.loop();

    // Get a new reading every 3 seconds.
    delay(3000);
}
