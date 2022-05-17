#include "Buzzer.h"

#include "Peripheral.h"
#include "Arduino.h"

// Constructor sets default parameters
Buzzer::Buzzer(int loud_pin, int quiet_pin){
    io_pin = loud_pin;
    this->quiet_pin = quiet_pin;
    // Default parameters
    tone_freq = 400;
    timeout = 1.2e+6;
}

// Setter method for tone_freq
void Buzzer::setTone(int tone_freq){
    this->tone_freq = tone_freq;
}

// Setter method for timeout with an upper limit of 20 minutes
void Buzzer::setTimeout(unsigned long timeout){
    if(timeout > 1.2e+6){ // 1.2e+6 millis = 20 minutes
        Serial.println("Max of 20 minutes exceeded, setting timeout to 20 minutes");
        this->timeout = 1.2e+6;
    }else{
        this->timeout = timeout;
    }
}

// Getter method for timeout
unsigned long Buzzer::getTimeout(){
    return timeout;
}

// Plays buzzer for a set duration with the option to be played quietly (off by default)
void Buzzer::pulse(unsigned long duration, bool is_quiet){
    stop(); // ensure buzzer is not still on
    int pin;
    if(is_quiet){pin = quiet_pin;}else{pin = io_pin;}
    duration = constrain(duration, 1, 1.2e+6); // duration should never be longer than 20 minutes
    tone(pin, tone_freq, duration);
}

// Play buzzer until the absolute upper limit set by timeout (<=20 minutes)
// allows option to be played quietly (off by default)
void Buzzer::start(bool is_quiet){
    stop();
    int pin;
    if(is_quiet){pin = quiet_pin;}else{pin = io_pin;}
    tone(pin, tone_freq, timeout); 
}

// Stops any tone being played on either the load or quiet pin
void Buzzer::stop(){
    noTone(io_pin);
    noTone(quiet_pin);
    state = false;
}
