#include <Arduino.h>
#include "checker/checker.h"
#include "protocols/protocols.h"


// This function checks, if the value of an fader changed
// by a larger value than the tollerance. If this is true,
// the function changes the value of the element in the array
// of the memeory stack behind the pointer address and changes it from 
// the pointer. After that it sends the MIDI command to the 
// client computer
void checkFader(Protocols *prots, uint8_t *channel[], int *channelValues[], int *channelNumbers[]) {
    for (int i=0; i<sizeof(*channel); i++) {

    }
}

