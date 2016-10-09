/**
 * ToggleSwitch.h
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides a hardware abstraction for a toggle switch.
 */

#ifndef ToggleSwitch_h
#define ToggleSwitch_h

#include <Arduino.h>

/**
 * Possible switch states.
 */
enum SwitchState {
  SWITCH_STATE_ON = HIGH,
  SWITCH_STATE_OFF = LOW
};

/**
 * Toggle switch info structure. Carries information passed when an event
 * callback fires.
 */
struct SwitchInfo {
  /**
   * The pin the switch is attached to.
   */
  short pin;

  /**
   * The current state of the switch.
   */
  volatile SwitchState state;

  /**
   * The name of the switch.
   */
  const char* name;
};

/**
 * Hardware abstraction of a toggle switch.
 */
class ToggleSwitch
{
public:
  /**
   * Initializes a new instance of the toggle switch with the pin the switch is
   * attached to, a callback to call when the switch state changes, and the name
   * of the switch.
   * @param pin The pin the switch is attached to.
   * @param onStateChange A callback to fire when the switch state changes.
   * @param name The name of the switch.
   */
  ToggleSwitch(short pin, void (*onStateChange)(SwitchInfo* sender), const char* name);

  /**
   * Initializes the switch.
   */
  void init();

  /**
   * Gets the current state of the switch.
   * @return The current switch state.
   */
  SwitchState getState();

  /**
   * Checks to see if the switch is in the "On" state.
   * @return true if on; Otherwise, false.
   */
  bool isOn();

  /**
   * Checks to see if the switch is in the "Off" state.
   * @return true if off; Otherwise, false.
   */
  bool isOff();

  /**
   * Polls the switch and checks state. Should be called from your sketch's
   * loop() method.
   */
  void loop();

private:
  /**
   * Gets the state of the pin the switch is attached to.
   */
  void getStateInternal();

  SwitchInfo* _sender;
  SwitchState _lastState;
  void (*onStateChange)(SwitchInfo* sender);
};
#endif
