#ifndef FORMATTER_FACTORY_H
#define FORMATTER_FACTORY_H

#include "formatter.h"

class FormatterFactory {
    public:
        FormatterFactory();
        virtual ~FormatterFactory();

        Formatter* getFormatter(char*);

};

#endif // FORMATTER_FACTORY_H
