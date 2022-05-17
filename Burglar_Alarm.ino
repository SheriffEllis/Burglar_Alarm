#include "Arduino.h"
#include "Controller.h"

#define ARMED_LED_PIN 41
#define TRIGGERED_LED_PIN 45
#define LOUD_BUZZ_PIN 31
#define QUIET_BUZZ_PIN 52
#define SOLENOID_PIN 27
#define MAGSWITCH_PIN 35
#define PIR_PIN 25

// The controller class managed all sensors and actuators internally within the main loop
Controller controller(ARMED_LED_PIN, TRIGGERED_LED_PIN, LOUD_BUZZ_PIN, QUIET_BUZZ_PIN, SOLENOID_PIN, MAGSWITCH_PIN, PIR_PIN);

void setup(){
  Serial.begin(9600);
  Serial.println("Initialised");
  // Gives time for the PIR sensor to calibrate
  controller.calibrate(30);
  Serial.println("The default PIN is 1234");
}

void loop(){
  // Uses an internal system state variable to determine the logic of the system
  controller.processSysState();
  // Updates the state of sensors in the system
  controller.updateSensors();
}