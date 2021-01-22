/**
 * ResetManager.h
 * Version 1.2
 * Author:
 *  Cyrus Brunner
 *
 * This library provides a methods for resetting the Arduino via software or
 * hardware.
 *
 * IMPORTANT_NOTE: Use with caution!! There are some caveats to using both
 * methods of resetting the Arduino you should consider before implementing:
 * 1) Soft Reset: Essentially just starts the sketch over at address zero,
 * effectively re-executing it. This DOES NOT reset any hardware, including I/O
 * pins. If any attached hardware has a method of resetting, it would be wise to
 * call it in your setup() method and it is also wise to fully re-intialize any
 * I/O pins you are using. Some hardware cannot be properly reset (ie. Ethernet
 * shield) and will likely require a hard reset.
 * 2) Hard Reset: This will fully reset the device and pin states. This method
 * assumes you are using a designated GPIO pin that you are connecting to the
 * RESET pin of your Arduino. Depending on your implementation, you may need to
 * disconnect this pin when flashing (uploading) your sketch to the Arduino or
 * communication will fail. Whichever method you use, understand that execution
 * will not leave the method you call and therefore will never return to the
 * call site, since the sketch will be started over from the beginning. If there
 * is any work to be done *prior* to a restart, make sure all of that work
 * occurs prior to calling one of these reset methods.
 */

#ifndef ResetManager_h
#define ResetManager_h

#include <Arduino.h>

/**
 * Provides methods for resetting an Arduino.
 */
class ResetManagerClass {
public:
  /**
   * Initializes a new instance of the Reset Manager.
   */
  ResetManagerClass();

  /**
   * Attaches the specified pin which will be used to perform a hard reset.
   * @param pin The pin which is tied to the RESET pin.
   */
  void attachHardResetPin(short pin);

  /**
   * Performs a "soft" reset of the Arduino. This will simply re-execute the
   * sketch and will NOT reset any peripherals or pin states. This WILL reset
   * the millis() function.
   */
  void softReset();

  /**
   * Performs a "hard" reset of the Arduino. This is effectively the same as
   * disconnecting the power and reconnecting it. This will reset all hardware
   * states and re-execute the sketch. This method assumes you have physically
   * attached a GPIO pin to the RESET pin on the Arduino and have already called
   * the attachHardResetPin() method to initailize that pin as a reset trigger.
   */
  void hardReset();

private:
  short _hardResetPin;
};

// Global instance
extern ResetManagerClass ResetManager;
#endif
