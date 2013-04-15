#include "exception-util.h"

ExceptionUtil::ExceptionUtil(){

}

ExceptionUtil::~ExceptionUtil(){
}

char* ExceptionUtil::exception(char* message){
    char* _result = new char[MAX_EXP_MSG_LENGTH];
    char _code[20];

    strcpy(_result, message);

    int _errorno = 0;

    //piece of code by OS
    #ifdef _WIN32
        _errorno = GetLastError();
    #else
        _errorno = errno;
    #endif

    sprintf(_code, " - %d", _errorno);
    strcat(_result, _code);

    return _result;
}
