# ArduinoHAF :: Hardware Abstraction Framework for Arduino

[![Build Status](https://travis-ci.org/cyrusbuilt/ArduinoHAF.svg?branch=master)](https://travis-ci.org/cyrusbuilt/ArduinoHAF)

==========================================================================

## Description

The goal of ArduinoHAF is to provide a Framework of hardware abstractions to
make it easier and cleaner to add devices to your project. This allows you to
think of things like LEDs and Relays (for example) as building blocks that you
can just add on to your sketch, instead writing a bunch of code into your sketch
to do things like initialize the pin(s) the device is attached to, trigger the
output to go low or high and any other logic needed to interact with that piece.
Instead, you just declare an instance of the device, initialize it, and then use
the appropriate methods to control it. Many of the abstractions in this
Framework will optionally allow you to attach callbacks to act as event handlers
for when the device changes state.

At the moment, the Framework only includes abstractions for LEDs and Relays, but
new devices will continue to be added.

## How to use

Add the appropriate header for the device you want to use in your sketch. So, if
you wanted to use an LED, you could do it like so:

```cpp
#include <Arduino.h>
#include "LED.h"

#define PIN_LED 4

LED myLED(PIN_LED, NULL);

void setup() {
  myLED.init();
}

void loop() {
  for (int i = 0; i < 4; i++) {
    delay(333.33);
    myLED.blink(333.33);
  }
}
```

## How to install

If you are using PlatformIO [http://platformio.org/](http://platformio.org/), you can simply run the
following command:

```bash
> platformio lib install arduinohaf
```

Otherwise, download the zip from [https://github.com/cyrusbuilt/ArduinoHAF/archive/master.zip](https://github.com/cyrusbuilt/ArduinoHAF/archive/master.zip)
then extract its contents to a folder called "ArduinoHAF" and then move that
folder to your libraries folder.

## FAQ

Q: Why not just have a single include so you can include the whole framework?  
A: By having separate includes, you can keep code size down. Every include you
add to your sketch increases the compiled size and memory usage.
Microcontrollers have a fairly finite amount of program storage and memory
available. By only including the pieces you need, you can hopefully keep it to a
minimum. As this framework grows, attempting to include the whole thing would be
quite expensive and may exceed your Arduino's total capacity, causing the Build
to fail.
