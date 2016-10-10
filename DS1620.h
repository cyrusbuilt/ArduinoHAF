/**
 * DS1620.h
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides a hardware abstraction of a Dallas Semiconductor DS1620
 * temperature sensor.
 */

#ifndef DS1620_h
#define DS1620_h

#include <Arduino.h>

/**
 * A hardware abstraction of a Dallas Semiconductor DS1620 temperature sensor.
 */
class DS1620Sensor
{
public:
  /**
   * Initializes a new instance of the DS1620 sensor with the clock pin, data
   * pin, and reset pin.
   * @param clockPin The pin the clock input is attached to.
   * @param dataPin The pin the data I/O is attached to.
   * @param resetPin The pin the reset input is attached to.
   */
  DS1620Sensor(short clockPin, short dataPin, short resetPin);

  /**
   * Initializes the sensor.
   */
  void init();

  /**
   * Gets the pin the clock input is attached to.
   * @return The clock pin.
   */
  short getClockPin();

  /**
   * Gets the pin the data input is attached to.
   * @return The data pin.
   */
  short getDataPin();

  /**
   * Gets the pin the reset input is attached to.
   * @return The reset pin.
   */
  short getResetPin();

  /**
   * Reads the current temperature from the sensor.
   * @return The temperature reading with half-degree granularity.
   */
  double getTemperature();
private:
  /**
   * Sends commands to the sensor registers.
   * @param command The command to send.
   */
  void sendCommand(byte command);

  /**
   * Reads data from the data pin.
   * @return The value read from the pin.
   */
  int readData();

  short _clockPin;
  short _dataPin;
  short _resetPin;
};
#endif
