#include "logger.h"

Logger::Logger(){

}

Logger::~Logger(){

}

void Logger::setName(char* name){
    this->name = name;
}

char* Logger::getName(){
    return name;
}

void Logger::setLevel(Level onLevel){
    this->onLevel = onLevel;
}

Level Logger::getLevel(){
    return onLevel;
}

void Logger::add(Appender* appender){
    this->appender.insert(appender);
}

set<Appender*> Logger::getAppender(){
    return appender;
}

void Logger::put(string property, string value){
    properties.put(property, value);
}

string Logger::get(string property){
    return properties.get(property);
}

void Logger::log(Level l, char* message){
    if(l >= getLevel()){
        LogRecord _record(message, l, getName());

        set<Appender*> _appenders = getAppender();
        for(set<Appender*>::iterator _entry = _appenders.begin(); _entry != _appenders.end(); ++_entry){
            Appender* _appender = (Appender*)*_entry;
            _appender->publish(&_record);
        }
    }
}

void Logger::trace(char* message){
    log(TRACE, message);
}

void Logger::debug(char* message){
    log(DEBUG, message);
}

void Logger::info(char* message){
    log(INFO, message);
}

void Logger::warn(char* message){
    log(WARN, message);
}

void Logger::error(char* message){
    log(ERROR, message);
}

void Logger::fatal(char* message){
    log(FATAL, message);
}
