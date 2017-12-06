/**
 * TemperatureConversion.h
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides utility methods for Temperature conversion.
 */

#ifndef TemperatureConversion_h
#define TemperatureConversion_h

#include <Arduino.h>

/**
 * Possible temperature measurement scales.
 */
enum TemperatureScale {
    TEMP_SCALE_CELCIUS = 0,
    TEMP_SCALE_FARENHEIT = 1,
    TEMP_SCALE_KELVIN = 2,
    TEMP_SCALE_RANKINE = 3
};

/**
 * Temperature conversion utilities.
 */
class TemperatureConversion {
public:
    /**
     * Absolute zero temperature in Celcius scale.
     */
    static constexpr double ABSOLUTE_ZERO_CELCIUS = -273.15;

    /**
     * Absolute zero temperature in Farenheit scale.
     */
    static constexpr double ABSOLUTE_ZERO_FARENHEIT = -459.67;

    /**
     * Absolute zero temperature in Kelvin scale.
     */
    static constexpr double ABSOLUTE_ZERO_KELVIN = 0;

    /**
     * Absolute zero temperature in Rankine scale.
     */
    static constexpr double ABSOLUTE_ZERO_RANKINE = 0;

    /**
     * Converts the temperature from Rankine to Kelvin scale. Formula = [K] =
     * [R] x 5/9.
     * @param  temp The temperature in degrees Rankine.
     * @return      The temperature value in degrees Kelvin.
     */
    static double convertRankineToKelvin(double temp);

    /**
     * Converts the temperature from Rankine to Celcius scale. Formula = [C] =
     * ([R] - 491.67) x 5/9.
     * @param  temp The temperature in degrees Rankine.
     * @return      The temperature value in degrees Celcius.
     */
    static double convertRankineToCelcius(double temp);

    /**
     * Converts the temperature from Rankine to Farenheit scale. Formula = [F] =
     * [K] x 9/5 - 459.67.
     * @param  temp The temperature in degrees Rankine.
     * @return      The temperature value in degrees Farenheit.
     */
    static double convertRankineToFarenheit(double temp);

    /**
     * Converts the temperature from Kelvin to Rankine scale. Formula = [R] =
     * [K] x 9/5.
     * @param  temp The temperature in degrees Kelvin.
     * @return      The temperature value in degrees Rankine.
     */
    static double convertKelvinToRankine(double temp);

    /**
     * Converts the temperature from Kelvin to Farenheit scale. Formula = [F] =
     * [K] x 9/5 - 459.67.
     * @param  temp The temperature in degrees Kelvin.
     * @return      The temperature value in degrees Farenheit.
     */
    static double convertKelvinToFarenHeit(double temp);

    /**
     * Converts the temperature from Kelvin to Celcius scale. Formula = [C] =
     * [K] - 273.15.
     * @param  temp The temperature in degrees Kelvin.
     * @return      The temperature value in degrees Celcius.
     */
    static double convertKelvinToCelcius(double temp);

    /**
     * Converts the temperature from Celcius to Rankine scale. Formula = [R] =
     * ([C] + 273.15) x 9/5.
     * @param  temp The temperature in degrees Celcius.
     * @return      The temperature value in degrees Rankine.
     */
    static double convertCelciusToRankine(double temp);

    /**
     * Converts the temperature from Celcius to Kelvin. Formula = [K] = [C] +
     * 273.15.
     * @param  temp The temperature in degrees Celcius.
     * @return      The temperature value in degrees Kelvin.
     */
    static double convertCelciusToKelvin(double temp);

    /**
     * Converts the temperature from Celcius to Farenheit scale.
     * Formula = [F] = [C] x 9/5 + 32.
     * @param  temp The temperature in degrees Farenheit.
     * @return      The temperature value in degrees Rankine.
     */
    static double convertCelciusToFarenheit(double temp);

    /**
     * Converts the temperature from Farenheit to Rankine scale.
     * Formula = [R] = [F] + 459.67.
     * @param  temp The temperature in degrees Farenheit.
     * @return      The temperature value in degrees Rankine.
     */
    static double convertFarenheitToRankine(double temp);

    /**
     * Converts the temperature from Farenheit to Kelvin scale.
     * Formula = [K] = ([F] + 459.67) x 5/9.
     * @param  temp The temperature in degrees Farenheit.
     * @return      The temperature value in degrees Kelvin.
     */
    static double convertFarenheitToKelvin(double temp);

    /**
     * Converts the temperature from Farenheit to Celcius scale.
     * Formula = [C] = ([F] - 32) x 5/9.
     * @param  temp The temperature in degrees Farenheit.
     * @return      The temperature value in degrees Celcius.
     */
    static double convertFarenheitToCelcius(double temp);

    /**
     * Converts the specified temperature value to Rankine scale.
     * @param  scale The temperature scale to convert from.
     * @param  temp  The temperature value to convert to Rankine scale.
     * @return       The temperature value in degrees Rankine.
     */
    static double convertToRankine(TemperatureScale scale, double temp);

    /**
     * Converts the specified temperature in Rankine to the specified scale.
     * @param  scale The scale to convert the specified Rankine value to.
     * @param  temp  The temperature value in degrees Rankine.
     * @return       The temperature value in the specified scale.
     */
    static double convertFromRankine(TemperatureScale scale, double temp);

    /**
     * Converts the specified value from the specified scale to degrees Kelvin.
     * @param  scale The temperature scale to convert the value from.
     * @param  temp  The temperature value to convert.
     * @return       The temperature in degrees Kelvin.
     */
    static double convertToKelvin(TemperatureScale scale, double temp);

    /**
     * Converts the specified temperature from Kelvin to the specified scale.
     * @param  scale The scale to convert to.
     * @param  temp  The temperature in degrees Kelvin.
     * @return       The temperature value in the specified scale.
     */
    static double convertFromKelvin(TemperatureScale scale, double temp);

    /**
     * Converts the specified temperature to the specified Celcius scale.
     * @param  scale The scale to convert to Celcius.
     * @param  temp  The temperature value.
     * @return       The temperature value in degrees Celcius.
     */
    static double convertToCelcius(TemperatureScale scale, double temp);

    /**
     * Converts the specified temperature value in degrees Celcius to the
     * specified scale.
     * @param  scale The scale to convert the temperature value to.
     * @param  temp  The temperature in degrees Celcius.
     * @return       The temperature value in the specified scale.
     */
    static double convertFromCelcius(TemperatureScale scale, double temp);

    /**
     * Converts the specified temperature value to Farenheit scale.
     * @param  scale The scale to convert the temperature from.
     * @param  temp  The temperature value in the specified scale.
     * @return       The temperature in degrees Farenheit.
     */
    static double convertToFarenheit(TemperatureScale scale, double temp);

    /**
     * Convert the temperature in degrees Farenheit to the specified scale.
     * @param  scale The scale to convert to.
     * @param  temp  The temperature in degrees Farenheit.
     * @return       The temperature value in the specified scale.
     */
    static double convertFromFarenheit(TemperatureScale scale, double temp);

    /**
     * Converts the specified temperature from one scale to another.
     * @param  fromScale The scale to convert the temperature from.
     * @param  toScale   The scale to convert the temperature to.
     * @param  temp      The temperature value to convert.
     * @return           The temperature in the degress matching the 'to' scale.
     */
    static double convert(TemperatureScale fromScale, TemperatureScale toScale, double temp);
};

#endif
