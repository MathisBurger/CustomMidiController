#include <Arduino.h>
#include "./protocols/protocols.h"

Protocols prots = Protocols(176, 50);

uint8_t channel[] = {A0};
int controller[] = {21};
int channelValues[(int)sizeof(channel)];

void setup() {
  Serial.begin(9600);

  for (int i=0; i<(int)sizeof(channel); i++) {
    channelValues[i] = analogRead(channel[i]);
  }
}

void loop() {

    for (int i=0; i<(int)sizeof(channel); i++) {
      int value = analogRead(channel[i]);
      if (prots.tolleranceTriggered(channelValues[i], value)) {
        channelValues[i] = value;
        prots.send_MIDI_cmd(controller[i], value);
      }
    }
    delay(1000);

}