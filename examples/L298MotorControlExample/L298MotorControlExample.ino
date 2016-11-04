#include "Arduino.h"
#include "L298MotorControl.h"

#define PIN_PWM 3
#define PIN_LOGIC1 8
#define PIN_LOGIC2 9

void onStateChange(L298MotorInfo* sender) {
  Serial.println(F("Motor state changed!"));
  Serial.print(F("Logic pin 1: "));
  Serial.println(sender->controlPin1);
  Serial.print(F("Logic pin 2: "));
  Serial.println(sender->controlPin2);
  Serial.print(F("PWM pin: "));
  Serial.println(sender->pwmPin);
  Serial.print(F("Speed: "));
  Serial.println(analogRead(sender->pwmPin));
  Serial.print(F("Motor state: "));
  switch (sender->state) {
    case L298MS_Stopped:
      Serial.println(F("Stopped"));
      break;
    case L298MS_Forward:
      Serial.println(F("Forward"));
      break;
    case L298MS_Reverse:
      Serial.println(F("Reverse"));
      break;
    default:
      Serial.println(F("Unknown"));
      break;
  }
}

L298MotorControl motor(PIN_PWM, PIN_LOGIC1, PIN_LOGIC2, onStateChange);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(10);
  }
}

void loop() {
  Serial.println(F("Moving motor forward at speed 80 for 4 seconds..."));
  motor.forward(80, 4000);

  Serial.println(F("Moving motor in reverse at half speed for 3 seconds..."));
  motor.reverse(3000UL);

  Serial.println(F("Moving motor forward at maximum speed for 5 seconds..."));
  motor.forward(L298_MOTOR_CONTROL_MAX_SPEED, 5000);

  Serial.println(F("Moving in reverse...."));
  motor.reverse();

  delay(5000);
  Serial.println(F("Stopping..."));
  motor.brake();

  delay(2000);
}
