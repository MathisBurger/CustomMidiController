#include <Arduino.h>
#include "protocols.h"

// This method constructor initializes the controlChange
// and controllerNumber, which may be needed later for
// some protocol/converting actions
Protocols::Protocols(int controlChange, int controllerNumber) {
    CONTROL_CHANGE = controlChange;
    CONTROLLER_NUMBER = controllerNumber;
}

// This method converts the potentiometer value,
// which is between 0 and 1023 to a relative value
// between 0 and 127
int Protocols::ConvertPotValue(int value) {
    return (int)map(value, 0, 1023, 0, 127);
}
