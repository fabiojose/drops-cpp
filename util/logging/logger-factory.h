#ifndef LOGGER_HELPER_H
#define LOGGER_HELPER_H

#include <set>
#include <string>
using namespace std;

#include "../properties.h"

#include "level.h"
#include "console-appender.h"
#include "file-appender.h"
#include "simple-formatter.h"
#include "logger.h"

#include "formatter-factory.h"
#include "appender-factory.h"

#include "../../util.h"
#include "../../strategy.h"

/**
 * The LoggerFactory to load and setup the logging configuration.
 * fabiojose@gmail.com
 */
class LoggerFactory{
    private:
        FormatterFactory ffactory;
        AppenderFactory afactory;

        string nameOf(string key, string prefix);

    public:
        LoggerFactory();
        virtual ~LoggerFactory();

        string loggerOf(string key);
        string appenderOf(string key);
        string formatterOf(string key);
        set<string> nameOf(Map<string, string>* properties, string prefix);
        Level levelOf(string level);
        void load();
        void setup();

        Logger* getLogger(string);
};

#endif // LOGGER_HELPER_H
