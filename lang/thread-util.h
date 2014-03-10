#ifndef THREAD_UTIL_H_INCLUDED
#define THREAD_UTIL_H_INCLUDED

#include "thread.h"

//include by OS
#ifdef _WIN32
  #include <process.h>
  #include <windows.h>
#else

#endif // LINUX

class ThreadUtil{

    public:
        ThreadUtil();
        virtual ~ThreadUtil();

        static void wait(Thread* thread){

            //implementation by OS
            #ifdef _WIN32
              WaitForSingleObject((HANDLE)thread->getHandle(), INFINITE);
            #else

            #endif // LINUX

        }
};

#endif // THREAD_UTIL_H_INCLUDED
