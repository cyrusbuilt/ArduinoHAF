@echo off
cls

set BUILD_ARGS=--lib="." --verbose --board=uno --board=micro --board=leonardo --board=megaatmega1280 --board=megaatmega2560 --board=huzzah

:: Get script directory
set SCRIPT_DIR=%~dp0
set SCRIPT_DIR=%SCRIPT_DIR:~0,-1%

:: Build all examples for supported platforms. We can probably do this much more
:: elegantly using a loop.
pio ci %BUILD_ARGS% examples\BuzzerExample/BuzzerExample.ino
pio ci %BUILD_ARGS% examples\DimmableLightExample/DimmableLightExample.ino
pio ci %BUILD_ARGS% examples\DS6120SensorExample/DS6120SensorExample.ino
pio ci %BUILD_ARGS% examples\L298MotorControlExample/L298MotorControlExample.ino
pio ci %BUILD_ARGS% examples\LEDExample/LEDExample.ino
pio ci %BUILD_ARGS% examples\RelayExample/RelayExample.ino
pio ci %BUILD_ARGS% examples\ToggleSwitchExample/ToggleSwitchExample.ino
pio ci %BUILD_ARGS% examples\REXExample/REXExample.ino
pio ci %BUILD_ARGS% examples\ResetManagerExample/ResetManagerExample.ino
pio ci %BUILD_ARGS% examples\TemperatureConversionExample/TemperatureConversionExample.ino
pio ci %BUILD_ARGS% examples\TemperatureSensorExample/TemperatureSensorExample.ino
pio ci %BUILD_ARGS% examples\PIRExample/PIRExample.ino
pio ci %BUILD_ARGS% examples\DoorContactExample/DoorContactExample.ino
pio ci %BUILD_ARGS% examples\UltraSoniceDistanceSensorExample/UltraSoniceDistanceSensorExample.ino
pio ci %BUILD_ARGS% examples\UltraSoniceDistanceSensorEventExample/UltraSoniceDistanceSensorEventExample.ino

exit %ERRORLEVEL%
