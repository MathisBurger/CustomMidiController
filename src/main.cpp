#include <Arduino.h>
#include "protocols/protocols.h"
#include "checker/checker.h"

Protocols prots = Protocols(176, 50);

uint8_t channel[] = {A0};
int channelNumbers[] = {21};
int channelValues[(int)sizeof(channel)];


void setup() {
  Serial.begin(9600);

  for (int i=0; i<(int)sizeof(channel); i++) {
    channelValues[i] = analogRead(channel[i]);
  }
}

void loop() {

    checkFader(prots, channel, channelValues, channelNumbers);
    delay(1000);
    Serial.println(channelValues[0]);

}