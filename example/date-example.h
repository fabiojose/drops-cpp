#ifndef DATE_EXAMPLE_H_INCLUDED
#define DATE_EXAMPLE_H_INCLUDED

#include <stdlib.h>
#include <iostream>
using namespace std;

#include "../util/date.h"
#include "example.h"

class DateExample:public Example {

    public:
        DateExample();
        virtual ~DateExample();

        int execute(int, char*[]);

};

#endif // DATE_EXAMPLE_H_INCLUDED
