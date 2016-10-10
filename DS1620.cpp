/**
 * DS1620.cpp
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides a hardware abstraction of a Dallas Semiconductor DS1620
 * temperature sensor.
 */

#include "DS1620.h"

DS1620Sensor::DS1620Sensor(short clockPin, short dataPin, short resetPin) {
  this->_clockPin = clockPin;
  this->_dataPin = dataPin;
  this->_resetPin = resetPin;
}

short DS1620Sensor::getClockPin() {
  return this->_clockPin;
}

short DS1620Sensor::getDataPin() {
  return this->_dataPin;
}

short DS1620Sensor::getResetPin() {
  return this->_resetPin;
}

void DS1620Sensor::init() {
  pinMode(this->_clockPin, OUTPUT);
  digitalWrite(this->_clockPin, LOW);
  pinMode(this->_dataPin, OUTPUT);
  digitalWrite(this->_dataPin, LOW);
  pinMode(this->_resetPin, OUTPUT);
  digitalWrite(this->_resetPin, LOW);
}

void DS1620Sensor::sendCommand(byte command) {
  int bit = 0;
  for (uint8_t n = 0; n < 8; n++) {
    bit = ((command >> n) & 0x01);
    digitalWrite(this->_dataPin, (bit == 1) ? HIGH : LOW);
    digitalWrite(this->_clockPin, LOW);
    digitalWrite(this->_clockPin, HIGH);
  }
}

int DS1620Sensor::readData() {
  int bit = 0;
  int rawData = 0;
  for (uint8_t n = 0; n < 9; n++) {
    digitalWrite(this->_clockPin, LOW);
    pinMode(this->_dataPin, INPUT);
    bit = (int)digitalRead(this->_dataPin);
    digitalWrite(this->_clockPin, HIGH);
    rawData = rawData | (bit << n);
  }

  pinMode(this->_dataPin, OUTPUT);
  return rawData;
}

double DS1620Sensor::getTemperature() {
  digitalWrite(this->_resetPin, LOW);
  digitalWrite(this->_clockPin, HIGH);
  digitalWrite(this->_resetPin, HIGH);
  this->sendCommand(0x0c);   // Write config command.
  this->sendCommand(0x02);   // CPU mode.
  digitalWrite(this->_resetPin, LOW);

  delay(200);   // Wait until configuration register is written.
  digitalWrite(this->_clockPin, HIGH);
  digitalWrite(this->_resetPin, HIGH);
  this->sendCommand(0xEE);   // Start conversion.
  digitalWrite(this->_resetPin, LOW);

  delay(200);
  digitalWrite(this->_clockPin, HIGH);
  digitalWrite(this->_resetPin, HIGH);
  this->sendCommand(0xAA);
  int raw = this->readData();
  digitalWrite(this->_resetPin);
  return ((double)raw / 2.0);
}
