#ifndef LOGGER_H
#define LOGGER_H

#define LOGGER_ARRAY_LEN 50

#include "Arduino.h"

struct EventTime{
    int event_type;
    long timestamp;
};

class Logger{
  private:
    EventTime events[LOGGER_ARRAY_LEN];
    void pushQueue();
  public:
    Logger();
    void logEvent(int event_type);
    void printLog();
};

#endif // LOGGER_H

