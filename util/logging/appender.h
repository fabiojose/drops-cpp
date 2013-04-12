#ifndef APPENDER_H_INCLUDED
#define APPENDER_H_INCLUDED

#include "formatter.h"
#include "../map.h"

/**
 * The Abstract Appender.
 * fabiojose@gmail.com
 */
class Appender {

    private:
        Formatter* formatter;
        HashMap<string, string> properties;

    public:
        Appender();
        virtual ~Appender();

        void setFormatter(Formatter* formatter);
        Formatter* getFormatter();

        /**
        * Put properties on the appender.
        */
        void put(string key, string value);

        /**
        * Get properties from the appender.
        */
        string get(string key);

        virtual void publish(LogRecord* record) = 0;
};

#endif // APPENDER_H_INCLUDED
