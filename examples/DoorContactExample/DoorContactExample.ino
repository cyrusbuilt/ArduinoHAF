#include <Arduino.h>
#include "DoorContact.h"

#define PIN_CONTACT 4

void onDoorStateChange(DoorInfo* sender) {
    Serial.println(F("Door state changed!"));
    Serial.print(F("Door contact attached to pin: "));
    Serial.print(sender->pin);
    Serial.print(F("Door state: "));
    if (sender->state == DOOR_STATE_OPEN) {
        Serial.println(F("OPEN"));
    }
    else {
        Serial.println(F("CLOSED"));
    }
}

DoorContact myContact(PIN_CONTACT, onDoorStateChange);

void setup() {
    Serial.begin(9600);
    if (!Serial) {
        delay(10);
    }

    myContact.init();
}

void loop() {
    myContact.loop();
}