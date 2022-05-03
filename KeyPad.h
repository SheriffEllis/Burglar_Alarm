#ifndef KEYPAD_H
#define KEYPAD_H

#include "Arduino.h"

class KeyPad{
  public:
    int getPin();
    int getChoice(String choices[]);
};

#endif
