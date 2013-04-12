#include "appender.h"

Appender::Appender(){
    formatter = NULL;
}

Appender::~Appender(){
    if(NULL!= formatter){
        delete formatter;
    }
}

void Appender::setFormatter(Formatter* formatter){
    this->formatter = formatter;
}

Formatter* Appender::getFormatter(){
    return formatter;
}

void Appender::put(string key, string value){
    properties.put(key, value);
}

string Appender::get(string key){
    string _result("");

    if(properties.containsKey(key)){
        _result = properties.get(key);
    }

    return _result;
}
