#include "PinHandler.h"

#include "Arduino.h"

PinHandler::PinHandler(){
    stored_pin = 1234;
}

PinHandler::PinHandler(int pin){
    stored_pin = pin;
}

bool PinHandler::verifyPin(int pin){
    //TODO : implement tries left
    return stored_pin == pin;
}

void PinHandler::setPin(int pin){
    stored_pin = pin;
}
