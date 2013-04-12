#ifndef FILE_APPENDER_H
#define FILE_APPENDER_H

#include <fstream>
using namespace std;

#include <sys/stat.h>

#include "../../util.h"
#include "appender.h"

/**
 * The FileAppender to log messagens in text files.
 * fabiojose@gmail.com
 */
class FileAppender: public Appender {

    private:
        fstream file;

    protected:
        string getFileName();
        string getDirectory();

        fstream& getFile();

    public:
        FileAppender();
        virtual ~FileAppender();

        virtual void publish(LogRecord* record);
};

#endif // FILE_APPENDER_H
