#include "PinHandler.h"

#include "Arduino.h"

PinHandler::PinHandler(){
    stored_pin = 1234;
}

PinHandler::PinHandler(int pin){
    stored_pin = pin;
}

bool PinHandler::verifyPin(int pin){
    if(stored_pin==pin){
        return true;
    }else{
        tries++;
        return false;
    }
}

void PinHandler::setPin(int pin){
    stored_pin = pin;
}

int PinHandler::getTries(){
    return tries;
}

void PinHandler::resetTries(){
    tries = 0;
}