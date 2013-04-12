#ifndef CONSOLE_APPENDER_H
#define CONSOLE_APPENDER_H

#include <iostream>
using namespace std;

#include "appender.h"
#include "log-record.h"

/**
 * The ConsoleAppender to log messages on the console.
 * fabiojose@gmail.com
 */
class ConsoleAppender:public Appender {
    public:
        ConsoleAppender();
        virtual ~ConsoleAppender();

        virtual void publish(LogRecord* record);
};

#endif // CONSOLE_APPENDER_H
