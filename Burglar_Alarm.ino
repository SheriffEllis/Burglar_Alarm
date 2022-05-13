#include "KeyPad.h"

int choice;
KeyPad keypad;

void setup(){
  Serial.begin(9600);
}

void loop(){
  
  String test[] = {"Choice0","Choice1","Choice2"};
  choice = keypad.getChoice(test, 2);
  Serial.print("The choice you input was ");
  Serial.println(choice);
  
}
