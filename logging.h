/**
 * Logging.
 * fabiojose@gmail.com
 */
#ifndef LOGGING_H_INCLUDED
  #define LOGGING_H_INCLUDED
#endif

#include <iostream>
using namespace std;

#include "properties.h"

#define LOG4CPP_PROPERTIES "log4cpp.properties"
Properties* ____LOG4CPP = new Properties();
class Logger {

    private:

        static void setup(){
            if(!____LOG4CPP->isEmpty()){

                fstream _stream(LOG4CPP_PROPERTIES);

                ____LOG4CPP->load(_stream);

                _stream.close();
            }
        }

    public:
        Logger(){

        }

        ~Logger(){

        }

        static Logger* getLogger(string name){
            setup();
        }

        virtual void debug(string) = 0;
        virtual void error(string) = 0;
        virtual void fatal(string) = 0;
        virtual void info(string)  = 0;
        virtual void warn(string)  = 0;
        virtual void trace(string) = 0;
};

class LogRecord {

    public:
        LogRecord(){

        }

        ~LogRecord(){

        }
};

class Handler {

    public:
        Handler(){

        }

        ~Handler(){

        }

        virtual void publish(LogRecord* record) = 0;
};

class ConsoleHandler: public Handler {

};

class FileHandler: public Handler {

};

class Formatter {

    public:
        Formatter(){

        }

        ~Formatter(){

        }

        virtual string format(LogRecord* record) = 0;

};
