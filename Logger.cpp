#include "Logger.h"

#include "Arduino.h"

Logger::Logger(){
    //Fill the array with event_type 0 and timestamp 0
    for (int i = 0; i < LOGGER_ARRAY_LEN; i++)
    {
        events[i].event_type = Event::nullEvent;
        events[i].timestamp = 0;
    }    
}

void Logger::pushQueue(){
    //Move everything in array +1, set position 0 to event_type and timestamp 0, remove element at end of queue
    for (int i = LOGGER_ARRAY_LEN-1; i > 0; i--)
    {
        events[i] = events[i-1];
    }
    events[0].event_type = Event::nullEvent;
    events[0].timestamp = 0;
}

void Logger::logEvent(Event event_type){
    pushQueue();
    events[0].event_type = event_type;
    events[0].timestamp = millis();
}

void Logger::printLog(){
    Serial.println("\nSYSTEM EVENT LOG:");
    Serial.println("Time (sec ago)\t: Event");
    Serial.println("--------------------------------------");
    for (int i = 0; (i < LOGGER_ARRAY_LEN) and (events[i].event_type != Event::nullEvent); i++)
    {
        Serial.print((millis() - events[i].timestamp)/1000); // Calculate how long ago
        Serial.print("\t\t: ");
        //TODO complete event list
        switch (events[i].event_type)
        {
        case Event::alarmReset:
            Serial.println("Alarm Reset");
            break;

        case Event::failedLogin:
            Serial.println("Failed Login");
            break;

        case Event::successfulLogin:
            Serial.println("Successful Login");
            break;

        case Event::magswitchTrigger:
            Serial.println("Magnetic Switch Triggered");
            break;

        case Event::pirTrigger:
            Serial.println("PIR Sensor Triggered");
            break;

        case Event::solenoidOpened:
            Serial.println("Door Solenoid Opened");
            break;

        case Event::solenoidClosed:
            Serial.println("Door Solenoid Closed");
            break;
        
        case Event::alarmTriggered:
            Serial.println("Alarm Triggered");
            break;

        default:
            Serial.println("Invalid Event");
            break;
        }
    }
    Serial.println();
}
