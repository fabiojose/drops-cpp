/**
 *
 * Threads.
 *
 */

#include <iostream>
using namespace std;

class ThreadUtil{

    public:
        ThreadUtil(){

        }

        ~ThreadUtil(){

        }

        static void* newArgument(int theSize){
            #ifdef WINDOWS
                return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, theSize);
            #else
                throw unsuppex;
            #endif
        }
};

class Thread {

    public:
        Thread(){

        }

        ~Thread(){

        }

        void start(){

        }

        void run(){

        }

};
