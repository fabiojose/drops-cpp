#ifndef LOGGER_H
#define LOGGER_H

#include <string>
using namespace std;

#include "appender.h"
#include "level.h"

#include "logger-helper.h"

class Logger{

    private:
        Appender* appender;
        Level onLevel;

    public:
        Logger();
        virtual ~Logger();

        static Logger* getLogger(string name){

        }

        static Logger* getRoot(){
            //return getLogger(LOG4CPP_ROOT_LOGGER);
        }

        void setLevel(Level onLevel);
        Level getLevel();

        void setAppender(Appender* appender);
        Appender* getAppender();

        void log(Level l, string message);
        void trace(string message);
        void debug(string message);
        void info(string message);
        void warn(string message);
        void error(string message);
        void fatal(string message);
};

#endif // LOGGER_H
