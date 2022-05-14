#include "Arduino.h"
#include "Buzzer.h"

Buzzer buzzer(10, 9);

void setup(){
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop(){
  buzzer.pulse(1000);
  delay(500);
  buzzer.pulse(2000,true);
  delay(3000);
}
