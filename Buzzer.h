#ifndef BUZZER_H
#define BUZZER_H

#include "Peripheral.h"
#include "Arduino.h"

class Buzzer : public Peripheral{
  private:
    static const long TIMEOUT = 1.2e+6;
    int quiet_pin;
    int tone_freq;
  public:
    Buzzer(int loud_pin, int quiet_pin);
    void setTone(int tone_freq);
    void pulse(unsigned long duration, bool is_quiet = false);
    void start(bool is_quiet = false);
    void stop();
};

#endif // BUZZER_H
