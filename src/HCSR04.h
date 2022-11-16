/**
 * HCSR04.h
 * Version 1.0
 * Auhtor:
 *  Cyrus Brunner
 * 
 * This library provides a hardware abstraction of an HCSR04 Ultrasonic
 * Ranging Sensor.
 */

#ifndef HCSR04_h
#define HCSR04_h

#include <Arduino.h>

#define CM_TO_IN_MULTIPLIER 2.54  /** Multiplier for converting centimeters to inches. */
#define MAX_DISTANCE_CM 400       /** The maximum supported distance for reliable ranging (cm). */

/**
 * Event info structure.
 */
struct HCSR04Info {
    /**
     * The alarm distance set.
     */
    double alarmDistance;

    /**
     * The current distance reading (cm).
     */
    double currentDistance;

    /**
     * True if the alarm distance is reached.
     */
    bool isAlarm;
};

/**
 * A hardware abstraction of an HCSR04 Ultrasonic Ranging Sensor.
 */
class HCSR04 {
public:
    /**
     * Instantiates an instance of HCSR04 with the trigger and echo pins.
     * @param triggerPin The trigger pin.
     * @param echoPin The echo pin.
     */
    HCSR04(short triggerPin, short echoPin);

    /**
     * Instantiates an instance of HCSR04 with the trigger and echo pins and a
     * callback to fire when ranging events occur.
     * @param triggerPin The trigger pin.
     * @param echoPin The echo pin.
     * @param onAlarmState Callback method to fire when a ranging event occurs.
     */
    HCSR04(short triggerPin, short echoPin, void (*onAlarmState)(HCSR04Info* sender));

    /**
     * Initializes the sensor pins.
     */
    void begin();

    /**
     * Measures the distance to target in centimeters.
     * @return The distance in centimeters.
     */
    double measureDistanceCm();

    /**
     * Measures the distance to target in inches.
     * @return The distance in inches.
     */
    double measureDistanceIn();

    /**
     * Sets the alarm distance. This is the distance that when reached, will
     * set the isAlarm flag in HCSR04Info to true.
     * @param alarmDistanceCM The alarm distance in centimeters.
     */
    void setAlarmDistance(double alarmDistanceCM);

    /**
     * Measures the distance and if changed from the last reading will call
     * the onAlarmState callback if set.
     */
    void loop();
private:
    short _triggerPin;
    short _echoPin;
    HCSR04Info* _sender;
    void (*onAlarmState)(HCSR04Info* sender);
};

#endif