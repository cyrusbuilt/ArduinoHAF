#include <Arduino.h>
#include "WaterLevelSensor.h"

#define PIN_SENSOR A0

WaterLevelSensor sensor(PIN_SENSOR);

void waitForInput() {
    while(Serial.available() < 1) {
        delay(50);
    }
}

String getInputString() {
    char c;
    String result = "";
    bool gotEndMarker = false;
    while (!gotEndMarker) {
        if (Serial.available() > 0) {
            c = Serial.read();
            if (c == '\n') {
                gotEndMarker = true;
                break;
            }

            Serial.print(c);
            result += c;
        }
    }

    return result;
}

void calibrateSensor() {
    Serial.println(F("Beginning calibration sequence...\n\n"));
    Serial.println(F("Step 1: Place sensor in fluid container to be measured."));
    Serial.println(F("Step 2: Enter tape length in centimeters: "));
    waitForInput();
    String resultStr = getInputString();
    short length = (short)resultStr.toInt();
    sensor.setTapeLengthCm(length);
    Serial.println(F("Step 3: Make sure container is empty and press any key to continue..."));
    waitForInput();
    float reading = sensor.read();
    Serial.print(F("Min value = "));
    Serial.println(reading);
    sensor.setMinValue(reading);
    Serial.println(F("Step 4: Fill container until full and then press any key to continue..."));
    waitForInput();
    reading = sensor.read();
    Serial.print(F("Max value = "));
    Serial.println(reading);
    sensor.setMaxValue(reading);
    Serial.println("\n\nCalibration procedure complete.");
}

void setup() {
    Serial.begin(9600);
    while(!Serial) {
        delay(10);
    }

    sensor.begin();
    calibrateSensor();
}

void loop() {
    // Meaure the fluid level every 5 seconds.
    float val = sensor.read();
    int percent = sensor.getPercentFull();
    float levelcm = sensor.getLevelCm();
    float levelin = sensor.getLevelInches();
    Serial.print(F("Sensor reading: "));
    Serial.println(val);
    Serial.print(F("Percent full: "));
    Serial.println(percent);
    Serial.print(F("Fluid level in CM: "));
    Serial.println(levelcm);
    Serial.print(F("Fluid level in Inches: "));
    Serial.println(levelin);
    Serial.println("\n\n");
    delay(5000);
}