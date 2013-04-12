#include "date.h"

//private
struct tm* Date::when(long theTime){
    time_t _time;
    if(0== theTime){
        _time = time(0);
    } else {
        _time = theTime;
    }

    date = _time;

    return localtime(&_time);
}

void Date::load(struct tm* now){

    day    = now->tm_mday;
    month  = now->tm_mon  + 1;
    year   = now->tm_year + 1900;
    hour   = now->tm_hour;
    minute = now->tm_min;
    second = now->tm_sec;
}

//public
Date::Date(){
    tinfo = when(0);

    load(tinfo);
}

Date::Date(long date){
    tinfo = when(date);

    load(tinfo);
}

Date::~Date(){
    delete tinfo;
}

long Date::getTime(){
    return date;
}

bool Date::after(Date* when){
    return date > when->date;
}

bool Date::before(Date* when){
    return date < when->date;
}

bool Date::equals(void* o){
    bool _result = false;

    Date* _date = static_cast<Date*>(o);
    if(_date){
        _result = (date == _date->date);
    }

    return _result;
}

struct tm* Date::getRaw(){
    return tinfo;
};

string Date::toString(){
    string _result("");

    char _buffer[30];
    strftime(_buffer, 30, "%d/%m/%Y %H:%M:%S", this->getRaw());
    _result = _buffer;

    return _result;
}
