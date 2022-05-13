#ifndef BUZZER_H
#define BUZZER_H

#include "Peripheral.h"
#include "Arduino.h"

class Buzzer : public Peripheral{
  private:
    static const long TIMEOUT = 20000;
    int quiet_pin;
    int tone_freq;
    int pulse_freq;
    long duration;
    long start_time;
  public:
    Buzzer(int loud_pin, int _quiet_pin);
    void setTone(int tone_freq);
    void setPulseFreq(int pulse_freq);
    void pulsate(long duration, bool is_quiet);
    void stop();
    void update();
};

#endif // BUZZER_H
