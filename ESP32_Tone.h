/**
 * ESP32_Tone.h
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides compatibility functions for Arduino's tone() and noTone() functions.
 */

#ifndef _ESP32_TONE_H
#ifdef ESP32
#define _ESP32_TONE_H

#include <Arduino.h>

void tone(byte pin, int freq, unsigned long duration = 0);
void noTone(byte pin);

#endif
#endif