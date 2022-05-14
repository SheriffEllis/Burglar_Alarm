#include "Arduino.h"
#include "Controller.h"

#define ARMED_LED_PIN 12
#define TRIGGERED_LED_PIN 11
#define LOUD_BUZZ_PIN 10
#define QUIET_BUZZ_PIN 9
#define SOLENOID_PIN 8
#define MAGSWITCH_PIN 7
#define PIR_PIN 6

Controller controller(ARMED_LED_PIN, TRIGGERED_LED_PIN, 
    LOUD_BUZZ_PIN, QUIET_BUZZ_PIN, SOLENOID_PIN, MAGSWITCH_PIN, PIR_PIN);

void setup(){
}

void loop(){
  controller.processSysState();
  controller.updateSensors();
  controller.updateTimers();
}
