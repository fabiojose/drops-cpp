#ifndef MAP_EXAMPLE_H_INCLUDED
#define MAP_EXAMPLE_H_INCLUDED

#include <iostream>
#include <map>
using namespace std;

#include <stdlib.h>
#include "../util/map.h"

#include "example.h"

class MapExample:public Example{

    public:
        MapExample();
        virtual ~MapExample();

        int execute(int, char*[]);

};

#endif // MAP_EXAMPLE_H_INCLUDED
