#ifndef LEVEL_FORMAT_H
#define LEVEL_FORMAT_H

#include <iostream>
using namespace std;

#include <string.h>

#include "format.h"
#include "../util/logging/level.h"

class LevelFormat: Format {
    public:
        LevelFormat();
        virtual ~LevelFormat();

        char* format(Level);
        Level parse(char*);
};

#endif // LEVEL_FORMAT_H
