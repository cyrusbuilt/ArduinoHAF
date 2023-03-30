#include "Arduino.h"
#include "LED.h"

#define PIN_LED 4  // The pin the LED is attached to. Change to meet your needs.

void onLEDStateChange(LEDInfo* sender) {
  Serial.println(F("LED changed state!"));
  Serial.print(F("LED on pin: "));
  Serial.println(sender->pin);
  Serial.print(F("New state: "));
  switch (sender->state) {
    case LED_On:
      Serial.println(F("LED is ON!"));
      break;
    case LED_Off:
      Serial.println(F("LED is OFF!"));
      break;
    default:
      Serial.println(F("LED state is UNKNOWN."));
      break;
  }
}

// Attach and LED to the pin and assign a handler for state changes.
HAF_LED blinker(PIN_LED, onLEDStateChange);


void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(10);
  }

  // Initialize the LED.
  blinker.init();
}

void loop() {
  // Blink the LED roughly 3 times per second.
  for (int i = 0; i < 4; i++) {
    delay(333.33);
    blinker.blink(333.33);
  }
}
