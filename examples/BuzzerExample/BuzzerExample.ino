#include <Arduino.h>
#include "Buzzer.h"

#define PIN_BUZZER 5

void onBuzzerStateChange(BuzzerInfo* sender) {
  Serial.println(F("Buzzer state changed!"));
  Serial.print(F("Buzzer pin: "));
  Serial.println(sender->pin);
  Serial.print(F("Buzzer name: "));
  Serial.println(sender->name);
  Serial.print(F("New state: "));
  switch (sender->state) {
    case BUZZER_STATE_BUZZING:
      Serial.println(F("Buzzer is BUZZING"));
      break;
    case BUZZER_STATE_STOPPED:
      Serial.println(F("Buzzer is STOPPED"));
      break;
    default:
      Serial.println(F("Buzzer state is UNKNOWN"));
      break;
  }

  Serial.print(F("Frequency: "));
  Serial.println(sender->frequency);
}


Buzzer myBuzzer(PIN_BUZZER, onBuzzerStateChange, "TEST BUZZER");


void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(10);
  }

  myBuzzer.init();
}

void loop() {
  myBuzzer.playNote(BUZZER_NOTE_C, 1000);
  myBuzzer.playNote(BUZZER_NOTE_B, 1000);
  myBuzzer.playNote(BUZZER_NOTE_F, 1000);
  myBuzzer.playNote(BUZZER_NOTE_A, 1000);
}
