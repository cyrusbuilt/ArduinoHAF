/**
 * PIR.h
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides a hardware abstraction of a PIR (Pyroelectric InfraRed)
 * sensor. These sensors are typically used for motion detection. This is very
 * similar to a REX (Request-to-EXit) sensor which actually uses a PIR. The
 * difference is a REX includes a PIR, status LED, a relay and its own onboard
 * microcontroller. When the PIR trips, the onboard MCU will change the state of
 * one or more LEDs and then trigger a relay if the threshold is met. The REX
 * library is looking for that relay to short and react to it. This library, on
 * the other hand, is looking for a high/low state from an actual PIR sensor,
 * thus allowing you to build your own REX or other PIR application.
 */

#ifndef PIR_h
#define PIR_h

#include <Arduino.h>

/**
 * PIR info structure. Carries information passed when an event callback fires.
 */
struct PirInfo {
    /**
     * The pin the PIR is attached to.
     */
    short pin;

    /**
     * The current state of the PIR.
     */
    short state;

    /**
     * The name of the PIR.
     */
    char* name;
};

/**
 * Hardware abstraction of a PIR (Pyroelectric InfraRed) sensor.
 */
class PIR {
public:
    /**
     * Initializes a new instance of the PiR with the pin it is attached to,
     * a callback to fire when the state changes, and the name of the PIR.
     * @param pin The pin this PIR is attached to.
     * @param onStateChange A callback to fire when the PIR's state changes. Can
     * be NULL.
     * @param name The name of the PIR. Can be NULL.
     */
    PIR(short pin, void (*onStateChange)(PirInfo* sender), char* name);

    /**
     * Gets whether or not the PIR is initialized.
     * @return true if a valid pin was a provided and PIR initialized properly;
     * Otherwise, false.
     */
    bool isInitialized();

    /**
     * Initializes the PIR sensor.
     */
    void init();

    /**
     * Polls the PIR and checks state. Should be called from your sketch's
     * loop() method.
     */
    void loop();

    /**
     * Gets the current (or last known) state of the PIR.
     * @return HIGH if the PIR detected motion, or LOW if motion no longer
     * detected.
     */
    short getState();

private:
    bool _initialized;
    short _value;
    PirInfo* _sender;
    void (*onStateChange)(PirInfo* sender);
};

#endif
