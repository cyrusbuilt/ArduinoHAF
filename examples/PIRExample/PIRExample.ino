#include "Arduino.h"
#include "PIR.h"

#define PIN_PIR 4

void onPirStateChange(PirInfo* sender) {
    Serial.println(F("PIR sensor state changed!"));
    Serial.print(F("PIR name: "));
    Serial.println(sender->name);
    Serial.print(F("PIR attached to pin: "));
    Serial.println(sender->pin);
    Serial.print(F("PIR sensor state: "));
    Serial.println(sender->state == HIGH ? "HIGH" : "LOW");
}

PIR myPirSensor(PIN_PIR, onPirStateChange, "TEST_PIR");

void setup() {
    Serial.begin(9600);
    while (!Serial) {
      delay(1);
    }

    myPirSensor.init();
}

void loop() {
    myPirSensor.loop();
}
