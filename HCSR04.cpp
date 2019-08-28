/**
 * HCSR04.cpp
 * Version 1.0
 * Author:
 *  Cyrus Brunner <cyrusbuilt at gmail dot com>
 * 
 * This library provides a hardware abstraction of an HCSR04 Ultrasonic
 * Ranging Sensor.
 */

#include "HCSR04.h"

HCSR04::HCSR04(short triggerPin, short echoPin) {
    this->_triggerPin = triggerPin;
    this->_echoPin = echoPin;
    this->onAlarmState = NULL;
    this->_sender = NULL;
}

HCSR04::HCSR04(short triggerPin, short echoPin, void (*onAlarmState)(HCSR04Info* sender)) {
    this->_triggerPin = triggerPin;
    this->_echoPin = echoPin;
    this->onAlarmState = onAlarmState;
    this->_sender = new HCSR04Info { 0, 0, false };
}

void HCSR04::begin() {
    pinMode(this->_triggerPin, OUTPUT);
    pinMode(this->_echoPin, INPUT);
}

double HCSR04::measureDistanceCm() {
    // First, we pulse the trigger pin. This sequence tells the sensor to
    // measure for distance.
    digitalWrite(this->_triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(this->_triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->_triggerPin, LOW);

    // Measure the length of the echo signal, which is equal to the time needed
    // for the ultrasonic waves to reach the target and come back. This
    // distance is measured in centimeters.
    unsigned long durationMicroSeconds = pulseIn(this->_echoPin, HIGH);
    double distanceCM = durationMicroSeconds / 2.0 * 0.0343;
    if (distanceCM == 0 || distanceCM > MAX_DISTANCE_CM) {
        return -1.0;
    }

    return distanceCM;
}

double HCSR04::measureDistanceIn() {
    double distanceCM = this->measureDistanceCm();
    if (distanceCM == -1.0) {
        return distanceCM;
    }

    // Convert the value in centimeters to inches.
    return distanceCM * CM_TO_IN_MULTIPLIER;
}

void HCSR04::setAlarmDistance(double alarmDistanceCM) {
    if (this->_sender != NULL) {
        this->_sender->alarmDistance = alarmDistanceCM;
    }
}

void HCSR04::loop() {
    double currentReading = this->measureDistanceCm();
    if (this->_sender != NULL && currentReading != this->_sender->currentDistance) {
        this->_sender->currentDistance = currentReading;
        this->_sender->isAlarm = (this->_sender->currentDistance >= this->_sender->alarmDistance);
        if (this->onAlarmState != NULL) {
            this->onAlarmState(this->_sender);
        }
    }
}