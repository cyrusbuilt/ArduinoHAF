@echo off
cls

set BUILD_ARGS=--lib="." --verbose --board=uno --board=micro --board=leonardo --board=megaatmega1280 --board=megaatmega2560

:: Get script directory
set SCRIPT_DIR=%~dp0
set SCRIPT_DIR=%SCRIPT_DIR:~0,-1%

:: Build all examples for supported platforms. We can probably do this much more
:: elegantly using a loop.
platformio ci %BUILD_ARGS% examples/BuzzerExample/BuzzerExample.ino
platformio ci %BUILD_ARGS% examples/DimmableLightExample/DimmableLightExample.ino
platformio ci %BUILD_ARGS% examples/DS6120SensorExample/DS6120SensorExample.ino
platformio ci %BUILD_ARGS% examples/L298MotorControlExample/L298MotorControlExample.ino
platformio ci %BUILD_ARGS% examples/LEDExample/LEDExample.ino
platformio ci %BUILD_ARGS% examples/RelayExample/RelayExample.ino
platformio ci %BUILD_ARGS% examples/ToggleSwitchExample/ToggleSwitchExample.ino
platformio ci %BUILD_ARGS% examples/REXExample/REXExample.ino
platformio ci %BUILD_ARGS% examples/ResetManagerExample/ResetManagerExample.ino
platformio ci %BUILD_ARGS% examples/TemperatureConversionExample/TemperatureConversionExample.ino
platformio ci %BUILD_ARGS% examples/TemperatureSensorExample/TemperatureSensorExample.ino
platformio ci %BUILD_ARGS% examples/PIRExample/PIRExample.ino

exit %ERRORLEVEL%
