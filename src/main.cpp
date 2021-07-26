#include <Arduino.h>
#include "protocols/protocols.h"

#define MIDI_CHANNEL 176
#define TOLLERANCE 200

Protocols prots = Protocols(MIDI_CHANNEL, TOLLERANCE);

// Arduino channel for potientiometer
uint8_t channel[] = {A1, A2, A3, A4, A5, A6};
int controller[] = {21, 22, 23, 24, 25, 26};

// Numbers of the MIDI channels (same indexes as the channel[])
int channelNumbers[] = {21};


int channelValues[(int)sizeof(channel)];

// This function reads all potentiometer states once
// and sends them
void setup() {
  Serial.begin(9600);

  for (int i=0; i<sizeof(channel); i++) {
    int value = analogRead(channel[i]);
    channelValues[i] = value;
    prots.send_MIDI_cmd(channelNumbers[i], prots.ConvertPotValue(value));
  }
}

// This loop runs infinitely and 
// executes the listening actions on
// the arduino
void loop() {
  for (int i=0; i<(int)sizeof(channel); i++) {
      int value = analogRead(channel[i]);
      if (prots.tolleranceTriggered(channelValues[i], value)) {
        prots.send_MIDI_cmd(channelNumbers[i], prots.ConvertPotValue(value));
        channelValues[i] = value;
      }
  }
}