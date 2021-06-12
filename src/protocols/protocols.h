#ifndef PROTOCOLS_H
#define PROTOCOLS_H

class Protocols
{
    private:
        int CONTROL_CHANGE;
        int TOLLERANCE;

    public:
        Protocols(int controlChange, int tollerance);
        int ConvertPotValue(int value);
        void send_MIDI_cmd(int controller, int value);
        bool tolleranceTriggered(int oldValue, int newValue);
};

#endif