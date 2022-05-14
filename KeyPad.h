#ifndef KEYPAD_H
#define KEYPAD_H

#include "Arduino.h"

class KeyPad{
    private:
        const static unsigned long TIMEOUT = 20000;
        void flushSerial();
        void waitForInput();
        void waitForInput(unsigned long timer_start);
    public:
        int getPin();
        int getPin(unsigned long timer_start);
        int getChoice(String choices[], int max_choice_num);
};

#endif
