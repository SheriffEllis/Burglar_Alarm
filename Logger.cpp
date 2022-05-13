#include "Logger.h"

#include "Arduino.h"

Logger::Logger(){
    //Fill the array with event_type 0 and timestamp 0
    for (int i = 0; i < LOGGER_ARRAY_LEN; i++)
    {
        events[i].event_type = 0;
        events[i].timestamp = 0;
    }    
}

void Logger::pushQueue(){
    //Move everything in array +1, set position 0 to event_type and timestamp 0, remove element at end of queue
    for (int i = LOGGER_ARRAY_LEN-1; i > 0; i--)
    {
        events[i] = events[i-1];
    }
    events[0].event_type = 0;
    events[0].timestamp = 0;
}

void Logger::logEvent(int event_type){
    pushQueue();
    events[0].event_type = event_type;
    events[0].timestamp = millis();
}

void Logger::printLog(){
    Serial.println("Timestamp(s)\t: Event");
    Serial.println("--------------------------------------");
    for (int i = 0; i < LOGGER_ARRAY_LEN; i++)
    {
        Serial.print(events[i].timestamp/1000);
        Serial.print("\t\t: ");
        //TODO complete event list
        switch (events[i].event_type)
        {
        case 0:
            Serial.println("Null Event");
            break;

        case 1:
            Serial.println("Insert Event 1");
            break;

        case 2:
            Serial.println("Insert Event 2");
            break;

        case 3:
            Serial.println("Insert Event 3");
            break;
        
        default:
            Serial.println("Invalid Event");
            break;
        }
    }
    
}
