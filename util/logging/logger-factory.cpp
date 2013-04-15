#include "logger-factory.h"

#define LOG4CPP_PROPERTIES  "log4cpp.properties"
#define LOG4CPP_ROOT_LOGGER "ROOT"

const string LOG4CPP_LOGGER    = "log4cpp.logger.";
const string LOG4CPP_APPENDER  = "log4cpp.appender.";
const string LOG4CPP_FORMATTER = "log4cpp.formatter.";

//the logging properties
Properties ____LOG4CPP;

//the loggers store
HashMap<string, Logger*>    ____LOG4CPP_LOGGERS;

//the appenders store
HashMap<string, Appender*>  ____LOG4CPP_APPENDERS;

//the formatters store
HashMap<string, Formatter*> ____LOG4CPP_FORMATTERS;

LoggerFactory::LoggerFactory(){

}

LoggerFactory::~LoggerFactory(){

}

string LoggerFactory::nameOf(string key, string prefix){
    string _result("");

    if(StringUtil::startsWith(key, prefix)){
        _result = key.substr(prefix.size(), key.size());

        size_t _index = _result.find_first_of(".");
        if(string::npos != _index){
            _result = _result.substr(0, _index);
        }
    }

    return _result;
}

string LoggerFactory::loggerOf(string key){
    return nameOf(key, LOG4CPP_LOGGER);
}

string LoggerFactory::appenderOf(string key){
    return nameOf(key, LOG4CPP_APPENDER);
}

string LoggerFactory::formatterOf(string key){
    return nameOf(key, LOG4CPP_FORMATTER);
}

set<string> LoggerFactory::nameOf(Map<string, string>* properties, string prefix){
    set<string> _result;

    set<string> _keys = properties->keySet();
    for(set<string>::iterator _entry = _keys.begin(); _entry != _keys.end(); ++_entry){

        _result.insert(nameOf((string)*_entry, prefix));

    }

    return _result;
}

