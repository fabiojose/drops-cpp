#ifndef THROWABLE_H_INCLUDED
#define THROWABLE_H_INCLUDED

#include <exception>
using namespace std;

class Throwable:public exception {

    private:
        char* message;
        int code;

    public:
        Throwable();
        Throwable(char* message);
        Throwable(char* message, int code);
        virtual ~Throwable() throw();

        void setMessage(char* message);
        void setCode(int code);

        virtual const char* what() const throw();

};

#endif // THROWABLE_H_INCLUDED
