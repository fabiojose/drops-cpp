#include "thread.h"

Thread::Thread(){
    target = NULL;
}

Thread::Thread(Runnable* target){
    this->target = target;
}

Thread::~Thread(){

}

long unsigned int Thread::getHandle(){
    return handle;
}

void Thread::start(){

    //the thread beginner by OS
    #ifdef _WIN32
      handle = _beginthreadex( NULL, 0, Thread::runner, this, 0, NULL);
    #else

    #endif // _WIN32

}

void Thread::run(){
    if(NULL!= target){

        target->run();

    }
}
