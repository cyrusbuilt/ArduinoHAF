/**
 * TemperatureConversion.cpp
 * Version 1.0a
 * Author:
 *  Cyrus Brunner
 *
 * This library provides utility methods for Temperature conversion.
 */

#include "TemperatureConversion.h"

double TemperatureConversion::convertRankineToKelvin(double temp) {
    return ((temp * 5) / 9);
}

double TemperatureConversion::convertRankineToCelcius(double temp) {
    return (((temp - 491.67) * 5) / 9);
}

double TemperatureConversion::convertRankineToFarenheit(double temp) {
    return (temp - 459.67);
}

double TemperatureConversion::convertKelvinToRankine(double temp) {
    return ((temp * 9) / 5);
}

double TemperatureConversion::convertKelvinToFarenHeit(double temp) {
    return (((temp * 9) / 5) - 459.67);
}

double TemperatureConversion::convertKelvinToCelcius(double temp) {
    return (temp + ABSOLUTE_ZERO_CELCIUS);
}

double TemperatureConversion::convertCelciusToRankine(double temp) {
    return (((temp - ABSOLUTE_ZERO_CELCIUS) * 9) / 5);
}

double TemperatureConversion::convertCelciusToKelvin(double temp) {
    return (temp - ABSOLUTE_ZERO_CELCIUS);
}

double TemperatureConversion::convertCelciusToFarenheit(double temp) {
    return (((temp * 9) / 5) + 32);
}

double TemperatureConversion::convertFarenheitToRankine(double temp) {
    return (temp + 459.67);
}

double TemperatureConversion::convertFarenheitToKelvin(double temp) {
    return (((temp + 459.67) * 5) / 9);
}

double TemperatureConversion::convertFarenheitToCelcius(double temp) {
    return ((temp - 32) * 5 / 9);
}

double TemperatureConversion::convertToRankine(TemperatureScale scale, double temp) {
    double val = 0;
    switch (scale) {
        case TEMP_SCALE_FARENHEIT:
            val = convertFarenheitToRankine(temp);
            break;
        case TEMP_SCALE_CELCIUS:
            val = convertCelciusToRankine(temp);
            break;
        case TEMP_SCALE_KELVIN:
            val = convertKelvinToRankine(temp);
            break;
        case TEMP_SCALE_RANKINE:
            val = temp;
            break;
        default:
            break;
    }
    return val;
}

double TemperatureConversion::convertFromRankine(TemperatureScale scale, double temp) {
    double val = 0;
    switch (scale) {
        case TEMP_SCALE_FARENHEIT:
            val = convertRankineToFarenheit(temp);
            break;
        case TEMP_SCALE_CELCIUS:
            val = convertRankineToCelcius(temp);
            break;
        case TEMP_SCALE_KELVIN:
            val = convertRankineToKelvin(temp);
            break;
        case TEMP_SCALE_RANKINE:
            val = temp;
            break;
        default:
            break;
    }
    return val;
}

double TemperatureConversion::convertToKelvin(TemperatureScale scale, double temp) {
    double val = 0;
    switch (scale) {
        case TEMP_SCALE_FARENHEIT:
            val = convertFarenheitToKelvin(temp);
            break;
        case TEMP_SCALE_CELCIUS:
            val = convertCelciusToKelvin(temp);
            break;
        case TEMP_SCALE_KELVIN:
            val = temp;
            break;
        case TEMP_SCALE_RANKINE:
            val = convertRankineToKelvin(temp);
            break;
        default:
            break;
    }
    return val;
}

double TemperatureConversion::convertFromKelvin(TemperatureScale scale, double temp) {
    double val = 0;
    switch (scale) {
        case TEMP_SCALE_FARENHEIT:
            val = convertKelvinToFarenHeit(temp);
            break;
        case TEMP_SCALE_CELCIUS:
            val = convertKelvinToCelcius(temp);
            break;
        case TEMP_SCALE_KELVIN:
            val = temp;
            break;
        case TEMP_SCALE_RANKINE:
            val = convertKelvinToRankine(temp);
            break;
        default:
            break;
    }
    return val;
}

double TemperatureConversion::convertToCelcius(TemperatureScale scale, double temp) {
    double val = 0;
    switch (scale) {
        case TEMP_SCALE_FARENHEIT:
            val = convertFarenheitToCelcius(temp);
            break;
        case TEMP_SCALE_CELCIUS:
            val = temp;
            break;
        case TEMP_SCALE_KELVIN:
            val = convertKelvinToCelcius(temp);
            break;
        case TEMP_SCALE_RANKINE:
            val = convertRankineToCelcius(temp);
            break;
        default:
            break;
    }
    return val;
}

double TemperatureConversion::convertFromCelcius(TemperatureScale scale, double temp) {
    double val = 0;
    switch (scale) {
        case TEMP_SCALE_FARENHEIT:
            val = convertCelciusToFarenheit(temp);
            break;
        case TEMP_SCALE_CELCIUS:
            val = temp;
            break;
        case TEMP_SCALE_KELVIN:
            val = convertCelciusToKelvin(temp);
            break;
        case TEMP_SCALE_RANKINE:
            val = convertCelciusToRankine(temp);
            break;
        default:
            break;
    }
    return val;
}

double TemperatureConversion::convertToFarenheit(TemperatureScale scale, double temp) {
    double val = 0;
    switch (scale) {
        case TEMP_SCALE_FARENHEIT:
            val = temp;
            break;
        case TEMP_SCALE_CELCIUS:
            val = convertCelciusToFarenheit(temp);
            break;
        case TEMP_SCALE_KELVIN:
            val = convertKelvinToFarenHeit(temp);
            break;
        case TEMP_SCALE_RANKINE:
            val = convertRankineToFarenheit(temp);
            break;
        default:
            break;
    }
    return val;
}

double TemperatureConversion::convertFromFarenheit(TemperatureScale scale, double temp) {
    double val = 0;
    switch (scale) {
        case TEMP_SCALE_FARENHEIT:
            val = temp;
            break;
        case TEMP_SCALE_CELCIUS:
            val = convertFarenheitToCelcius(temp);
            break;
        case TEMP_SCALE_KELVIN:
            val = convertFarenheitToKelvin(temp);
            break;
        case TEMP_SCALE_RANKINE:
            val = convertFarenheitToRankine(temp);
            break;
        default:
            break;
    }
    return val;
}

double TemperatureConversion::convert(TemperatureScale fromScale, TemperatureScale toScale, double temp) {
    double val = 0;
    switch (fromScale) {
        case TEMP_SCALE_FARENHEIT:
            val = convertFromFarenheit(toScale, temp);
            break;
        case TEMP_SCALE_CELCIUS:
            val = convertFromCelcius(toScale, temp);
            break;
        case TEMP_SCALE_KELVIN:
            val = convertFromKelvin(toScale, temp);
            break;
        case TEMP_SCALE_RANKINE:
            val = convertFromRankine(toScale, temp);
            break;
        default:
            break;
    }
    return val;
}
