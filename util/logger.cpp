#include "logger.h"

HashMap<string, Logger*> ____LOG4CPP_LOGGERS;

Logger::Logger(){
    appender = NULL;
}

Logger::~Logger(){
    if(NULL!= appender){
        delete appender;
    }
}

void Logger::setLevel(Level onLevel){
    this->onLevel = onLevel;
}

Level Logger::getLevel(){
    return onLevel;
}

void Logger::setAppender(Appender* appender){
    this->appender = appender;
}

Appender* Logger::getAppender(){
    return appender;
}

void Logger::log(Level l, string message){
    if(l >= getLevel()){
        LogRecord _record(message);
        getAppender()->publish(&_record);
    }
}

void Logger::trace(string message){
    log(TRACE, message);
}

void Logger::debug(string message){
    log(DEBUG, message);
}

void Logger::info(string message){
    log(INFO, message);
}

void Logger::warn(string message){
    log(WARN, message);
}

void Logger::error(string message){
    log(ERROR, message);
}

void Logger::fatal(string message){
    log(FATAL, message);
}
