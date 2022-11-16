/**
 * Relay.h
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides a hardware abstraction of a relay device (assumes SPDT)
 * type.
 */

#ifndef Relay_h
#define Relay_h

#include <Arduino.h>

/**
 * Possible relay states.
 */
enum RelayState {
  RelayOpen = LOW,
  RelayClosed = HIGH
};

/**
 * Relay info structure. Carries information passed when an event callback fires.
 */
struct RelayInfo {
  /**
   * The pin the relay is attached to.
   */
  short pin;

  /**
   * The current state of the relay.
   */
  volatile RelayState state;

  /**
   * The name of the relay.
   */
  const char* name;
};

/**
 * Hardware abstraction of a relay switch.
 */
class Relay {
public:
  /**
   * Initializes a new instance of the relay with the pin it is attached to,
   * a callback to fire when the state changes, and the name of the relay.
   * @param pin The pin this relay is attached to.
   * @param onStateChange A callback to fire when the relay's state changes.
   * @param name The name of the relay.
   */
  Relay(short pin, void (*onStateChange)(RelayInfo* sender), const char* name);

  /**
   * Initializes the relay.
   */
  void init();

  /**
   * Gets the current state of the relay.
   * @return The current state.
   */
  RelayState getState();

  /**
   * Sets the state of the relay.
   * @param state The state to set.
   */
  void setState(RelayState state);

  /**
   * Checks to see if the relay is in an open state.
   * @return true if open; Otherwise, false.
   */
  bool isOpen();

  /**
   * Checks to see if the relay is in a closed state.
   * @return true if closed; Otherwise, false.
   */
  bool isClosed();

  /**
   * Gets the pin this relay is attached to.
   * @return The pin this relay is attached to.
   */
  short getPin();

  /**
   * Closes (turns on) this relay.
   */
  void close();

  /**
   * Opens (turns off) this relay.
   */
  void open();

private:
  /**
   * Gets the current state of the relay but reading the value of the pin that
   * this relay is attached to.
   */
  void getStateInternal();

  RelayInfo* _sender;
  void (*onStateChange)(RelayInfo* info);
};
#endif
