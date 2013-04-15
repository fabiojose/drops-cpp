#ifndef THREAD_UTIL_H_INCLUDED
#define THREAD_UTIL_H_INCLUDED

#include "thread.h"

//include by OS
#ifdef LINUX

#else
  #include <process.h>
  #include <windows.h>
#endif // LINUX

class ThreadUtil{

    public:
        ThreadUtil();
        virtual ~ThreadUtil();

        static void wait(Thread* thread){

            //implementation by OS
            #ifdef LINUX

            #else
              WaitForSingleObject((HANDLE)thread->getHandle(), INFINITE);
            #endif // LINUX

        }
};

#endif // THREAD_UTIL_H_INCLUDED
