#include "WaterLevelSensor.h"

WaterLevelSensor::WaterLevelSensor(short analogPin) {
    this->_sensorPin = analogPin;
    this->_minValue = 0.0;
    this->_maxValue = 0.0;
    this->_tapeLength = 0.0;
}

void WaterLevelSensor::begin() {
    pinMode(this->_sensorPin, INPUT);
}

void WaterLevelSensor::setMinValue(float min) {
    this->_minValue = min;
}

void WaterLevelSensor::setMaxValue(float max) {
    this->_maxValue = max;
}

void WaterLevelSensor::setTapeLengthCm(short length) {
    this->_tapeLength = length;
}

float WaterLevelSensor::read() {
    float reading = analogRead(this->_sensorPin);
    reading = (1023 / reading) - 1;
    float resistance = SENSOR_RESISTOR / reading;
    return resistance;
}

int WaterLevelSensor::getPercentFull() {
    float reading = this->read();
    float adjusted = this->_maxValue - reading;
    float range = this->_maxValue - this->_minValue;
    return (int)adjusted / range;
}

float WaterLevelSensor::getLevelCm() {
    float percent = this->getPercentFull();
    return percent * this->_tapeLength;
}

float WaterLevelSensor::getLevelInches() {
    float measurement = this->getLevelCm();
    return measurement > 0 ? measurement / 2.54 : 0;
}