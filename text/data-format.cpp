#include "date-format.h"

DateFormat::DateFormat(){

}

DateFormat::~DateFormat(){

}

char* DateFormat::format(Date* date, char* pattern){
    char* _result  = new char[50];

    strftime(_result, 50, pattern, date->getRaw());

    return _result;
}
