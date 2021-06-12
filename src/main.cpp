#include <Arduino.h>
#include "./protocols/protocols.h"

Protocols prots = Protocols(176);

void setup() {
  Serial.begin(9600);
}

void loop() {

  Serial.println(prots.ConvertPotValue(analogRead(A0)));
  delay(1000);
}