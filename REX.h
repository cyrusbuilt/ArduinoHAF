/**
 * REX.h
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides a hardware abstraction for a Request to EXit sensor (REX).
 */

#ifndef REX_h
#define REX_h

#include <Arduino.h>

#define REX_TRIP_THRESHOLD_MILLIS 500

/**
 * REX info structure. Carries information passed when an event callback fires.
 */
struct RexInfo {
  /**
   * The pin the REX is attached to.
   */
  short pin;

  /**
   * Whether or not the REX is tripped.
   */
  bool tripped;

  /**
   * The name of the REX (ie. door or zone).
   */
  const char* name;
};

/**
 * Hardware abstraction of a Request to EXit sensor (REX).
 */
class REX {
public:
  /**
   * Initializes a new instance of a REX with the pin the sensor is attached to,
   * a callback method to call when the sensor's state changes, and the name of
   * the REX sensor.
   * @param pin The pin the sensor is attached to.
   * @param onStateChange A callback method to call when the state changes.
   * @param name The name of the REX sensor.
   */
  REX(short pin, void (*onStateChange)(RexInfo* sender), const char* name);

  /**
   * Initializes a new instance of a REX with the pin the sensor is attached to,
   * and a callback method to call when the sensor's state changes.
   * @param pin The pin the sensor is attached to.
   * @param onStateChange A callback method to call when the state changes.
   */
  REX(short pin, void (*onStateChange)(RexInfo* sender));

  /**
   * Initializes a new instance of a REX with the pin the sensor is attached to
   * and the name of the REX sensor.
   * @param pin The pin the sensor is attached to.
   * @param name The name of the REX sensor.
   */
  REX(short pin, const char* name);

  /**
   * Initializes a new instance of a REX with the pin the sensor is attached to.
   * @param pin The pin the sensor is attached to.
   */
  explicit REX(short pin);

  /**
   * Initializes the REX sensor.
   */
  void init();

  /**
   * Gets whether or not the REX is initialized.
   * @return true if a valid pin was a provided and REX initialized properly;
   * Otherwise, false.
   */
  bool isInitialized();

  /**
   * Gets the pin the REX sensor is attached to.
   * @return The pin number that sensor is attached to.
   */
  short getPin();

  /**
   * Gets whether or not the REX tripped.
   * @return true if the REX tripped; Otherwise, false.
   */
  bool isTripped();

  /**
   * Polls the REX and checks state. Should be called from your sketch's
   * loop() method.
   */
  void loop();

private:
  unsigned long _lastMillis;
  bool _lastState;
  bool _initialized;
  RexInfo* _sender;
  void (*onStateChange)(RexInfo* sender);
};
#endif
