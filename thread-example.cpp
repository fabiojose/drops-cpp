/**
 *
 * A Thread Example.
 *
 */

#include <iostream>
using namespace std;

#include "s.h"
#include "thread.h"

class CounterThread: public Thread {

    public:
        ~CounterThread(){

        }

        virtual void run();
};

void CounterThread::run(){
    cout<<"Starting the counter..."<<endl;

    for(int _counter = 0;_counter < 10; _counter++){
        cout<<_counter<<endl;
    }

    cout<<"Counter finished."<<endl;
}

int main(int argc, char* argv[]){
    cout<<"Thread Example."<<endl;

    try{
        CounterThread* _countert = new CounterThread();
        cout<<typeid(_countert).name()<<endl;
        cout<<"Runner method: "<<&CounterThread::run<<endl;
        _countert->setName("fabiojose-example");
        cout<<_countert<<endl;
        _countert->start();


        delete _countert;

        system("PAUSE");
    }catch(exception& e){
        cout<<e.what()<<endl;
    }
    return EXIT_SUCCESS;
}
