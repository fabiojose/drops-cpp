#include "file-appender.h"

//protected
string FileAppender::getFileName(){
    return get("file.name");
}

string FileAppender::getDirectory(){
    return get("directory");
}

fstream& FileAppender::getFile(){
    if(!file.is_open()){
        char* _absolute = UtilString::toChar(getDirectory() + getFileName());
        file.open(_absolute,  ios::out | ios::app);
        file.seekp(ios::end);

        /*struct stat _statis;
        if(stat(_absolute, &_statis)){
            cout<<_statis.st_size<<endl;
        }*/
    }

    return file;
}

//public
FileAppender::FileAppender(){

}

FileAppender::~FileAppender(){
    if(file.is_open()){
        file.close();
    }
}

void FileAppender::publish(LogRecord* record){

    char* _toPublish = getFormatter()->format(record);
    getFile()<<_toPublish<<endl;

}
