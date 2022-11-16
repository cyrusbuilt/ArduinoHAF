/**
 * WaterLevelSensor.h
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 * 
 * This library provides a hardware abstraction for an eTape capacitive fluid
 * level sensor. This library assumes you are using the sensor with a voltage
 * divider circuit (as opposed to an inverting op-amp circuit).
 */

#ifndef WATER_LEVEL_SENSOR_H
#define WATER_LEVEL_SENSOR_H

#include <Arduino.h>

// The sensor is typically used with a 560 Ohm resistor for the voltage divider
// but you can change the resistor value here if necessary.
#define SENSOR_RESISTOR 560

/**
 * Hardware abstraction of an eTape fluid level sensor.
 */
class WaterLevelSensor {
public:
    /**
     * Default constructor taking an analog pin number.
     * @param analogPin The analog pin to read from.
     */
    WaterLevelSensor(short analogPin);

    /**
     * Initializes the sensor. This must be called first before readings can
     * be taken unless the specified analog pin was externally initialized as
     * an input.
     */
    void begin();

    /**
     * Set the minimum reading value. This is typically done by calling read()
     * while there is no fluid on the tape, then set that reading value here.
     * @param min The minimum fluid level reading value. Default is 0.0.
     */
    void setMinValue(float min);

    /**
     * Set the maximum reading value. This typically done by calling read()
     * while the maximum amount of fluid is covering the tape (for your
     * application), then set that reading value here.
     * @param max The maximum fluid level reading value. Default is 0.0.
     */
    void setMaxValue(float max);

    /**
     * Set tape length in Centimeters.
     * @param length The tape length in centimeters. Default is 0.0.
     */
    void setTapeLengthCm(short length);

    /**
     * Gets the percentage of fluid in whatever container the fluid is being
     * measured in.
     * @returns The percentage of the container that is full of fluid.
     */
    int getPercentFull();

    /**
     * Gets the fluid level in centimeters.
     * @returns The fluid level in centimeters.
     */
    float getLevelCm();

    /**
     * Gets the fluid level in inches.
     * @returns The fluid level in inches.
     */
    float getLevelInches();

    /**
     * Reads the resistance value from the eTape sensor.
     * @returns The sensor's current resistance value.
     */
    float read();

private:
    short _sensorPin;
    short _tapeLength;
    float _minValue;
    float _maxValue;
};

#endif