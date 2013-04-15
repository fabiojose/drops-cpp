#ifndef TCPSOCK_EXAMPLE_H_INCLUDED
#define TCPSOCK_EXAMPLE_H_INCLUDED

#include <iostream>
using namespace std;

#include <string.h>

#include "../net/socket.h"

#include "example.h"

class TcpsockExample: public Example {

    public:
        TcpsockExample();
        ~TcpsockExample();

        int execute(int, char*[]);

};

#endif // TCPSOCK_EXAMPLE_H_INCLUDED
