#include "KeyPad.h"

int choice;
KeyPad keypad;

void setup(){
  Serial.begin(9600);
}

void loop(){
  choice = keypad.getChoice("0 - Choice 0\n1 - Choice 1\n2 - Choice 2", 2);
  Serial.print("The choice you input was ");
  Serial.println(choice);
}
