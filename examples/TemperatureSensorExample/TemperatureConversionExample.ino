#include "Arduino.h"
#include "TemperatureConversion.h"

void printTestResult(char* testName, double expected, double result) {
    Serial.print(testName);
    Serial.print(F(": expected: "));
    Serial.print(expected);
    Serial.print(F(", result: "));
    Serial.print(result);
    if (result == expected) {
        Serial.println(F(", PASS"));
    }
    else {
        Serial.println(F(", FAIL"));
    }

    Serial.println();
}

void testConvertRankineToKelvin() {
    double expected = 1;
    double result = TemperatureConversion::convertRankineToKelvin(45);
    printTestResult("convertRankineToKelvin", expected, result);
}

void testConvertRankineToCelcius() {
    double expected = -248.15;
    double result = TemperatureConversion::convertRankineToCelcius(45);
    printTestResult("convertRankineToCelcius", expected, result);
}

void testConvertRankineToFarenheit() {
    double expected = -414.67;
    double result = TemperatureConversion::convertRankineToFarenheit(45);
    printTestResult("convertRankineToFarenheit", expected, result);
}

void testConvertKelvinToRankine() {
    double expected = 81;
    double result = TemperatureConversion::convertKelvinToRankine(45);
    printTestResult("convertKelvinToRankine", expected, result);
}

void testConvertKelvinToFarenheit() {
    double expected = -378.67;
    double result = TemperatureConversion::convertKelvinToFarenHeit(45);
    printTestResult("convertKelvinToFarenHeit", expected, result);
}

void testConvertKelvinToCelcius() {
    double expected = -228.15;
    double actual = TemperatureConversion::convertKelvinToCelcius(45);
    printTestResult("convertKelvinToCelcius", expected, actual);
}

void testConvertCelciusToRankine() {
    double expected = 572.67;
    double actual = TemperatureConversion::convertCelciusToRankine(45);
    printTestResult("convertCelciusToRankine", expected, actual);
}

void testConvertCelciusToKelvin() {
    double expected = 318.15;
    double actual = TemperatureConversion::convertCelciusToKelvin(45);
    printTestResult("convertCelciusToKelvin", expected, actual);
}

void testConvertCelciusToFarenheit() {
    double expected = 113;
    double actual = TemperatureConversion::convertCelciusToFarenheit(45);
    printTestResult("convertCelciusToFarenheit", expected, actual);
}

void testConvertFarenheitToRankine() {
    double expected = 504.67;
    double result = TemperatureConversion::convertFarenheitToRankine(45);
    printTestResult("convertFarenheitToRankine", expected, result);
}

void testConvertFarenheitToKelvin() {
    double expected = 280.37;
    double result = TemperatureConversion::convertFarenheitToKelvin(45);
    printTestResult("convertFarenheitToKelvin", expected, result);
}

void testConvertFarenheitToCelcius() {
    double expected = 7.22;
    double result = TemperatureConversion::convertFarenheitToCelcius(45);
    printTestResult("convertFarenheitToCelcius", expected, result);
}

void testConvertToRankine() {
    double expected = 81;
    double result = TemperatureConversion::convertToRankine(TEMP_SCALE_KELVIN, 45);
    Serial.println(F("Converting from scale: Kelvin, to Scale: Rankine"));
    printTestResult("convertToRankine", expected, result);
}

void testConvertFromRankine() {
    double expected = 25;
    double result = TemperatureConversion::convertFromRankine(TEMP_SCALE_KELVIN, 45);
    Serial.println(F("Converting from scale Rankine, to Scale: Kelvin"));
    printTestResult("convertFromRankine", expected, result);
}

void testConvertToKelvin() {
    double expected 280.37;
    double result = TemperatureConversion::convertToKelvin(TEMP_SCALE_FARENHEIT, 45);
    Serial.println(F("Converting from scale Farenheit, to Scale: Kelvin"));
    printTestResult("convertToKelvin", expected, result);
}

void testConvertFromKelvin() {
    double expected = -228.15;
    double result = TemperatureConversion::convertFromKelvin(TEMP_SCALE_CELCIUS, 45);
    Serial.println(F("Converting from scale Kelvin, to scale: Celcius"));
    printTestResult("convertFromKelvin", expected, result);
}

void testConvertToCelcius() {
    double expected = 7.22;
    double result = TemperatureConversion::convertToCelcius(TEMP_SCALE_FARENHEIT, 45);
    Serial.println(F("Converting from scale Farenheit, to scale Celcius"));
    printTestResult("convertToCelcius", expected, result);
}

void testConvertFromCelcius() {
    double expected = 113;
    double result = TemperatureConversion::convertFromCelcius(TEMP_SCALE_FARENHEIT, 45);
    Serial.println(F("Converting from scale Celcius to scale Farenheit"));
    printTestResult("convertFromCelcius", expected, result);
}

void testConvertFromFarenheit() {
    double expected = -378.67;
    double result = TemperatureConversion::convertFromFarenheit(TEMP_SCALE_KELVIN, 45);
    Serial.println(F("Converting from scale Farenheit to scale Kelvin"));
    printTestResult("convertFromFarenheit", expected, result);
}

void testConvert() {
    double expected = 81;
    double result = TemperatureConversion::convert(TEMP_SCALE_KELVIN, TEMP_SCALE_RANKINE, 45);
    Serial.println(F("Converting from scale Kelvin to scale Rankine"));
    printTestResult("convert", expected, result);
}

void setup() {
    Serial.begin(9600);
    while (!Serial) {
        delay(1);
    }

    Serial.println("**** Begin TemperatureConversion tests ****");
    Serial.println();

    testConvertRankineToKelvin();
    testConvertRankineToCelcius();
    testConvertRankineToFarenheit();
    testConvertKelvinToRankine();
    testConvertKelvinToFarenheit();
    testConvertKelvinToCelcius();
    testConvertCelciusToRankine();
    testConvertCelciusToKelvin();
    testConvertCelciusToFarenheit();
    testConvertFarenheitToRankine();
    testConvertFarenheitToKelvin();
    testConvertFarenheitToCelcius();
    testConvertToRankine();
    testConvertFromRankine();
    testConvertToKelvin();
    testConvertFromKelvin();
    testConvertToCelcius();
    testConvertFromCelcius();
    testConvertFromFarenheit();
    testConvert();
}

void loop() {
    // Nothing to do here.
}
