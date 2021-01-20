/**
 * ESP32_AnalogWrite.h
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides compatibility functions for Arduino's analogWrite() on ESP32.
 */

#ifndef _ESP32_ANALOG_WRITE_H
#ifdef ESP32
#define _ESP32_ANALOG_WRITE_H

#include <Arduino.h>

int analogWriteChannel(uint8_t pin);
void analogWrite(uint8_t pin, uint32_t value, uint32_t valueMax = 255);

#endif
#endif