/**
 * DoorContact.cpp
 * Version 1.1
 * Author:
 *  Cyrus Brunner
 * 
 * This library is an abstraction for a door contact.
 */

#include "DoorContact.h"

DoorContact::DoorContact(short pin, void (*onStateChange)(DoorInfo* sender)) {
    this->onStateChange = onStateChange;
    this->_lastState = DOOR_STATE_CLOSE;
    this->_sender = new DoorInfo { pin, DOOR_STATE_CLOSE };
}

void DoorContact::init(bool usePullup) {
    if (this->_sender->pin > 0) {
        if (usePullup) {
            digitalWrite(this->_sender->pin, HIGH);
        }
        pinMode(this->_sender->pin, INPUT);
    }
}

DoorContactState DoorContact::getState() {
    if (digitalRead(this->_sender->pin) == LOW) {
        return DOOR_STATE_OPEN;
    }
    
    return DOOR_STATE_CLOSE;
}

void DoorContact::loop() {
    DoorContactState newState = this->getState();
    if (newState != this->_lastState) {
        this->_lastState = newState;
        if (this->onStateChange != NULL) {
            this->onStateChange(this->_sender);
        }
    }
}

bool DoorContact::isClosed() {
    return (this->getState() == DOOR_STATE_CLOSE);
}

bool DoorContact::isOpen() {
    return (this->getState() == DOOR_STATE_OPEN);
}