#ifndef APPENDER_H_INCLUDED
#define APPENDER_H_INCLUDED

#include "formatter.h"
#include "map.h"

class Appender {

    private:
        Formatter* formatter;
        HashMap<string, string> properties;

    public:
        Appender(){
            formatter = NULL;
        }

        ~Appender(){
            if(NULL!= formatter){
                delete formatter;
            }
        }

        void setFormatter(Formatter* formatter){
            this->formatter = formatter;
        }

        Formatter* getFormatter(){
            return formatter;
        }

        /**
        * Put properties on the appender.
        */
        void put(string key, string value){
            properties.put(key, value);
        }

        /**
        * Get properties from the appender.
        */
        string get(string key){
            string _result("");

            if(properties.containsKey(key)){
                _result = properties.get(key);
            }

            return _result;
        }

        virtual void publish(LogRecord* record) = 0;
};

class ConsoleAppender: public Appender {

    public:
        ConsoleAppender(){

        }

        ~ConsoleAppender(){

        }

        void publish(LogRecord* record){
            cout<<getFormatter()->format(record)<<endl;
        }

};

class FileAppender: public Appender {

    public:
        FileAppender(){

        }

        ~FileAppender(){

        }

        void publish(LogRecord* record){

        }
};

#endif // APPENDER_H_INCLUDED
