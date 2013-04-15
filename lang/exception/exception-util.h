#ifndef EXCEPTION_UTIL_H_INCLUDED
#define EXCEPTION_UTIL_H_INCLUDED

//include by OS
#ifdef _WIN32
  #include <windows.h>
#endif // _WIN32

#include <string.h>
#include <stdio.h>
#include <errno.h>

const int MAX_EXP_MSG_LENGTH = 256;

class ExceptionUtil {

    public:
        ExceptionUtil();
        ~ExceptionUtil();

        char* exception(char* message);
};

static ExceptionUtil exutil;

#endif // EXCEPTION_UTIL_H_INCLUDED
