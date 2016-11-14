/**
 * Buzzer.cpp
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides a hardware abstraction for a Piezo buzzer.
 */

#include "Buzzer.h"

Buzzer::Buzzer(short pin, void (*onStateChange)(BuzzerInfo* sender), const char* name) {
  this->onStateChange = onStateChange;
  this->_sender = new BuzzerInfo { pin, BUZZER_STATE_STOPPED, name, 0 };
}

void Buzzer::init() {
  if (this->_sender->pin > 0) {
    pinMode(this->_sender->pin, OUTPUT);
    digitalWrite(this->_sender->pin, LOW);
  }
}

BuzzerState Buzzer::getState() {
  return this->_sender->state;
}

short Buzzer::getPin() {
  return this->_sender->pin;
}

const char* Buzzer::getName() {
  return this->_sender->name;
}

void Buzzer::buzz(int freq, unsigned long duration) {
  if (this->_sender->state != BUZZER_STATE_BUZZING) {
    this->_sender->state = BUZZER_STATE_BUZZING;
    this->_sender->frequency = freq;
    if (this->onStateChange != NULL) {
      this->onStateChange(this->_sender);
    }

    tone(this->_sender->pin, this->_sender->frequency, duration);
    delay(duration);

    this->_sender->state = BUZZER_STATE_STOPPED;
    this->_sender->frequency = 0;
    if (this->onStateChange != NULL) {
      this->onStateChange(this->_sender);
    }
  }
}

void Buzzer::playNote(BuzzerNotes note, unsigned long duration) {
  this->buzz((int)note, duration);
}
