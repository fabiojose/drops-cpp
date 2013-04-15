
#include <iostream>
using namespace std;

#include <stdlib.h>

#include "example/date-example.h"
#include "example/logging-example.h"
#include "example/map-example.h"
#include "example/properties-example.h"
#include "example/thread-example.h"
#include "example/multicast-example.h"
#include "example/tcpsock-example.h"

int main(int argc, char* argv[]){
    int _result = EXIT_SUCCESS;

    Example* _example = new TcpsockExample();
    _result = _example->execute(argc, argv);

    delete _example;

    return _result;
}
