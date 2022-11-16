/**
 * Relay.cpp
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides a hardware abstraction of a relay device (assumes SPDT)
 * type.
 */

#include "Relay.h"

Relay::Relay(short pin, void (*onStateChange)(RelayInfo* sender), const char* name) {
  this->onStateChange = onStateChange;
  this->_sender = new RelayInfo { pin, RelayOpen, name };
}

void Relay::init() {
  if (this->_sender->pin > 0) {
    pinMode(this->_sender->pin, OUTPUT);
    digitalWrite(this->_sender->pin, LOW);
  }
}

void Relay::getStateInternal() {
  int state = digitalRead(this->_sender->pin);
  if (state == HIGH) {
    this->_sender->state = RelayClosed;
  }
  else {
    this->_sender->state = RelayOpen;
  }
}

RelayState Relay::getState() {
  this->getStateInternal();
  return this->_sender->state;
}

void Relay::setState(RelayState state) {
  if (this->_sender->state != state) {
    this->_sender->state = state;
    digitalWrite(this->_sender->pin, state);
    if (this->onStateChange != NULL) {
      this->onStateChange(this->_sender);
    }
  }
}

bool Relay::isOpen() {
  return (this->getState() == RelayOpen);
}

bool Relay::isClosed() {
  return (this->getState() == RelayClosed);
}

short Relay::getPin() {
  return this->_sender->pin;
}

void Relay::open() {
  this->setState(RelayOpen);
}

void Relay::close() {
  this->setState(RelayClosed);
}
