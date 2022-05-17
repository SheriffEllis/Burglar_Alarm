#ifndef LOGGER_H
#define LOGGER_H

#define LOGGER_ARRAY_LEN 10 // TODO return to original size

#include "Arduino.h"

enum class Event{
  nullEvent,
  alarmReset,
  failedLogin,
  successfulLogin,
  magswitchTrigger,
  pirTrigger,
  solenoidOpened,
  solenoidClosed,
  alarmTriggered
};

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

