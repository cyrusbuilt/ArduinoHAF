/**
 * DimmableLight.cpp
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides a hardware abstraction of a dimmable light.
 */

#include "DimmableLight.h"

DimmableLight::DimmableLight(short pin, int minLevel, int maxLevel, void (*onStateChange)(DimmableLightInfo* sender)) {
  this->onStateChange = onStateChange;
  if (minLevel < 0) {
    minLevel = 0;
  }

  if (minLevel > 255) {
    minLevel = 255;
  }

  if (maxLevel < 0) {
    maxLevel = 0;
  }

  if (maxLevel > 255) {
    maxLevel = 255;
  }

  this->_sender = new DimmableLightInfo { pin, 0, minLevel, maxLevel, false };
}

void DimmableLight::init() {
  if (this->_sender->pin > 0) {
    pinMode(this->_sender->pin, OUTPUT);
    analogWrite(this->_sender->pin, 0);
  }
}

int DimmableLight::getMinLevel() {
  return this->_sender->minLevel;
}

int DimmableLight::getMaxLevel() {
  return this->_sender->maxLevel;
}

int DimmableLight::getLevel() {
  return analogRead(this->_sender->pin);
}

bool DimmableLight::isOn() {
  return (this->getLevel() > this->_sender->minLevel);
}

bool DimmableLight::isOff() {
  return (this->getLevel() <= this->_sender->minLevel);
}

void DimmableLight::setLevel(int level) {
  if (level < this->_sender->minLevel) {
    level = this->_sender->minLevel;
  }

  if (level > this->_sender->maxLevel) {
    level = this->_sender->maxLevel;
  }

  if (this->_sender->level != level) {
    analogWrite(this->_sender->pin, level);
    this->_sender->isOn = this->isOn();
    if (this->onStateChange != NULL) {
      this->onStateChange(this->_sender);
    }
  }
}

void DimmableLight::turnOn() {
  this->setLevel(this->_sender->maxLevel);
}

void DimmableLight::turnOff() {
  this->setLevel(this->_sender->minLevel);
}

float DimmableLight::getLevelPercentage(int level) {
  int minVal = min(this->_sender->minLevel, this->_sender->maxLevel);
  int maxVal = max(this->_sender->minLevel, this->_sender->maxLevel);
  int range = (max - min);
  float percentage = ((level * 100) / range);
  return percentage;
}

float DimmableLight::getLevelPercentage() {
  return this->getLevelPercentage(this->getLevel());
}
