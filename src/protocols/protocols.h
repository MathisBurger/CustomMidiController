#ifndef PROTOCOLS_H
#define PROTOCOLS_H

class Protocols
{
    private:
        int CONTROL_CHANGE;

    public:
        Protocols(int controlChange);
        int ConvertPotValue(int value);
        void send_MIDI_cmd(int controller, int value);
        
};

#endif