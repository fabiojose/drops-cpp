
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "util/map.h"
#include "util/properties.h"
#include "util/logging.h"

int main(int argc, char* argv[]){

    Logger* _logger = Logger::getLogger("root");
    Level _level = DEBUG;
    cout<<_level<<endl;

    _level = TRACE;
    cout<<_level<<endl;

    Strategy<string, Map<string, string>*>* _pstrategy = new PropertiesStrategy(____LOG4CPP);

    HashMap<string, string>* _loggers = (HashMap<string, string>*)_pstrategy->execute("log4cpp.logger.");
    cout<<_loggers->toString()<<endl;

    HashMap<string, string>* _appenders = (HashMap<string, string>*)_pstrategy->execute("log4cpp.appender.");
    cout<<_appenders->toString()<<endl;

    HashMap<string, string>* _formatters = (HashMap<string, string>*)_pstrategy->execute("log4cpp.formatter.");
    cout<<_formatters->toString()<<endl;

    cout<<UtilLogging::loggerOf("log4cpp.logger.CounterThread.level")<<endl;
    cout<<UtilLogging::loggerOf("log4cpp.logger.ROOT.appender")<<endl;

    cout<<UtilLogging::appenderOf("log4cpp.appender.CONSOLE")<<endl;
    cout<<UtilLogging::appenderOf("log4cpp.appender.FILE.file.name")<<endl;

    cout<<UtilLogging::formatterOf("log4cpp.formatter.FORMATTER.pattern")<<endl;
    cout<<UtilLogging::formatterOf("log4cpp.formatter.FORMATTER")<<endl;

    //delete _logger;
    delete _loggers;
    delete _appenders;
    delete _formatters;
    delete _pstrategy;

    return EXIT_SUCCESS;
}
