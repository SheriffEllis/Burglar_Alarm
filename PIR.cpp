#include "PIR.h"
#include "Arduino.h"

PIR::PIR(int input_pin){
    io_pin = input_pin;
    state = false;
    enabled = true;
    pinMode(io_pin, INPUT);
}

bool PIR::measure(){
    state = digitalRead(io_pin);
    time_of_last_measure = millis();
    return state;
}
