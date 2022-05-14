#include "MagneticSwitch.h"
#include "LED.h"
#include "Solenoid.h"

LED led(10);
Solenoid solenoid(9);
MagneticSwitch magnetic_switch1(12);
MagneticSwitch magnetic_switch2(11);


void setup(){
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop(){
  led.setState(magnetic_switch1.measure());
  if(magnetic_switch2.measure()){
    solenoid.open(1000);
  }

  solenoid.update();
}
