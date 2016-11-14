#!/bin/sh

# Get script dir.
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd)"

# Build targets.
export PATH=~/.atom/packages/platformio-ide/penv/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:~/n/bin:$PATH

platformio ci --lib="." --verbose --board=uno --board=micro --board=leonardo --board=megaatmega1280 --board=megaatmega2560 examples/BuzzerExample/BuzzerExample.ino
platformio ci --lib="." --verbose --board=uno --board=micro --board=leonardo --board=megaatmega1280 --board=megaatmega2560 examples/DimmableLightExample/DimmableLightExample.ino
platformio ci --lib="." --verbose --board=uno --board=micro --board=leonardo --board=megaatmega1280 --board=megaatmega2560 examples/DS6120SensorExample/DS6120SensorExample.ino
platformio ci --lib="." --verbose --board=uno --board=micro --board=leonardo --board=megaatmega1280 --board=megaatmega2560 examples/L298MotorControlExample/L298MotorControlExample.ino
platformio ci --lib="." --verbose --board=uno --board=micro --board=leonardo --board=megaatmega1280 --board=megaatmega2560 examples/LEDExample/LEDExample.ino
platformio ci --lib="." --verbose --board=uno --board=micro --board=leonardo --board=megaatmega1280 --board=megaatmega2560 examples/RelayExample/RelayExample.ino
platformio ci --lib="." --verbose --board=uno --board=micro --board=leonardo --board=megaatmega1280 --board=megaatmega2560 examples/ToggleSwitchExample/ToggleSwitchExample.ino

exit $?
