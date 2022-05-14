#include "Solenoid.h"

#include "Peripheral.h"
#include "Arduino.h"

Solenoid::Solenoid(int output_pin){
    io_pin = output_pin;
    enabled = true;
    pinMode(io_pin, OUTPUT);
}

void Solenoid::open(unsigned long duration){ 
  this->duration = duration; // Set the timer for re-closing the solenoid at this moment
  state = true; // true = open, false = closed, used as a flag to let update() know to keep running
  digitalWrite(io_pin, state);
  start_time = millis();
}

void Solenoid::update(){
  if(state and (millis() - start_time) >= duration){ // Close when the timer has been reached if the solenoid is open
    close();
  }
}

void Solenoid::close(){
  state = false;
  digitalWrite(io_pin, state);
}
