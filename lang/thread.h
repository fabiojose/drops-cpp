/**
 *
 * Threads.
 * fabiojose@gmail.com
 */

#ifndef THREAD_H_INCLUDED
#define THREAD_H_INCLUDED

#include <iostream>
using namespace std;

#ifdef LINUX

#else
  #include <process.h>
#endif // LINUX

class Runnable{

    public:
        Runnable(){

        }

        ~Runnable(){

        }

        virtual void run() = 0;
};

class Thread:public Runnable {

    private:
        long unsigned int handle;
        Runnable* target;

    public:
        Thread(){
            target = NULL;
        }

        Thread(Runnable* target){
            this->target = target;
        }

        ~Thread(){

        }

        long unsigned int getHandle(){
            return handle;
        }

        //the thread runner by OS
        #ifdef LINUX

        #else
          static unsigned __stdcall runner(void* data){

              Thread* _thread = (Thread*)data;
              _thread->run();

          }
        #endif // LINUX

        void start(){

            //the thread beginner by OS
            #ifdef LINUX

            #else
              handle = _beginthreadex( NULL, 0, Thread::runner, this, 0, NULL);
            #endif // LINUX

        }

        void run(){

            cout<<"Running the target.";
            if(NULL!= target){

                target->run();

            }

        }

};

class UtilThread{

    public:
        UtilThread(){

        }

        ~UtilThread(){

        }

        static void wait(Thread* thread){

            #ifdef LINUX

            #else
              WaitForSingleObject((HANDLE)thread->getHandle(), INFINITE);
            #endif // LINUX

        }
};

#endif // THREAD_H_INCLUDED
