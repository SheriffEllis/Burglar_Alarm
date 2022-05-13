#include "Solenoid.h"

#include "Peripheral.h"
#include "Arduino.h"

Solenoid::Solenoid(int output_pin){
    io_pin = output_pin;
    enabled = true;
    pinMode(io_pin, OUTPUT);
}

void Solenoid::open(){ // Open only when the alarm system has been deactivated
  
  state = true; // True = open, False = closed
  digitalWrite(io_pin, state);
  
}

void Solenoid::update(long duration){
  
  duration = millis();
  durationRunning = true;

  if(durationRunning && (millis() >= 20000)){
    durationRunning = false;
    state = false;
    digitalWrite(io_pin, state);
  }
  
}

void Solenoid::close(){

  state = false;
  digitalWrite(io_pin, state);
  
}
