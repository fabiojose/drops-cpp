#ifndef FORMATTER_H_INCLUDED
#define FORMATTER_H_INCLUDED

#include "log-record.h"
#include "../map.h"

/**
 * Abstract Formatter.
 * fabiojose@gmail.com
 */
class Formatter {

    private:
        char* pattern;
        HashMap<string, string> properties;

    public:
        Formatter();
        virtual ~Formatter();

        void setPattern(char* pattern);
        char* getPattern();

        void put(string, string);
        string get(string);

        virtual char* format(LogRecord* record) = 0;

};

#endif // FORMATTER_H_INCLUDED
