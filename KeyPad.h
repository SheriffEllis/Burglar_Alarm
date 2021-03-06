/*
Provides a means of acquiring input in the form of pins, numbers, and choices
from the user's keypad/serial input
*/

#ifndef KEYPAD_H
#define KEYPAD_H

#include "Arduino.h"

class KeyPad{
    private:
        void waitForInput();
        void waitForInput(unsigned long timer_start, unsigned long timeout);
    public:
        void flushSerial();
        int getNumber(int upper, int lower);
        int getPin();
        int getPin(unsigned long timer_start, unsigned long timeout);
        int getChoice(int max_choice_num);
};

#endif
