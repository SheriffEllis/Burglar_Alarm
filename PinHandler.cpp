#include "PinHandler.h"

#include "Arduino.h"

PinHandler::PinHandler(){
    stored_pin = 1234; // Default pin
}

PinHandler::PinHandler(int pin){
    stored_pin = pin;
}

bool PinHandler::verifyPin(int pin){
    if(stored_pin==pin){
        Serial.println("CORRECT PIN");
        return true;
    }else{
        if(pin != -1){ // Pin of -1 indicates a timeout
            Serial.println("INCORRECT PIN"); // only print this if it's not a timeout
        }
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