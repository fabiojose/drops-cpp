
#include <iostream>
using namespace std;

#include <stdlib.h>

#include "s.h"
#include "lang/thread.h"

class CounterThread: public Runnable {

    public:
        CounterThread(){

        }

        ~CounterThread(){

        }

        void run(){

            for(int _counter = 0; _counter < 1000; _counter++){

                cout<<"."<<_counter;

            }
        }

};

int main(int argc, char* argv[]){

    cout<<"OS: "<<S::runningOn()<<endl;

    //using a Runnable target.
    Runnable* _tcounter = new CounterThread();

    //using a base class Thread to run the target
    Thread* _thread     = new Thread(_tcounter);

    //start de thread
    _thread->start();

    //waiting util thread´s run ends
    UtilThread::wait(_thread);

    delete _tcounter;
    delete _thread;

    return EXIT_SUCCESS;
}
