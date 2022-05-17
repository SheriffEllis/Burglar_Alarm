#include "Logger.h"

#include "Arduino.h"

// fill the events array with nullEvents with timestamps of 0
Logger::Logger(){
    for (int i = 0; i < LOGGER_ARRAY_LEN; i++)
    {
        events[i].event_type = Event::nullEvent;
        events[i].timestamp = 0;
    }    
}

// move everything in the events array +1 index
// set index 0 to nullEvent and timestamp 0
// removes element at end of queue
void Logger::pushQueue(){
    for (int i = LOGGER_ARRAY_LEN-1; i > 0; i--)
    {
        events[i] = events[i-1];
    }
    events[0].event_type = Event::nullEvent;
    events[0].timestamp = 0;
}

// adds a new event to the events array, using the current time as the timestamp
void Logger::logEvent(Event event_type){
    pushQueue();
    events[0].event_type = event_type;
    events[0].timestamp = millis();
}

// prints out the events array in a user-readable format
void Logger::printLog(){
    Serial.println("\nSYSTEM EVENT LOG:");
    Serial.println("Time (sec ago)\t: Event");
    Serial.println("--------------------------------------");
    for (int i = 0; (i < LOGGER_ARRAY_LEN) and (events[i].event_type != Event::nullEvent); i++)
    {
        Serial.print((millis() - events[i].timestamp)/1000); // Calculate how long ago
        Serial.print("\t\t: ");
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

        case Event::pinChanged:
            Serial.println("Pin Changed");
            break;

        default:
            Serial.println("Invalid Event");
            break;
        }
    }
    Serial.println();
}
