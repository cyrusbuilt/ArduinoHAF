/**
 * Buzzer.h
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides a hardware abstraction for a Piezo buzzer.
 */

#ifndef Buzzer_h
#define Buzzer_h

#include <Arduino.h>

/**
 * Frequencies that represent musical notes.
 */
enum BuzzerNotes {
  BUZZER_NOTE_C = 262,
  BUZZER_NOTE_D = 294,
  BUZZER_NOTE_E = 330,
  BUZZER_NOTE_F = 349,
  BUZZER_NOTE_G = 392,
  BUZZER_NOTE_A = 440,
  BUZZER_NOTE_B = 494,
  BUZZER_NOTE_C = 523
};

/**
 * Possible buzzer states.
 */
enum BuzzerState {
  BUZZER_STATE_BUZZING,
  BUZZER_STATE_STOPPED
};

/**
 * Buzzer info structure. Carries information passed when an event callback fires.
 */
struct BuzzerInfo {
  /**
   * The pin the buzzer is attached to.
   */
  short pin;

  /**
   * The state of the buzzer.
   */
  volatile BuzzerState state;

  /**
   * The buzzer's name.
   */
  const char* name;

  /**
   * The current buzzer frequency.
   */
  int frequency;
};

/**
 * Hardware abstraction of a piezo buzzer.
 */
class Buzzer
{
public:
  /**
   * Initializes a new instance of the buzzer with the pin the buzzer is
   * attached to, a callback to fire when the state changes, and the name of the
   * buzzer.
   * @param pin The pin the buzzer is attached to.
   * @param onStateChange The callback to call when the buzzer state changes.
   * @param name The name of the buzzer.
   */
  Buzzer(short pin, void (*onStateChange)(BuzzerInfo* sender), const char* name);

  /**
   * Initializes the buzzer.
   */
  void init();

  /**
   * Gets the current state of the buzzer.
   * @return The current state of the buzzer.
   */
  BuzzerState getState();

  /**
   * Activates the buzzer at the specified frequency for the specified duration.
   * @param freq     The frequency to buzz at.
   * @param duration The time in milliseconds to buzz for.
   */
  void buzz(int freq, unsigned long duration);

  /**
   * Plays the specified note for specified duration.
   * @param note     The note to play.
   * @param duration The time in milliseconds to play the note for.
   */
  void playNote(BuzzerNotes note, unsigned long duration);

private:
  BuzzerInfo* _sender;
  void (*onStateChange)(BuzzerInfo* sender);
};
#endif
