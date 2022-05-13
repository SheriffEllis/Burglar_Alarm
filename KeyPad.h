#ifndef KEYPAD_H
#define KEYPAD_H

#include "Arduino.h"

class KeyPad{
    private:
        void flushSerial();
        void waitForInput();
    public:
        int getPin();
        int getChoice(String choices[], int maxChoiceNum);
};

#endif
