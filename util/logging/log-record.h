#ifndef LOG_RECORD_H_INCLUDED
#define LOG_RECORD_H_INCLUDED

#include "level.h"

/**
 * LogRecord with message and addtional information for publish.
 * fabiojose@gmail.com
 */
class LogRecord {

    private:
        char* message;
        Level level;
        char* logger;

    public:
        LogRecord(){

        }

        LogRecord(char* message){
            this->message = message;
        }

        LogRecord(char* message, Level level){
            this->message = message;
            this->level   = level;
        }

        LogRecord(char* message, Level level, char* logger){
            this->message = message;
            this->level   = level;
            this->logger  = logger;
        }

        ~LogRecord(){

        }

        void setMessage(char* message){
            this->message = message;
        }

        char* getMessage(){
            return message;
        }

        void setLevel(Level level){
            this->level = level;
        }

        Level getLevel(){
            return level;
        }

        void setLogger(char* logger){
            this->logger = logger;
        }

        char* getLogger(){
            return logger;
        }
};

#endif // LOG_RECORD_H_INCLUDED
