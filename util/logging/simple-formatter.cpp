#include "simple-formatter.h"

//protected
DateFormat* SimpleFormatter::getFormatt(){
    if(NULL== formatt){
        formatt = new DateFormat();
    }
}

LevelFormat* SimpleFormatter::getLevelFormat(){
    if(NULL== levelFormat){
        levelFormat = new LevelFormat();
    }
}

//public
SimpleFormatter::SimpleFormatter(){
    formatt     = NULL;
    levelFormat = NULL;
}

SimpleFormatter::~SimpleFormatter(){
    if(NULL!= formatt){
        delete formatt;
    }

    if(NULL!= levelFormat){
        delete levelFormat;
    }
}

char* SimpleFormatter::format(LogRecord* record){

    //the timestamp format
    Date _now;
    char* _snow = getFormatt()->format(&_now, getPattern());

    char* _level  = getLevelFormat()->format(record->getLevel());
    int _length   = strlen(_snow) + strlen(_level) + strlen(record->getLogger()) + strlen(record->getMessage()) + 3;
    char* _result = new char[_length];

    //the log message format
    strcpy(_result, _snow);
    strcat(_result, " ");
    strcat(_result, _level);
    strcat(_result, " ");
    strcat(_result, record->getLogger());
    strcat(_result, " ");
    strcat(_result, record->getMessage());

    return _result;
}
