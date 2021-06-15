#include <Arduino.h>
#include "protocols/protocols.h"
#include "checker/checker.h"

Protocols prots = Protocols(176, 50);

// Arduino channel for potientiometer
uint8_t channel[] = {A0};

// Numbers of the MIDI channels (same indexes as the channel[])
int channelNumbers[] = {21};

int channelValues[(int)sizeof(channel)];

// This function reads all potentiometer states once
// and sends them
void setup() {
  Serial.begin(9600);

  for (int i=0; i<(int)sizeof(channel); i++) {
    int value = analogRead(channel[i]);
    channelValues[i] = value;
    prots.send_MIDI_cmd(channelNumbers[i], prots.ConvertPotValue(value));
  }
}

// This loop runs infinitely and 
// executes the listening actions on
// the arduino
void loop() {

    checkFader(prots, channel, channelValues, channelNumbers);
    delay(1000);
    Serial.println(channelValues[0]);

}