#include <Arduino.h>
#include "protocols.h"

// This method constructor initializes the controlChange
// and the tollerance of the potentiometer,
// which may be needed later for
// some protocol/converting actions
Protocols::Protocols(int controlChange, int tollerance) {
    CONTROL_CHANGE = controlChange;
    TOLLERANCE = tollerance;
}

// This method converts the potentiometer value,
// which is between 0 and 1023 to a relative value
// between 0 and 127
int Protocols::ConvertPotValue(int value) {
    return (int)map(value, 0, 1023, 0, 127);
}

// This method sends an MIDI command to the client 
// via serial communication. The MIDI command contains
// only the controller number and its value
void Protocols::send_MIDI_cmd(int controller, int value) {
    Serial.write(CONTROL_CHANGE);
    Serial.write(controller);
    Serial.write(value);
}

// This method checks if the difference of the two given
// values is bigger than the tollerene, which is an private
// variable of the class. This validation state is being 
// returned as a boolean value
bool Protocols::tolleranceTriggered(int oldValue, int newValue) {
    int difference = oldValue - newValue;
    if (difference < 0) {
        return difference < -TOLLERANCE;
    } else {
        return difference > TOLLERANCE;
    }
}
