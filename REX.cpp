/**
 * REX.cpp
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides a hardware abstraction for a Request to EXit sensor (REX).
 */

#include "REX.h"

REX::REX(short pin, void (*onStateChange)(RexInfo* sender), const char* name) {
  this->onStateChange = onStateChange;
  this->_sender = new RexInfo { pin, false, name };
  this->_initialized = false;
}

REX::REX(short pin, void (*onStateChange)(RexInfo* sender)) {
  this->onStateChange = onStateChange;
  this->_sender = new RexInfo { pin, false, NULL };
  this->_initialized = false;
}

REX::REX(short pin, const char* name) {
  this->onStateChange = NULL;
  this->_sender = new RexInfo { pin, false, name };
  this->_initialized = false;
}

REX::REX(short pin) {
  this->onStateChange = NULL;
  this->_sender = new RexInfo { pin, false, NULL };
  this->_initialized = false;
}

void REX::init() {
  if (this->_sender->pin > 0) {
    pinMode(this->_sender->pin, INPUT);
    this->_lastMillis = 0L;
    this->_lastState = false;
    this->_initialized = true;
  }
}

bool REX::isInitialized() {
  return this->_initialized;
}

short REX::getPin() {
  return this->_sender->pin;
}

bool REX::isTripped() {
  return this->_sender->tripped;
}

void REX::loop() {
  unsigned long current = millis();
  bool trip = (digitalRead(this->_sender->pin) == HIGH);
  bool hitThreshold = ((current - this->_lastMillis) > REX_TRIP_THRESHOLD_MILLIS);
  bool newState = (trip && hitThreshold);
  if (newState != this->_lastState) {
      this->_sender->tripped = newState;
      if (this->onStateChange != NULL) {
        this->onStateChange(this->_sender);
      }
  }

  this->_lastMillis = current;
  this->_lastState = newState;
}
