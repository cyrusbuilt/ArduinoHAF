#include "HCSR04.h"

#define PIN_TRIGGER 4
#define PIN_ECHO 5

void onAlarmState(HCSR04Info* sender) {
    Serial.print(F("Distance (cm): "));
    Serial.println(sender->currentDistance);

    Serial.print(F("Distance (in): "));
    Serial.println(sender->currentDistance * CM_TO_IN_MULTIPLIER);

    Serial.print(F("Alarm distance (cm): "));
    Serial.println(sender->alarmDistance);

    Serial.print(F("Alarm distance hit: "));
    Serial.println(sender->isAlarm);
}

HCSR04 distanceSensor(PIN_TRIGGER, PIN_ECHO, onAlarmState);

void setup() {
    Serial.begin(9600);
    distanceSensor.begin();
    distanceSensor.setAlarmDistance(20);
}

void loop() {
    distanceSensor.loop();
    delay(1000);
}