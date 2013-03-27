/**
 *
 * Threads.
 *
 */

#include <iostream>
using namespace std;

class Thread {
    
    public:
        Thread(){
            cout<<"Constructor.";
        }
        
        ~Thread(){
            cout<<"Destructor.";
        }
        
        void start(){
            
        }
        
        void run(){
            cout<<"Thread running.";
        }
    
};
