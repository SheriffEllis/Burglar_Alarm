#ifndef KEYPAD_H
#define KEYPAD_H

#include "Arduino.h"

class KeyPad{
    private:
        void waitForInput();
        void waitForInput(unsigned long timer_start, unsigned long timeout);
    public:
        void flushSerial();
        int getPin();
        int getPin(unsigned long timer_start, unsigned long timeout);
        int getChoice(int max_choice_num);
};

#endif
