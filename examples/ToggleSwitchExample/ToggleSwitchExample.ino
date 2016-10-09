#include "Arduino.h"
#include "ToggleSwitch.h"

#define PIN_SWITCH 4

void onSwitchStateChange(SwitchInfo* sender) {
  Serial.println(F("Switch state changed!"));
  Serial.print(F("Switch name: "));
  Serial.println(sender->name);
  Serial.print(F("Switch attached to pin: "));
  Serial.println(sender->pin);
  Serial.print(F("Switch state: "));
  switch (sender->state) {
    case SWITCH_STATE_ON:
      Serial.println(F("Switch is ON"));
      break;
    case SWITCH_STATE_OFF:
      Serial.println(F("Switch is OFF"));
      break;
    default:
      Serial.println(F("Switch state is UNKNOWN"));
      break;
  }
}


ToggleSwitch mySwitch(PIN_SWITCH, onSwitchStateChange, "TEST SWITCH");


void setup() {
  Serial.begin(9600);
  if (!Serial) {
    delay(10);
  }

  mySwitch.init();
}

void loop() {
  mySwitch.loop();
}
