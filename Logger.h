#ifndef LOGGER_H
#define LOGGER_H

#include "Arduino.h"

struct EventTime{
    int event_type;
    long timestamp;
};

class Logger{
  private:
    EventTime events[50];
    void pushQueue();
  public:
    Logger();
    void logEvent(int event_type);
    void printLog();
};

#endif // LOGGER_H

