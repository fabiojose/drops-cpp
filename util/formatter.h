#ifndef FORMATTER_H_INCLUDED
#define FORMATTER_H_INCLUDED

#include "log-record.h"
#include "../text/date-format.h"
#include "date.h"

class Formatter {

    private:
        char* pattern;

    public:
        Formatter(){

        }

        ~Formatter(){

        }

        void setPattern(char* pattern){
            this->pattern = pattern;
        }

        char* getPattern(){
            return pattern;
        }

        virtual string format(LogRecord* record) = 0;

};

class SimpleFormatter: public Formatter {

    private:
        DateFormat* formatt;

    protected:
        DateFormat* getFormatt(){
            if(NULL== formatt){
                formatt = new DateFormat(getPattern());
            }
        }

    public:
        SimpleFormatter(){
            formatt = NULL;
        }

        ~SimpleFormatter(){
            if(NULL!= formatt){
                delete formatt;
            }
        }

        string format(LogRecord* record){
            string _result("");

            //the timestamp format
            Date* _now = new Date();
            string _snow = getFormatt()->format(_now);
            delete _now;

            //the log message format
            _result = _snow;

            return _result;
        }
};

#endif // FORMATTER_H_INCLUDED
