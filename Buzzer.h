/*
 * The Buzzer Peripheral class stores the tone and timeout of the buzzer.
 * This class makes primary use of the tone function with some
 * additional internal logic. The buzzer tone should never exceed the 
 * max timeout of 20 minutes. The buzzer class also allows for the use
 * of a quiet pin which runs the tone signal through a resistor before
 * reaching the buzzer.
 */


#ifndef BUZZER_H
#define BUZZER_H

#include "Peripheral.h"
#include "Arduino.h"

class Buzzer : public Peripheral{
  private:
    unsigned long timeout;
    int quiet_pin;
    int tone_freq;
  public:
    Buzzer(int loud_pin, int quiet_pin);
    void setTimeout(unsigned long timeout);
    unsigned long getTimeout();
    void setTone(int tone_freq);
    void pulse(unsigned long duration, bool is_quiet = false);
    void start(bool is_quiet = false);
    void stop();
};

#endif // BUZZER_H
