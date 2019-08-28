#include "HCSR04.h"

#define PIN_TRIGGER 4
#define PIN_ECHO 5

HCSR04 distanceSensor(PIN_TRIGGER, PIN_ECHO);

void setup() {
    Serial.begin(9600);
    distanceSensor.begin();
}

void loop() {
    double distanceCM = distanceSensor.measureDistanceCm();
    Serial.print(F("Distance (cm): "));
    Serial.println(distanceCM);

    double distanceIN = distanceSensor.measureDistanceIn();
    Serial.print(F("Distance (in): "));
    Serial.print(distanceIN);
    delay(1000);
}