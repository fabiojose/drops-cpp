#include "level-format.h"

LevelFormat::LevelFormat(){

}

LevelFormat::~LevelFormat(){

}

char* LevelFormat::format(Level level){

    char* _result;

    if(TRACE == level){
        _result = "TRACE";

    } else if(DEBUG == level){
        _result = "DEBUG";

    } else if(INFO == level){
        _result = "INFO ";

    } else if(WARN == level){
        _result = "WARN ";

    } else if(ERROR == level){
        _result = "ERROR";

    } else if(FATAL == level){
        _result = "FATAL";
    }

    return _result;

}

Level LevelFormat::parse(char* level){

    Level _result;

    if(strcmp("TRACE", level)){
        _result = TRACE;

    } else if(strcmp("DEBUG", level)){
        _result = DEBUG;

    } else if(strcmp("INFO", level)){
        _result = INFO;

    } else if(strcmp("WARN", level)){
        _result = WARN;

    } else if(strcmp("ERROR", level)){
        _result = ERROR;

    } else if(strcmp("FATAL", level)){
        _result = FATAL;
    }

    return _result;
}
