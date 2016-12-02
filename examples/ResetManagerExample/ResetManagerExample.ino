#include "Arduino.h"
#include "ResetManager.h"

#define PIN_TO_ATTACH_TO_RESET_PIN 5

void prompt() {
  Serial.println(F("Enter 's' for software reset or 'h' for hardware reset: "));
  while (Serial.available() < 1) {
    delay(10);
  }
}

void checkCommand() {
  char incomingByte = Serial.read();
  switch (incomingByte) {
    case 's':
      ResetManager.softReset();
      break;
      
    case 'h':
      ResetManager.hardReset();
      break;

    default:
      Serial.println(F("Unrecognized command."));
      prompt();
      checkCommand();
      break;
  }
}

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(1);
  }

  ResetManager.attachHardResetPin(PIN_TO_ATTACH_TO_RESET_PIN);
  prompt();
  checkCommand();
}

void loop() {
  // Nothing to do after setup()
}
