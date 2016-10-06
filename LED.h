/**
 * LED.h
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides a hardware abstraction of an LED device (assumes single
 * color).
 */

#ifndef LED_h
#define LED_h

#include <Arduino.h>

/**
 * Possible LED states.
 */
enum LEDState {
  LED_On = HIGH,
  LED_Off = LOW
};

/**
 * An LED info structure. Carries information passed by event callbacks when
 * the LED changes state.
 */
struct LEDInfo {
  /**
   * The pin the LED is attached to.
   */
  short pin;

  /**
   * The current state of the LED.
   */
  volatile LEDState state;
};

/**
 * A hardware abstraction of an LED device.
 */
class LED {
public:
  /**
   * Initializes a new instance of an LED with the pin it is attached to and
   * an optional callback to fire when a state change occurs.
   * @param pin The pin this LED is attached to.
   * @param onStateChange The callback to fire when the LED changes state.
   */
  LED(short pin, void (*onStateChange)(LEDInfo* sender));

  /**
   * Initializes the LED.
   */
  void init();

  /**
   * Gets the current state of the LED.
   * @return The current state.
   */
  LEDState getState();

  /**
   * Sets the state of the LED.
   * @param state The state to set.
   */
  void setState(LEDState state);

  /**
   * Gets whether or not this LED is on.
   * @return true if on; Otherwise, false.
   */
  bool isOn();

  /**
   * Gets whether or not this LED is off.
   * @return true if off; Otherwise, false.
   */
  bool isOff();

  /**
   * Turns this LED on.
   */
  void on();

  /**
   * Turns this LED off.
   */
  void off();

  /**
   * Blinks this LED once (on then off).
   * @param delayms The delay in milliseconds before the LED is switched back off.
   */
  void blink(unsigned long delayms);

private:
  /**
   * Gets the current state of the LED but reading the value of the pin that
   * this relay is attached to.
   */
  void getStateInternal();

  LEDInfo* _sender;
  void (*onStateChange)(LEDInfo* info);
};

#endif
