#ifndef SIMPLE_FORMATTER_H
#define SIMPLE_FORMATTER_H

#include "formatter.h"
#include "../../text/date-format.h"
#include "../../text/level-format.h"
#include "../date.h"

/**
 * SimpleFormatter to format log messages.
 * fabiojose@gmail.com
 */
class SimpleFormatter: public Formatter {

    private:
        DateFormat* formatt;
        LevelFormat* levelFormat;

    protected:
        DateFormat* getFormatt();
        LevelFormat* getLevelFormat();

    public:
        SimpleFormatter();
        virtual ~SimpleFormatter();

        char* format(LogRecord* record);
};

#endif // SIMPLE_FORMATTER_H
