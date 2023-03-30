/**
 * LED.cpp
 * Version 1.1
 * Author:
 *  Cyrus Brunner
 *
 * This library provides a hardware abstraction of an LED device (assumes single
 * color).
 */

#include "LED.h"

HAF_LED::HAF_LED(short pin, void (*onStateChange)(LEDInfo* info)) {
  this->_sender = new LEDInfo { pin, LED_Off };
  this->onStateChange = onStateChange;
}

void HAF_LED::init() {
  if (this->_sender->pin > 0) {
    pinMode(this->_sender->pin, OUTPUT);
    digitalWrite(this->_sender->pin, LOW);
  }
}

void HAF_LED::getStateInternal() {
  int state = digitalRead(this->_sender->pin);
  if (state == HIGH) {
    this->_sender->state = LED_On;
  }
  else {
    this->_sender->state = LED_Off;
  }
}

LEDState HAF_LED::getState() {
  this->getStateInternal();
  return this->_sender->state;
}

void HAF_LED::setState(LEDState state) {
  if (this->_sender->state != state) {
    this->_sender->state = state;
    digitalWrite(this->_sender->pin, state);
    if (this->onStateChange != NULL) {
      this->onStateChange(this->_sender);
    }
  }
}

bool HAF_LED::isOn() {
  return (this->getState() == LED_On);
}

bool HAF_LED::isOff() {
  return (this->getState() == LED_Off);
}

void HAF_LED::on() {
  this->setState(LED_On);
}

void HAF_LED::off() {
  this->setState(LED_Off);
}

void HAF_LED::blink(unsigned long delayms) {
  this->on();
  delay(delayms);
  this->off();
}
