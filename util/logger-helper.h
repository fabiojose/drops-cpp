#ifndef LOGGER_HELPER_H
#define LOGGER_HELPER_H

#include <set>
#include <string>
using namespace std;

#include "properties.h"

#include "level.h"
#include "formatter.h"

#include "../util.h"
#include "../strategy.h"

class LoggerHelper{
    private:
        string nameOf(string key, string prefix);

    public:
        LoggerHelper();
        virtual ~LoggerHelper();

        string loggerOf(string key);
        string appenderOf(string key);
        string formatterOf(string key);
        set<string> nameOf(Map<string, string>* properties, string prefix);
        Level levelOf(string level);
        void load();
        void setup();
};

#endif // LOGGER_HELPER_H
