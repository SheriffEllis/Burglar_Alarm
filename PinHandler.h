/*
The Pin Handler class has the job of storing and verifying the pin
of the user. The stored pin is a private variable and possesses no
getter methods so as to prevent access to any other part of the program.
The pin can only be set or verified.

A counter for the number of failed pin attempts is also stored to allow
the program to give a limited number of tries at entering the correct pin
in certain parts of the logic.
*/


#ifndef PINHANDLER_H
#define PINHANDLER_H

#include "Arduino.h"

class PinHandler{
  private:
    int stored_pin;
    int tries; // number of failed attempts to enter the correct pin
  public:
    PinHandler();
    bool verifyPin(int pin);
    void setPin(int pin);
    int getTries();
    void resetTries();
};

#endif // PINHANDLER_H
