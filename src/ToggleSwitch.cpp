/**
 * ToggleSwitch.cpp
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides a hardware abstraction for a toggle switch.
 */

#include "ToggleSwitch.h"

ToggleSwitch::ToggleSwitch(short pin, void (*onStateChange)(SwitchInfo* sender), const char* name) {
  this->onStateChange = onStateChange;
  this->_lastState = SWITCH_STATE_OFF;
  this->_sender = new SwitchInfo { pin, SWITCH_STATE_OFF, name };
}

void ToggleSwitch::init() {
  if (this->_sender->pin > 0) {
    pinMode(this->_sender->pin, INPUT);
  }
}

void ToggleSwitch::getStateInternal() {
  int state = digitalRead(this->_sender->pin);
  if (state == HIGH) {
    this->_sender->state = SWITCH_STATE_ON;
  }
  else {
    this->_sender->state = SWITCH_STATE_OFF;
  }
}

SwitchState ToggleSwitch::getState() {
  return this->_sender->state;
}

bool ToggleSwitch::isOn() {
  return (this->getState() == SWITCH_STATE_ON);
}

bool ToggleSwitch::isOff() {
  return (this->getState() == SWITCH_STATE_OFF);
}

void ToggleSwitch::loop() {
  this->getStateInternal();
  SwitchState newState = this->getState();
  if (this->_lastState != newState) {
    this->_lastState = newState;
    if (this->onStateChange != NULL) {
      this->onStateChange(this->_sender);
    }
  }
}
