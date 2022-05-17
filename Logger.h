/*
The Logger class is in charge of storing events and the time they occured at.
This can be used by the user or maintenence to troubleshoot issues or to find out
if there have been failed attempts to access the system in their absence.
*/

#ifndef LOGGER_H
#define LOGGER_H

#include "Arduino.h"

// max size of log before old entries are pushed out of queue
// can be made smaller to save memory as timestamps are all longs
#define LOGGER_ARRAY_LEN 30

// enumeration used to keep track of event types
// declared as enum CLASS to prevent potential clashes with global namespace
enum class Event{
  nullEvent,
  alarmReset,
  failedLogin,
  successfulLogin,
  magswitchTrigger,
  pirTrigger,
  solenoidOpened,
  solenoidClosed,
  alarmTriggered,
  pinChanged
};

// EventTime struct used to keep track of an event with a respective timestamp
// an array of these objects is stored in the logger
struct EventTime{
    Event event_type;
    long timestamp;
};

class Logger{
  private:
    EventTime events[LOGGER_ARRAY_LEN];
    void pushQueue();
  public:
    Logger();
    void logEvent(Event event_type);
    void printLog();
};

#endif // LOGGER_H

