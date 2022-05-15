#ifndef KEYPAD_H
#define KEYPAD_H

#include "Arduino.h"

class KeyPad{
    private:
        void flushSerial();
        void waitForInput();
        void waitForInput(unsigned long timer_start, unsigned long timeout);
    public:
        int getPin();
        int getPin(unsigned long timer_start, unsigned long timeout);
        int getChoice(String choices, int max_choice_num);
};

#endif
