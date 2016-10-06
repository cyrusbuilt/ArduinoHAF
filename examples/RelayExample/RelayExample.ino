#include "Arduino.h"
#include "Relay.h"

#define PIN_RELAY 5  // The pin the relay is attached to. Modify to meet you needs.

void onRelayStateChange(RelayInfo* sender) {
  Serial.println(F("Relay state changed!"));
  Serial.print(F("Relay name: "));
  Serial.println(sender->name);
  Serial.print(F("Relay on pin: "));
  Serial.println(sender->pin);
  Serial.print(F("New state: "));
  switch (sender->state) {
    case RelayOpen:
      Serial.println(F("Relay is OPEN!"));
      break;
    case RelayClosed:
      Serial.println(F("Relay is CLOSED!"));
      break;
    default:
      Serial.println(F("Relay state is UNKNOWN."));
      break;
  }
}

// Attach the relay to the defined pin, provide a callback for when the relay
// changes state, and name the relay "TEST RELAY".
Relay myRelay(PIN_RELAY, onRelayStateChange, "TEST RELAY");

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(10);
  }

  // Initialize the relay.
  myRelay.init();
}

void loop() {
  // Activate (close) the relay.
  myRelay.close();

  // Wait 3 seconds.
  delay(3000);

  // Deactivate (open) the relay.
  myRelay.open();
}
