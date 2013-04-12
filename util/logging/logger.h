#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <set>
using namespace std;

#include "appender.h"
#include "level.h"
#include "../map.h"

/**
 * The Logger.
 * fabiojose@gmail.com
 */
class Logger{

    private:
        char* name;
        set<Appender*> appender;

        Level onLevel;
        HashMap<string, string> properties;

    public:
        Logger();
        virtual ~Logger();

        void setName(char*);
        char* getName();

        void setLevel(Level onLevel);
        Level getLevel();

        void add(Appender* appender);
        set<Appender*> getAppender();

        void put(string, string);
        string get(string);

        void log(Level l, char* message);
        void trace(char* message);
        void debug(char* message);
        void info(char* message);
        void warn(char* message);
        void error(char* message);
        void fatal(char* message);
};

#endif // LOGGER_H
