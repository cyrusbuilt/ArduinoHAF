/**
 * L298MotorControl.cpp
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides an abstraction of a simple motor controlled via an L298
 * "H" bridge IC.
 */

#include "L298MotorControl.h"

L298MotorControl::L298MotorControl(short pwmPin, short controlPin1, short controlPin2, void (*onStateChange)(L298MotorInfo* info)) {
  this->_sender new L298MotorInfo { pwmPin, controlPin1, controlPin2, L298MS_Stopped };
  this->onStateChange = onStateChange;
  pinMode(this->_sender->pwmPin, OUTPUT);
  pinMode(this->_sender->controlPin1, OUTPUT);
  pinMode(this->_sender->controlPin2, OUTPUT);
  analogWrite(this->_sender->pwmPin, 0);
  digitalWrite(this->_sender->controlPin1, LOW);
  digitalWrite(this->_sender->controlPin2, LOW);
}

int L298MotorControl::validateSpeed(int speed) {
  if (speed < L298_MOTOR_CONTROL_MIN_SPEED) {
    speed = L298_MOTOR_CONTROL_MIN_SPEED;
  }

  if (speed > L298_MOTOR_CONTROL_MAX_SPEED) {
    speed = L298_MOTOR_CONTROL_MAX_SPEED;
  }

  return speed;
}

L298MotorState L298MotorControl::getState() {
  return this->_sender->state;
}

void L298MotorControl::setState(L298MotorState state) {
  if (this->getState() != state) {
    this->_sender->state = state;
    switch (state) {
      case L298MS_Forward:
        digitalWrite(this->_controlPin1, LOW);
        digitalWrite(this->_controlPin2, HIGH);
        break;
      case L298MS_Reverse:
        digitalWrite(this->_controlPin1, HIGH);
        digitalWrite(this->_controlPin2, LOW);
        break;
      case L298MS_Stopped:
        digitalWrite(this->_sender->controlPin1, HIGH);
        digitalWrite(this->_sender->controlPin2, HIGH);
        break;
      default:
        break;
    }

    if (this->onStateChange != NULL) {
      this->onStateChange(this->_sender);
    }
  }
}

void L298MotorControl::brake() {
  this->setState(L298MS_Stopped);
}

void L298MotorControl::forward(int speed, unsigned long duration) {
  speed = this->validateSpeed(speed);
  analogWrite(this->_pwmPin, speed);
  this->setState(L298MS_Forward);
  if (duration > 0) {
    delay(duration);
    this->brake();
  }
}

void L298MotorControl::forward(int speed) {
  this->forward(speed, 0);
}

void L298MotorControl::forward(unsigned long duration) {
  // Assume half of max speed.
  this->forward(123, duration);
}

void L298MotorControl::forward() {
  this->forward(123, 0);
}

void L298MotorControl::reverse(int speed, unsigned long duration) {
  speed = this->validateSpeed(speed);
  analogWrite(this->_sender->pwmPin, speed);
  this->setState(L298MS_Reverse);
  if (duration > 0) {
    delay(duration);
    this->brake();
  }
}

void L298MotorControl::reverse(int speed) {
  this->reverse(speed, 0);
}

void L298MotorControl::reverse(unsigned long duration) {
  this->reverse(123, duration);
}

void L298MotorControl::reverse() {
  this->reverse(123, 0);
}
