#!/bin/bash

# Get script dir.
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd)"

# Build targets.
export PATH=~/.platformio/penv/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:~/n/bin:$PATH

echo
echo "Building targets..."
echo
EXAMPLES=(
    examples/BuzzerExample/BuzzerExample.ino
    examples/DimmableLightExample/DimmableLightExample.ino
    examples/DoorContactExample/DoorContactExample.ino
    examples/DS6120SensorExample/DS6120SensorExample.ino
    examples/L298MotorControlExample/L298MotorControlExample.ino
    examples/LEDExample/LEDExample.ino
    examples/PIRExample/PIRExample.ino
    examples/RelayExample/RelayExample.ino
    examples/ResetManagerExample/ResetManagerExample.ino
    examples/REXExample/REXExample.ino
    examples/TemperatureConversionExample/TemperatureConversionExample.ino
    examples/TemperatureSensorExample/TemperatureSensorExample.ino
    examples/ToggleSwitchExample/ToggleSwitchExample.ino
    examples/UltraSonicDistanceSensorExample/UltraSonicDistanceSensorExample.ino
    examples/UltraSoniceDistanceSensorEventExample/UltraSoniceDistanceSensorEventExample.ino
    examples/WaterLevelSensorExample/WaterLevelSensorExample.ino
)

total=${#EXAMPLES[@]}
current=0
progress=0
for i in "${EXAMPLES[@]}"
do
    let "current++"
    let "progress = ($current * 100) / $total"
    printf "Processing example sketch: %s" $i
    printf " (%s%%)\n" $progress
    pio ci --lib="." --verbose --board=uno --board=micro --board=leonardo --board=megaatmega1280 --board=megaatmega2560 --board=huzzah --board=featheresp32 $i
done

echo
echo "Cleaning documentation output..."
echo
rm -rf ${SCRIPT_DIR}/docs

echo
echo "Generating API documentation..."
echo
doxygen ${SCRIPT_DIR}/Doxyfile

exit $?
