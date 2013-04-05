/**
 * Logging.
 * fabiojose@gmail.com
 */
#ifndef LOGGING_H_INCLUDED
#define LOGGING_H_INCLUDED

#include <set>
#include <iostream>
using namespace std;

#include "properties.h"
#include "../strategy.h"

#define LOG4CPP_PROPERTIES  "log4cpp.properties"
#define LOG4CPP_ROOT_LOGGER "ROOT"

const string LOG4CPP_LOGGER    = "log4cpp.logger.";
const string LOG4CPP_APPENDER  = "log4cpp.appender.";
const string LOG4CPP_FORMATTER = "log4cpp.formatter.";

/**
 * TRACE < DEBUG < INFO < WARN < ERROR < FATAL
 */
enum Level {

    TRACE,
    DEBUG,
    INFO,
    WARN,
    ERROR,
    FATAL

};

class UtilLogging {

    private:
        static string nameOf(string key, string prefix){
            string _result("");

            if(UtilString::startsWith(key, prefix)){
                _result = key.substr(prefix.size(), key.size());

                size_t _index = _result.find_first_of(".");
                if(string::npos != _index){
                    _result = _result.substr(0, _index);
                }
            }

            return _result;
        }

    public:
        UtilLogging(){

        }

        ~UtilLogging(){

        }

        static string loggerOf(string key){
            return nameOf(key, LOG4CPP_LOGGER);
        }

        static string appenderOf(string key){
            return nameOf(key, LOG4CPP_APPENDER);
        }

        static string formatterOf(string key){
            return nameOf(key, LOG4CPP_FORMATTER);
        }

        static set<string> nameOf(Map<string, string>* properties, string prefix){
            set<string> _result;

            set<string> _keys = properties->keySet();
            for(set<string>::iterator _entry = _keys.begin(); _entry != _keys.end(); ++_entry){

                _result.insert(nameOf((string)*_entry, prefix));

            }

            return _result;
        }
};

Properties* ____LOG4CPP = new Properties();
class Logger {

    private:

        static void load(){
            if(____LOG4CPP->isEmpty()){

                fstream _stream(LOG4CPP_PROPERTIES);

                ____LOG4CPP->load(_stream);

                _stream.close();
            }
        }

        static void setup(){
            load();

            Strategy<string, Map<string, string>*>* _strategy = new PropertiesStrategy(____LOG4CPP);

            //0 - collect the loggers.
            Map<string, string>* _ploggers = _strategy->execute(LOG4CPP_LOGGER);
            set<string> _loggers = UtilLogging::nameOf(_ploggers, LOG4CPP_LOGGER);

            //1 - collect the appenders.
            Map<string, string>* _pappenders = _strategy->execute(LOG4CPP_APPENDER);
            set<string> _appenders = UtilLogging::nameOf(_pappenders, LOG4CPP_APPENDER);

            //2 - collect the formatters.
            Map<string, string>* _pformatters = _strategy->execute(LOG4CPP_FORMATTER);
            set<string> _formatters = UtilLogging::nameOf(_pformatters, LOG4CPP_FORMATTER);

            set<string> _fkeys = _pformatters->keySet();
            for(set<string>::iterator _entry = _fkeys.begin(); _entry != _fkeys.end(); ++_entry){


            }
            //3 - validate the formatters


            //3 - connect appenders and formatters.

            //4 - connect loggers and appenders.

            delete _strategy;
            delete _ploggers;
            delete _pappenders;
            delete _pformatters;
        }

    public:
        Logger(){

        }

        ~Logger(){

        }

        static Logger* getLogger(string name){
            setup();

        }

        static Logger* getRoot(){
            setup();
            return getLogger(LOG4CPP_ROOT_LOGGER);
        }

        virtual void trace(string) = 0;
        virtual void debug(string) = 0;
        virtual void info(string)  = 0;
        virtual void warn(string)  = 0;
        virtual void error(string) = 0;
        virtual void fatal(string) = 0;

        virtual void log(Level, string) = 0;

};
Map<string, Logger*>* ____LOG4CPP_LOGGERS = new HashMap<string, Logger*>();

class DefaultLogger: public Logger{

    public:
        DefaultLogger(){

        }

        ~DefaultLogger(){

        }

        void trace(string message){

        }

        void debug(string message){

        }

        void info(string message){

        }

        void warn(string message){

        }

        void error(string message){

        }

        void fatal(string message){

        }

        void log(Level l, string message){

        }
};

class LogRecord {

    public:
        LogRecord(){

        }

        ~LogRecord(){

        }
};

class Appender {

    public:
        Appender(){

        }

        ~Appender(){

        }

        virtual void publish(LogRecord* record) = 0;
};

class ConsoleAppender: public Appender {

};

class FileAppender: public Appender {

};

class Formatter {

    public:
        Formatter(){

        }

        ~Formatter(){

        }

        virtual string format(LogRecord* record) = 0;

};

class SimpleFormatter: public Formatter {

    public:
        SimpleFormatter(){

        }

        ~SimpleFormatter(){

        }

        string format(LogRecord* record){

        }

};

#endif //LOGGING_H_INCLUDED
