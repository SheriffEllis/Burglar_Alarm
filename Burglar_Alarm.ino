#include "Logger.h"

Logger logger;

void setup(){
  Serial.begin(9600);
  logger.printLog();
  Serial.println("-------------------");
  logger.logEvent(1);
  delay(1000);
  logger.logEvent(2);
  delay(1500);
  logger.logEvent(3);
  logger.printLog();
}

void loop(){

}
