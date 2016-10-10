#include "Arduino.h"
#include "DS1620Sensor.h"

#define PIN_CLOCK 4
#define PIN_DATA  5
#define PIN_RESET 6

DS1620Sensor mySensor(PIN_CLOCK, PIN_DATA, PIN_RESET);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(10);
  }

  mySensor.init();
}

void loop() {
  double temp = mySensor.getTemperature();
  Serial.print(F("Current temperature: "));
  Serial.println(temp, DEC);
  delay(3000);
}
