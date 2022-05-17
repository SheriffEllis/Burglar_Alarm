#include "PinHandler.h"

#include "Arduino.h"

// Constructor sets default pin value and failed attempts to 0
PinHandler::PinHandler(){
    stored_pin = 1234; // Default pin
    tries = 0;
}

// Takes a pin and compares it against the stored pin, incrementing tries if incorrect
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

// Setter method for pin
void PinHandler::setPin(int pin){
    stored_pin = pin;
}

// Getter method for tries
int PinHandler::getTries(){
    return tries;
}

// Sets tries to 0
void PinHandler::resetTries(){
    tries = 0;
}