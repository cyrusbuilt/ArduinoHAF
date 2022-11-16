/**
 * TemperatureSensor.h
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides a hardware abstraction for a Temperature sensor.
 */

#ifndef TemperatureSensor_h
#define TemperatureSensor_h

#include <Arduino.h>
#include "DS1620Sensor.h"
#include "TemperatureConversion.h"

/**
 * Temperature sensor event info structure. Carries information passed by event
 * callbacks when the temperature changes.
 */
struct TemperatureEventInfo {
    /**
     * The last temperature reading.
     */
    double oldTemp;

    /**
     * The current temperature reading.
     */
    double newTemp;

    /**
     * The temperature scale used for the reading.
     */
    TemperatureScale scale;
};

/**
 * A hardware abstraction of temperature sensor.
 */
class TemperatureSensor {
public:
    /**
     * Initializes a new instance of the TemperatureSensor class with the
     * control pins and an optional event handler callback.
     * @param clockPin     The clock pin to use for the sensor.
     * @param dataPin      The data pin to use for the sensor.
     * @param resetPin     The reset pin to use for the sensor.
     * @param onTempChange The callback method to call when the temperature
     * changes.
     */
    TemperatureSensor(short clockPin, short dataPin, short resetPin, void (*onTempChange)(TemperatureEventInfo* eventInfo));

    /**
     * Class destructor/finalizer.
     */
    ~TemperatureSensor();

    /**
     * Gets a pointer to the underlying sensor instance.
     * @return The underlying temperature sensor.
     */
    DS1620Sensor* getSensor();

    /**
     * Gets the raw temperature reading from the sensor.
     * @return The raw temperature value (always in degrees Celcius).
     */
    double getRawTemperature();

    /**
     * Gets the temperature value in the specific scale.
     * @param  scale The temperature scale to get the temperature value in.
     * @return       The temperature value in the specified scale.
     */
    double getTemperature(TemperatureScale scale);

    /**
     * Gets the default temperature scale being used.
     * @return The default temperature scale.
     */
    TemperatureScale getScale();

    /**
     * Sets the default temperature scale.
     * @param scale The temperature scale to use as default.
     */
    void setScale(TemperatureScale scale);

    /**
     * Reads the temperature from the sensor and fires the callback for the
     * temperature change event if defined. Should be called from your sketch's
     * loop() function.
     */
    void loop();

private:
    double _lastTemp;
    TemperatureScale _scale;
    DS1620Sensor* _tempSensor;
    TemperatureEventInfo* _sender;
    void (*onTempChange)(TemperatureEventInfo* eventInfo);
};

#endif
