#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Arduino.h"

#include "KeyPad.h"
#include "FacialRecognition.h"
#include "PinHandler.h"
#include "Logger.h"
#include "LED.h"
#include "Buzzer.h"
#include "Solenoid.h"
#include "MagneticSwitch.h"
#include "PIR.h"

class Controller{
  private:
    int system_state;
    KeyPad keypad;
    FacialRecognition facial_recognition;
    PinHandler pin_handler;
    Logger logger;
    LED armed_LED, triggered_LED;
    Buzzer buzzer;
    Solenoid solenoid;
    MagneticSwitch magnetic_switch;
    PIR pir;

    void armAlarm();
    void triggerAlarm();
    void resetAlarm();
    void sendAlert(int event_type);
  public:
    Controller(int armed_LED_pin, int triggered_LED_pin, int loud_buzz_pin,
      int quiet_buzz_pin, int solenoid_pin, int magswitch_pin, int PIR_pin);
    void processSysState();
    void updateTimers();
};

#endif // CONTROLLER_H
