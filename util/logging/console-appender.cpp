#include "console-appender.h"

ConsoleAppender::ConsoleAppender(){

}

ConsoleAppender::~ConsoleAppender(){

}

void ConsoleAppender::publish(LogRecord* record){

    cout<<getFormatter()->format(record)<<endl;

}

