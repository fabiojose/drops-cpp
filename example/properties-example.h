#ifndef PROPERTIES_EXAMPLE_H_INCLUDED
#define PROPERTIES_EXAMPLE_H_INCLUDED

#include <stdlib.h>
#include <iostream>
using namespace std;

#include "../util/properties.h"

#include "example.h"

class PropertiesExample: public Example {

    public:
        PropertiesExample();
        virtual ~PropertiesExample();

        int execute(int, char*[]);

};

#endif // PROPERTIES_EXAMPLE_H_INCLUDED
