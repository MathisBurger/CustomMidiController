#ifndef PROTOCOLS_H
#define PROTOCOLS_H

class Protocols
{
    private:
        int CONTROL_CHANGE;
        int CONTROLLER_NUMBER;

    public:
        Protocols(int controlChange, int controllerNumber);
        int ConvertPotValue(int value);
};

#endif