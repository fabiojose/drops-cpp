#ifndef LOGGING_EXAMPLE_H_INCLUDED
#define LOGGING_EXAMPLE_H_INCLUDED

#include <stdlib.h>
#include <iostream>
using namespace std;

#include "../util/logging/logger-factory.h"
#include "../util/logging/logger.h"

#include "example.h"

class LoggingExample: public Example {

    public:
        LoggingExample();
        virtual ~LoggingExample();

        int execute(int, char*[]);

};

#endif // LOGGING_EXAMPLE_H_INCLUDED
