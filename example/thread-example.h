#ifndef THREAD_EXAMPLE_H_INCLUDED
#define THREAD_EXAMPLE_H_INCLUDED

#include <iostream>
using namespace std;

#include <stdlib.h>

#include "../drops.h"
#include "../lang/thread.h"
#include "../lang/thread-util.h"

#include "example.h"

class ThreadExample: public Example {

    public:
        ThreadExample();
        virtual ~ThreadExample();

        int execute(int, char*[]);

};

#endif // THREAD_EXAMPLE_H_INCLUDED
