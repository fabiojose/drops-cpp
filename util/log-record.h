#ifndef LOG_RECORD_H_INCLUDED
#define LOG_RECORD_H_INCLUDED

#include <string>
using namespace std;

class LogRecord {

    private:
        string message;

    public:
        LogRecord(){

        }

        LogRecord(string message){
            this->message = message;
        }

        ~LogRecord(){

        }

        void setMessage(string message){
            this->message = message;
        }

        string getMessage(){
            return message;
        }
};

#endif // LOG_RECORD_H_INCLUDED
