/**
 * DimmableLight.h
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides a hardware abstraction of a dimmable light.
 */

#ifndef DimmableLight_h
#define DimmableLight_h

#include <Arduino.h>

/**
 * A dimmable light info structure. Carries information passed by event
 * callbacks when the light changes state.
 */
struct DimmableLightInfo {
  /**
   * The pin the light is attached to.
   */
  short pin;

  /**
   * The light level.
   */
  int level;

  /**
   * The light's minimum level.
   */
  int minLevel;

  /**
   * The light's maximum level.
   */
  int maxLevel;

  /**
   * Wether or not the light is on.
   */
  bool isOn;
};

/**
 * A hardware abstraction of a dimmable light.
 */
class DimmableLight
{
public:
  /**
   * Initializes a new instance of the DimmableLight class with the pin the
   * light is attached to, the minimum brightness level, maximum brightness
   * level and a user callback to call when state changes occur.
   * @param pin The pin the dimmable light is attached to.
   * @param minLevel The minimum brightness level (typically 0).
   * @param maxLevel The maximum brightness level (highest possible is 255).
   * @param onStateChange A user callback to execute when state changes occur.
   * Can be NULL.
   */
  DimmableLight(short pin, int minLevel, int maxLevel, void (*onStateChange)(DimmableLightInfo* sender));

  /**
   * Initializes the light.
   */
  void init();

  /**
   * Gets the minimum brightness level.
   * @return The minimum brightness level.
   */
  int getMinLevel();

  /**
   * Gets the maximum brightness level.
   * @return The maximum brightness level.
   */
  int getMaxLevel();

  /**
   * Gets the current brightness level.
   * @return The current brightness level.
   */
  int getLevel();

  /**
   * Checks to see if the light is at a brightness level high enough to be
   * considered to be in the "on" state.
   * @return true if on; Otherwise, false.
   */
  bool isOn();

  /**
   * Checks to see if the light is at a brightness level low enough to be
   * considered to be in the "off" state.
   * @return [description]
   */
  bool isOff();

  /**
   * Sets the brightness level.
   * @param level The brightness level to set.
   */
  void setLevel(int level);

  /**
   * Turns the light on by setting the brightness level to max.
   */
  void turnOn();

  /**
   * Turns the light off by setting the brightness level to minimum.
   */
  void turnOff();

  /**
   * Computes the light level percentage.
   * @param  level The level to get the percentage from.
   * @return       The light level percentage.
   */
  float getLevelPercentage(int level);

  /**
   * Computes the light level percentage off of the current level.
   * @return The light level percentage.
   */
  float getLevelPercentage();
private:
  DimmableLightInfo* _sender;
  void (*onStateChange)(DimmableLightInfo* sender);
};
#endif
