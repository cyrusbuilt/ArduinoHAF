/**
 * PIR.h
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides a hardware abstraction of a PIR (Pyroelectric InfraRed)
 * sensor. These sensors are typically used for motion detection. This is very
 * similar to a REX (Request-to-EXit) sensor which actually uses a PIR. The
 * difference is a REX includes a PIR, status LED, a relay and its own onboard
 * microcontroller. When the PIR trips, the onboard MCU will change the state of
 * one or more LEDs and then trigger a relay if the threshold is met. The REX
 * library is looking for that relay to short and react to it. This library, on
 * the other hand, is looking for a high/low state from an actual PIR sensor,
 * thus allowing you to build your own REX or other PIR application.
 */

#include "PIR.h"

PIR::PIR(short pin, void (*onStateChange)(PirInfo* sender), char* name) {
    this->_initialized = false;
    this->_sender = new PirInfo { pin, LOW, name };
    this->onStateChange = onStateChange;
}

bool PIR::isInitialized() {
    return this->_initialized;
}

void PIR::init() {
    if (this->_sender->pin > 0) {
        pinMode(this->_sender->pin, INPUT);
        this->_value = LOW;
        this->_initialized = true;
    }
}

void PIR::loop() {
    bool stateChanged = false;
    this->_value = digitalRead(this->_sender->pin);
    if (this->_value == HIGH) {
        if (this->_sender->state == LOW) {
            this->_sender->state = HIGH;
            stateChanged = true;
        }
    }
    else {
        if (this->_sender->state == HIGH) {
            this->_sender->state = LOW;
            stateChanged = true;
        }
    }

    if ((stateChanged) && (this->onStateChange != NULL)) {
        this->onStateChange(this->_sender);
    }
}

short PIR::getState() {
    return this->_sender->state;
}
