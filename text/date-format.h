#ifndef DATE_FORMAT_H_INCLUDED
#define DATE_FORMAT_H_INCLUDED

#include <ctime>
#include <iostream>
using namespace std;

#include <string.h>

#include "format.h"
#include "../util/date.h"
#include "../util.h"

#define ____DATE_DEFAULT_PATTERN "%d/%m/%Y %H:%M:%S";

class DateFormat: public Format {

    public:
        DateFormat();
        virtual ~DateFormat();

        char* format(Date* date, char* pattern);
};

#endif // DATE_FORMAT_H_INCLUDED
