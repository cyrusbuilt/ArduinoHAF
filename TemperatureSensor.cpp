/**
 * TemperatureSensor.h
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides a hardware abstraction for a Temperature sensor.
 */

#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor(short dataPin, short clockPin, short resetPin, void (*onTempChange)(TemperatureEventInfo* eventInfo)) {
    this->_lastTemp = 0;
    this->_scale = TEMP_SCALE_CELCIUS;
    this->_tempSensor = new DS1620Sensor(dataPin, clockPin, resetPin);
    this->onTempChange = onTempChange;
    this->_sender = new TemperatureEventInfo { 0, 0, TEMP_SCALE_CELCIUS };
}

TemperatureSensor::~TemperatureSensor() {
    this->_lastTemp = 0;
    this->_scale = TEMP_SCALE_CELCIUS;
    this->onTempChange = NULL;
    delete this->_tempSensor;
    delete this->_sender;
}

DS1620Sensor* TemperatureSensor::getSensor() {
    return this->_tempSensor;
}

TemperatureScale TemperatureSensor::getScale() {
    return this->_scale;
}

void TemperatureSensor::setScale(TemperatureScale scale) {
    this->_scale = scale;
}

double TemperatureSensor::getRawTemperature() {
    return this->_tempSensor->getTemperature();
}

double TemperatureSensor::getTemperature(TemperatureScale scale) {
    double raw = this->getRawTemperature();
    if (scale != TEMP_SCALE_CELCIUS) {
        return TemperatureConversion::convert(TEMP_SCALE_CELCIUS, scale, raw);
    }
    return raw;
}

void TemperatureSensor::loop() {
    double newTemp = this->getRawTemperature();
    if (newTemp != this->_lastTemp) {
        double oldTemp = this->_lastTemp;
        this->_lastTemp = newTemp;
        this->_sender->oldTemp = oldTemp;
        this->_sender->newTemp = newTemp;
        this->_sender->scale = this->_scale;
        if (this->onTempChange != NULL) {
            this->onTempChange(this->_sender);
        }
    }
}
