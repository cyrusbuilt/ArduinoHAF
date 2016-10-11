#include "Arduino.h"
#include "DimmableLight.h"

#define PIN_LIGHT A3

void onLightStateChange(DimmableLightInfo* sender) {
  Serial.println(F("Light changed state!"));
  Serial.print(F("Light level: "));
  Serial.println(sender->level);
  Serial.print(F("Max level: "));
  Serial.println(sender->minLevel);
  Serial.print(F("Min level: "));
  Serial.println(sender->maxLevel);
  Serial.print(F("Light on pin: "));
  Serial.println(sender->pin);
  Serial.print(F("Light is on: "));
  Serial.println(sender->isOn ? "true" : "false");
}

DimmableLight myLight(PIN_LIGHT, 0, 255, onLightStateChange);


void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(10);
  }

  myLight.init();
}

void loop() {
  myLight.turnOn();
  delay(1000);
  myLight.turnOff();
  delay(1000);
  myLight.setLevel(100);
  delay(1000);
}
