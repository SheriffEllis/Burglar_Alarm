#include "MagneticSwitch.h"
#include "Arduino.h"

MagneticSwitch::MagneticSwitch(int input_pin){
    io_pin = input_pin;
    state = false;
    enabled = true;
    pinMode(io_pin, INPUT);
}

bool MagneticSwitch::measure(){
    state = digitalRead(io_pin);
    return state;
}
