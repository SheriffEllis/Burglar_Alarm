#include "MagneticSwitch.h"
#include "Arduino.h"

// Constructor sets pin and default parameters
MagneticSwitch::MagneticSwitch(int input_pin){
    io_pin = input_pin;
    state = false;
    enabled = true;
    pinMode(io_pin, INPUT);
}

// outputs value of digital read at pin and stores in state variable
bool MagneticSwitch::measure(){
    if(enabled){ // Only take a measurement if the sensor is enabled
        state = digitalRead(io_pin);
    }else{
        state = false;
    }
    return state;
}
