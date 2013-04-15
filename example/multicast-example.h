#ifndef MULTICAST_EXAMPLE_H_INCLUDED
#define MULTICAST_EXAMPLE_H_INCLUDED

#include <iostream>
using namespace std;

#include <stdlib.h>

#include "../drops.h"
#include "../net/msocket.h"
#include "../lang/thread.h"

#include "example.h"

class MulticastExample: public Example {

    public:
        MulticastExample();
        virtual ~MulticastExample();

        int execute(int, char*[]);

};

#endif // MULTICAST_EXAMPLE_H_INCLUDED
