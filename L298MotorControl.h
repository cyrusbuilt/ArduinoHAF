/**
 * L298MotorControl.h
 * Version 1.1
 * Author:
 *  Cyrus Brunner
 *
 * This library provides an abstraction of a simple motor controlled via an L298
 * "H" bridge IC.
 */

#ifndef L298MotorControl_h
#define L298MotorControl_h

#include <Arduino.h>

#define L298_MOTOR_CONTROL_MIN_SPEED 0
#define L298_MOTOR_CONTROL_MAX_SPEED 255

/**
 * Possible motor states.
 */
enum L298MotorState {
  /**
   * The motor is stopped.
   */
  L298MS_Stopped = 0,

  /**
   * The motor is moving forward (rotating clockwise).
   */
  L298MS_Forward = 1,

  /**
   * The motor is moving in reverse (rotating counter-clockwise).
   */
  L298MS_Reverse = -1
};

/**
 * A motor info structure. Carries information passed by event callbacks when
 * the motor changes state.
 */
struct L298MotorInfo {
  /**
   * The PWM (speed control) pin.
   */
  short pwmPin;

  /**
   * Logic control pin 1.
   */
  short controlPin1;

  /**
   * Logic control pin 2.
   */
  short controlPin2;

  /**
   * The current motor state.
   */
  volatile L298MotorState state;
};

/**
 * A hardware abstraction of an L298-controlled motor.
 */
class L298MotorControl {
public:
  /**
   * Initializes a new instance of an L298-controlled motor with the PWM (speed
   * control) pin, logic control pin 1, logic control pin 2, and state change
   * callback to call when state changes occur.
   * @param pwmPin        The PWM (speed) control pin.
   * @param controlPin1   The logic control pin 1.
   * @param controlPin2   The logic control pin 2.
   * @param onStateChange A state change callback method.
   */
  L298MotorControl(short pwmPin, short controlPin1, short controlPin2, void (*onStateChange)(L298MotorInfo* info));

  /**
   * Move forward (motor rotates clockwise) at half speed indefinitely (or until
   * brake() is called).
   */
  void forward();

  /**
   * Move forward (motor rotates clockwise) at the specified feed indefinitely
   * (or until brake() is called).
   * @param speed The speed at which the motor should rotate. Must be between
   * L298_MOTOR_CONTROL_MIN_SPEED and L298_MOTOR_CONTROL_MAX_SPEED.
   */
  void forward(int speed);

  /**
   * Move forward (motor rotates clockwise) at half speed for the specified
   * duration in milliseconds.
   * @param duration The amount of time in milliseconds the motor should go
   * forward until stopped. If set to zero, the motor will spin indefinitely (or
   * until brake() is called).
   */
  void forward(unsigned long duration);

  /**
   * Moves forward (motor rotates clockwise) at the specified speed for the
   * specified duration in milliseconds.
   * @param speed    The speed at which the motor should rotate. Must be between
   * L298_MOTOR_CONTROL_MIN_SPEED and L298_MOTOR_CONTROL_MAX_SPEED.
   * @param duration The amount of time in milliseconds the motor should go
   * forward until stopped. If set to zero, the motor will spin indefinitely (or
   * until brake() is called).
   */
  void forward(int speed, unsigned long duration);

  /**
   * Move in reverse (motor spins counter-clockwise) at half speed indefinitely
   * (or until brake() is called).
   */
  void reverse();

  /**
   * Move in reverse (motor spins counter-clockwise) at the specified speed
   * indefinitely (or until brake() is called).
   * @param speed The speed at which the motor should rotate. Must be between
   * L298_MOTOR_CONTROL_MIN_SPEED and L298_MOTOR_CONTROL_MAX_SPEED.
   */
  void reverse(int speed);

  /**
   * Move in reverse (motor spins counter-clockwise) at half speed for the
   * specified duration in milliseconds.
   * @param duration The speed at which the motor should rotate. Must be between
   * L298_MOTOR_CONTROL_MIN_SPEED and L298_MOTOR_CONTROL_MAX_SPEED.
   * @param duration The amount of time in milliseconds the motor should go
   * forward until stopped. If set to zero, the motor will spin indefinitely (or
   * until brake() is called).
   */
  void reverse(unsigned long duration);

  /**
   * Moves in reverse (motor rotates counter-clockwise) at the specified speed
   * for the specified duration in milliseconds.
   * @param speed    The speed at which the motor should rotate. Must be between
   * L298_MOTOR_CONTROL_MIN_SPEED and L298_MOTOR_CONTROL_MAX_SPEED.
   * @param duration The amount of time in milliseconds the motor should go
   * forward until stopped. If set to zero, the motor will spin indefinitely (or
   * until brake() is called).
   */
  void reverse(int speed, unsigned long duration);

  /**
   * Stops the motor.
   */
  void brake();

  /**
   * Gets the current state of the motor.
   * @return The motor state.
   */
  L298MotorState getState();

private:
  /**
   * Validates the specified speed value.
   * @param  speed The speed to validate.
   * @return       The validated speed.
   */
  int validateSpeed(int speed);

  /**
   * Sets the motor state and calls the user-provide state change callback if
   * present.
   * @param state The state to set.
   */
  void setState(L298MotorState state);

  L298MotorInfo* _sender;
  void (*onStateChange)(L298MotorInfo* info);
};
#endif
