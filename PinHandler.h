#ifndef PINHANDLER_H
#define PINHANDLER_H

#include "Arduino.h"

class PinHandler{
  private:
    int stored_pin;
    int tries;
  public:
    PinHandler();
    PinHandler(int pin);
    bool verifyPin(int pin);
    void setPin(int pin);
    int getTries();
    void resetTries();
};

#endif // PINHANDLER_H