Level LoggerFactory::levelOf(string level) {
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

void LoggerFactory::load(){
    if(____LOG4CPP.isEmpty()){

        fstream _stream(LOG4CPP_PROPERTIES);

        ____LOG4CPP.load(_stream);

        _stream.close();
    }
}

void LoggerFactory::setup(){
    load();

    if(____LOG4CPP_LOGGERS.isEmpty()){
        Strategy<string, Map<string, string>*>* _strategy = new PropertiesStrategy(&____LOG4CPP);

        //0 - collect the loggers.
        Map<string, string>* _ploggers = _strategy->execute(LOG4CPP_LOGGER);
        set<string> _loggers = LoggerFactory::nameOf(_ploggers, LOG4CPP_LOGGER);

        //1 - collect the appenders.
        Map<string, string>* _pappenders = _strategy->execute(LOG4CPP_APPENDER);
        set<string> _appenders = LoggerFactory::nameOf(_pappenders, LOG4CPP_APPENDER);

        //2 - collect the formatters.
        Map<string, string>* _pformatters = _strategy->execute(LOG4CPP_FORMATTER);
        set<string> _formatters = LoggerFactory::nameOf(_pformatters, LOG4CPP_FORMATTER);

        //3 - validate the formatters
        for(set<string>::iterator _entry = _formatters.begin(); _entry != _formatters.end(); ++_entry){

            Formatter* _formatter = NULL;

            string _kname(LOG4CPP_FORMATTER + *_entry);
            if(_pformatters->containsKey(_kname)){
                string _fname = _pformatters->get(_kname);

                if("SimpleFormatter" == _fname){

                    _formatter = new SimpleFormatter();
                    _formatter->setPattern(StringUtil::toChar( _pformatters->get(_kname + ".pattern") ));

                    //store the formatter properties
                    set<string> _keys = _pformatters->keySet();
                    for(set<string>::iterator _key = _keys.begin(); _key != _keys.end(); ++_key){
                        if(StringUtil::startsWith(*_key, _kname)){
                            _formatter->put(*_key, _kname);
                        }
                    }
                } else {
                    //configure the default formatter
                    _formatter = new SimpleFormatter();
                }
            } else {
                //configure the default formatter
                _formatter = new SimpleFormatter();
            }

            //store the formatter configuration
            ____LOG4CPP_FORMATTERS.put(*_entry, _formatter);
        }

        //4 - validate the appenders and connect formatters
        for(set<string>::iterator _entry = _appenders.begin(); _entry != _appenders.end(); ++_entry){

            Appender* _appender = NULL;

            string _kname(LOG4CPP_APPENDER + *_entry);
            if(_pappenders->containsKey(_kname)){
                string _aname = _pappenders->get(_kname);

                if("ConsoleAppender" == _aname){
                    _appender = new ConsoleAppender();

                } else if("FileAppender" == _aname){
                    _appender = new FileAppender();

                } else {
                    //configure a detault appender
                    _appender = new ConsoleAppender();
                }

                //store the appender properties
                set<string> _keys = _pappenders->keySet();
                for(set<string>::iterator _key = _keys.begin(); _key != _keys.end(); ++_key){
                    if(StringUtil::startsWith(*_key, _kname)){
                        string __key = *_key;
                        if(__key.size() != _kname.size()){
                            __key = __key.substr(_kname.size() + 1);
                        }

                        _appender->put(__key, _pappenders->get(*_key));
                    }
                }

                string _kfmt(LOG4CPP_APPENDER + *_entry + ".formatter");
                if(_pappenders->containsKey(_kfmt)){
                    string _fname = _pappenders->get(_kfmt);
                    if(____LOG4CPP_FORMATTERS.containsKey(_fname)){
                        _appender->setFormatter(____LOG4CPP_FORMATTERS.get(_fname));
                    } else {
                        //connect a default formatter
                    }
                } else {
                    //connect a default formatter
                }
            } else {
                //configure a detault appender
                _appender = new ConsoleAppender();
            }

            //store the appender configuration
            ____LOG4CPP_APPENDERS.put(*_entry, _appender);
        }

        //5 - creating instances of the loggers connect the appenders.
        for(set<string>::iterator _logger = _loggers.begin(); _logger != _loggers.end(); ++_logger){

            Logger* _theLogger = new Logger();

            string _klevel(LOG4CPP_LOGGER + *_logger + ".level");
            if(_ploggers->containsKey(_klevel)){
                string _slevel = _ploggers->get(_klevel);
                _theLogger->setLevel(LoggerFactory::levelOf(_slevel));
            } else {
                _theLogger->setLevel(LOG4CPP_DEFAULT_LEVEL);
            }

            //store the logger properties
            set<string> _keys = _ploggers->keySet();
            for(set<string>::iterator _key = _keys.begin(); _key != _keys.end(); ++_key){
                if(StringUtil::startsWith(*_key, LOG4CPP_LOGGER + *_logger)){
                    _theLogger->put(*_key, _ploggers->get(*_key));
                }
            }

            string _kapd(LOG4CPP_LOGGER + *_logger + ".appender");
            if(_ploggers->containsKey(_kapd)){
                vector<string> _lappenders = StringUtil::split(_ploggers->get(_kapd), ',');
                for(vector<string>::iterator _appender = _lappenders.begin(); _appender != _lappenders.end(); ++_appender){
                    string _sappender = StringUtil::trim(*_appender);

                    if(____LOG4CPP_APPENDERS.containsKey(_sappender)){
                        _theLogger->add(____LOG4CPP_APPENDERS.get(_sappender));
                    } else {
                        //connect the default appender
                    }
                }
            } else {
                //connect the default appender
            }

            //the logger name
            _theLogger->setName(StringUtil::toChar(*_logger));

            //store the logger in the map
            ____LOG4CPP_LOGGERS.put(*_logger, _theLogger);

        }

        delete _strategy;
        delete _ploggers;
        delete _pappenders;
        delete _pformatters;

    } else {
        cout<<"already loaded."<<endl;
    }
}

Logger* LoggerFactory::getLogger(string name){
    return ____LOG4CPP_LOGGERS.get(name);
}
