#ifndef THREAD_H_INCLUDED
#define THREAD_H_INCLUDED

#include <stddef.h>

//include by OS
#ifdef _WIN32
  #include <process.h>
#else

#endif // _WIN32

#include "runnable.h"

/**
 * Thread.
 * fabiojose@gmail.com
 */
class Thread:public Runnable {

    private:
        long unsigned int handle;
        Runnable* target;

    public:
        Thread();
        Thread(Runnable* target);
        virtual ~Thread();

        long unsigned int getHandle();

        //the thread runner by OS
        #ifdef _WIN32
          static unsigned __stdcall runner(void* data){

              Thread* _thread = (Thread*)data;
              _thread->run();

          }
        #else

        #endif // _WIN32

        void start();
        void run();
};

#endif // THREAD_H_INCLUDED
