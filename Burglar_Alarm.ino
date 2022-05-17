#include "Arduino.h"
#include "Controller.h"

#define ARMED_LED_PIN 10
#define TRIGGERED_LED_PIN 10
#define LOUD_BUZZ_PIN 9
#define QUIET_BUZZ_PIN 9
#define SOLENOID_PIN 8
#define MAGSWITCH_PIN 12
#define PIR_PIN 11

Controller controller(ARMED_LED_PIN, TRIGGERED_LED_PIN, LOUD_BUZZ_PIN, QUIET_BUZZ_PIN, SOLENOID_PIN, MAGSWITCH_PIN, PIR_PIN);

void setup(){
  Serial.begin(9600);
  Serial.println("Initialised");
  controller.calibrate(30);
  Serial.println("The default PIN is 1234");
}

void loop(){
  controller.processSysState();
  controller.updateSensors();
}
