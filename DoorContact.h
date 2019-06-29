/**
 * DoorContact.h
 * Version 1.1
 * Author:
 *  Cyrus Brunner
 * 
 * This library is an abstraction of a door contact.
 */

#ifndef DoorContact_h
#define DoorContact_h

#include <Arduino.h>

/**
 * Possible door contact states.
 */
enum DoorContactState {
    DOOR_STATE_OPEN = HIGH,
    DOOR_STATE_CLOSE = LOW
};

/**
 * Door contact info structure. Carries event info for when a door
 * contact event fires.
 */
struct DoorInfo {
    /**
     * The pin the door contact is attached to.
     */
    short pin;

    /**
     * The door contact state (open/closed).
     */
    volatile DoorContactState state;
};

/**
 * Hardware abstraction of a door contact.
 */
class DoorContact {
public:
    /**
     * Initializes a new instance of a door contact with the pin that the contact
     * is attached to and the callback to execute when the contact changes state.
     * @param pin The pin the door contact is attached to.
     * @param onStateChange The callback to execute when the door contact state changes.
     * Set NULL of not using events.
     */
    DoorContact(short pin, void (*onStateChange)(DoorInfo* sender));

    /**
     * Initializes the door contact.
     * @param usePullup If true, enables the internal pull-up resistor on the pin
     * the door contact is attached to.
     */
    void init(bool usePullup = true);

    /**
     * Gets the current state of the door contact.
     * @returns The current state.
     */
    DoorContactState getState();

    /**
     * Call this from your sketch's loop() function to check for state changes
     * and fire events when a state change is detected.
     */
    void loop();

    /**
     * Gets whether or not the door is open.
     * @returns true if open; Otherwise, false.
     */
    bool isOpen();

    /**
     * Gets whether or not the door is closed.
     * @returns true if closed; Otherwise, false.
     */
    bool isClosed();

private:
    DoorInfo* _sender;
    DoorContactState _lastState;
    void (*onStateChange)(DoorInfo* sender);
};

#endif