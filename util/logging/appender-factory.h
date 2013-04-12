#ifndef APPENDER_FACTORY_H
#define APPENDER_FACTORY_H

#include "appender.h"

class AppenderFactory {
    public:
        AppenderFactory();
        virtual ~AppenderFactory();

        Appender* getAppender(char*);

};

#endif // APPENDER_FACTORY_H
