/**
 * ResetManager.cpp
 * Version 1.0
 * Author:
 *  Cyrus Brunner
 *
 * This library provides a methods for resetting the Arduino via software or
 * hardware.
 *
 * IMPORTANT_NOTE: Use with caution!! There are some caveats to using both
 * methods of resetting the Arduino you should consider before implementing:
 * 1) Soft Reset: Essentially just starts the sketch over at address zero,
 * effectively re-executing it. This DOES NOT reset any hardware, including I/O
 * pins. If any attached hardware has a method of resetting, it would be wise to
 * call it in your setup() method and it is also wise to fully re-intialize any
 * I/O pins you are using. Some hardware cannot be properly reset (ie. Ethernet
 * shield) and will likely require a hard reset.
 * 2) Hard Reset: This will fully reset the device and pin states. This method
 * assumes you are using a designated GPIO pin that you are connecting to the
 * RESET pin of your Arduino. Depending on your implementation, you may need to
 * disconnect this pin when flashing (uploading) your sketch to the Arduino or
 * communication will fail. Whichever method you use, understand that execution
 * will not leave the method you call and therefore will never return to the
 * call site, since the sketch will be started over from the beginning. If there
 * is any work to be done *prior* to a restart, make sure all of that work
 * occurs prior to calling one of these reset methods.
 */

#include "ResetManager.h"

ResetManagerClass::ResetManagerClass() {
}

void ResetManagerClass::attachHardResetPin(short pin) {
  if (pin > 0) {
    this->_hardResetPin = pin;
    digitalWrite(this->_hardResetPin, HIGH);
    pinMode(this->_hardResetPin, OUTPUT);
  }
}

void ResetManagerClass::softReset() {
  asm volatile (" jmp 0");
}

void ResetManagerClass::hardReset() {
  if (this->_hardResetPin > 0) {
    digitalWrite(this->_hardResetPin, LOW);
  }
}

ResetManagerClass ResetManager;
