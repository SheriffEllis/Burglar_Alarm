#include "PIR.h"
#include "Arduino.h"

// Constructor sets pin and default parameters
PIR::PIR(int input_pin){
    io_pin = input_pin;
    state = false;
    enabled = true;
    pinMode(io_pin, INPUT);
}

// allows physical component time to calibrate at the start of the program
void PIR::calibrate(int seconds){
    Serial.println("Please wait while PIR sensor calibrates...");
    for (int i = seconds; i > 0; i--) // wait for number of seconds and display countdown
    {
        Serial.println(i);
        delay(1000);
    }
}

// outputs value of digital read at pin and stores in state variable
bool PIR::measure(){
    if(enabled){ // Only take a measurement if the sensor is enabled
        state = digitalRead(io_pin);
    }else{
        state = false;
    }
    return state;
}
