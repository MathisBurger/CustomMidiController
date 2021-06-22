#include <Arduino.h>
#include "protocols/protocols.h"
<<<<<<< HEAD
=======
#include "checker/checker.h"
>>>>>>> eaebf71777200030a11a0804e78b94f030ab54da

#define MIDI_CHANNEL 176
#define TOLLERANCE 50

Protocols prots = Protocols(MIDI_CHANNEL, TOLLERANCE);

// Arduino channel for potientiometer
uint8_t channel[] = {A0};
<<<<<<< HEAD
int controller[] = {21};
=======

// Numbers of the MIDI channels (same indexes as the channel[])
int channelNumbers[] = {21};

>>>>>>> eaebf71777200030a11a0804e78b94f030ab54da
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

<<<<<<< HEAD
    // This loop checks, if any values of the
    // potentiometer changed
    for (int i=0; i<(int)sizeof(channel); i++) {
=======
    checkFader(prots, channel, channelValues, channelNumbers);
    delay(1000);
    Serial.println(channelValues[0]);
>>>>>>> eaebf71777200030a11a0804e78b94f030ab54da

        int value = analogRead(channel[i]);
        if (prots.tolleranceTriggered(channelValues[i], value)) {
            channelValues[i] = value;
            prots.send_MIDI_cmd(controller[i], value);
        }
    }
}