#include "formatter.h"

Formatter::Formatter(){

}

Formatter::~Formatter(){

}

void Formatter::setPattern(char* pattern){
    this->pattern = pattern;
}

char* Formatter::getPattern(){
    return pattern;
}

void Formatter::put(string property, string value){
    properties.put(property, value);
}

string Formatter::get(string property){
    return properties.get(property);
}
