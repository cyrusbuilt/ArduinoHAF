#include "Arduino.h"
#include "REX.h"

#define PIN_REX 4

void onRexStateChanged(RexInfo* sender) {
  Serial.println(F("REX state changed!"));
  Serial.print(F("REX name: "));
  Serial.println(sender->name);
  Serial.print(F("REX attached to pin: "));
  Serial.println(sender->pin);
  Serial.print(F("REX sensor tripped: "));
  Serial.println(sender->tripped ? "TRUE" : "FALSE");
}

REX myRexSensor(PIN_REX, onRexStateChanged, "TEST REX");

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(1);
  }

  myRexSensor.init();
}

void loop() {
  myRexSensor.loop();
}
