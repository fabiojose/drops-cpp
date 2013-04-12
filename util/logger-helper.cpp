#include "logger-helper.h"

#define LOG4CPP_PROPERTIES  "log4cpp.properties"
#define LOG4CPP_ROOT_LOGGER "ROOT"

const string LOG4CPP_LOGGER    = "log4cpp.logger.";
const string LOG4CPP_APPENDER  = "log4cpp.appender.";
const string LOG4CPP_FORMATTER = "log4cpp.formatter.";

HashMap<string, string> ____LOG4CPP_APPENDERS;
Properties ____LOG4CPP;

LoggerHelper::LoggerHelper(){

}

LoggerHelper::~LoggerHelper(){

}

string LoggerHelper::nameOf(string key, string prefix){
    string _result("");

    if(UtilString::startsWith(key, prefix)){
        _result = key.substr(prefix.size(), key.size());

        size_t _index = _result.find_first_of(".");
        if(string::npos != _index){
            _result = _result.substr(0, _index);
        }
    }

    return _result;
}

string LoggerHelper::loggerOf(string key){
    return nameOf(key, LOG4CPP_LOGGER);
}

string LoggerHelper::appenderOf(string key){
    return nameOf(key, LOG4CPP_APPENDER);
}

string LoggerHelper::formatterOf(string key){
    return nameOf(key, LOG4CPP_FORMATTER);
}

set<string> LoggerHelper::nameOf(Map<string, string>* properties, string prefix){
    set<string> _result;

    set<string> _keys = properties->keySet();
    for(set<string>::iterator _entry = _keys.begin(); _entry != _keys.end(); ++_entry){

        _result.insert(nameOf((string)*_entry, prefix));

    }

    return _result;
}

Level LoggerHelper::levelOf(string level) {
    Level _result = LOG4CPP_DEFAULT_LEVEL;

    if("TRACE" == level){
        _result = TRACE;

    } else if("DEBUG" == level){
        _result = DEBUG;

    } else if("INFO" == level){
        _result = INFO;

    } else if("WARN" == level){
        _result = WARN;

    } else if("ERROR" == level){
        _result = ERROR;

    } else if("FATAL" == level){
        _result = FATAL;
    }

    return _result;
}

void LoggerHelper::load(){
    if(____LOG4CPP.isEmpty()){

        fstream _stream(LOG4CPP_PROPERTIES);

        ____LOG4CPP.load(_stream);

        _stream.close();
    }
}

void LoggerHelper::setup(){
    load();

    Strategy<string, Map<string, string>*>* _strategy = new PropertiesStrategy(&____LOG4CPP);

    //0 - collect the loggers.
    Map<string, string>* _ploggers = _strategy->execute(LOG4CPP_LOGGER);
    set<string> _loggers = LoggerHelper::nameOf(_ploggers, LOG4CPP_LOGGER);

    //1 - collect the appenders.
    Map<string, string>* _pappenders = _strategy->execute(LOG4CPP_APPENDER);
    set<string> _appenders = LoggerHelper::nameOf(_pappenders, LOG4CPP_APPENDER);

    //2 - collect the formatters.
    Map<string, string>* _pformatters = _strategy->execute(LOG4CPP_FORMATTER);
    set<string> _formatters = LoggerHelper::nameOf(_pformatters, LOG4CPP_FORMATTER);

    //3 - creating instances of the loggers
    for(set<string>::iterator _logger = _loggers.begin(); _logger != _loggers.end(); ++_logger){

        //Logger* _theLogger = new Logger();

        string _klevel(LOG4CPP_LOGGER + *_logger + ".level");
        if(_ploggers->containsKey(_klevel)){
            string _slevel = _ploggers->get(_klevel);
            //_theLogger->setLevel(LoggerHelper::levelOf(_slevel));
        } else {
            //_theLogger->setLevel(LOG4CPP_DEFAULT_LEVEL);
        }

        string _kapd(LOG4CPP_LOGGER + *_logger + ".appender");
        if(_ploggers->containsKey(_kapd)){

        } else {
            //apply the default appender
        }

    }

    //3 - validate the formatters
    for(set<string>::iterator _entry = _formatters.begin(); _entry != _formatters.end(); ++_entry){

        string _kname(LOG4CPP_FORMATTER + *_entry);
        if(_pformatters->containsKey(_kname)){
            string _fname = _pformatters->get(_kname);

            if("SimpleFormatter" == _fname){

                Formatter* _formatter = new SimpleFormatter();
                _formatter->setPattern(UtilString::toChar( _pformatters->get(_kname + ".pattern") ));
                delete _formatter;

            } else {
                //configure the default formatter
            }
        } else {
            //configure the default formatter
        }
    }

    //3 - connect appenders and formatters.
    set<string> _akeys = _pappenders->keySet();
    for(set<string>::iterator _entry = _akeys.begin(); _entry != _akeys.end(); ++_entry){

        string _fkey(LOG4CPP_APPENDER + *_entry + ".formatter");
        if(_pappenders->containsKey(_fkey)){
            //the formatter name
            string _fname = _pappenders->get(_fkey);
            //string _a
        } else {
            //connect the default formatter on the appender
        }
    }

    //4 - connect loggers and appenders.

    delete _strategy;
    delete _ploggers;
    delete _pappenders;
    delete _pformatters;
}
