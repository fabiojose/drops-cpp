#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include "throwable.h"
#include "exception-util.h"

class SocketBinddingException: public Throwable{

    public:
        SocketBinddingException();
        virtual ~SocketBinddingException() throw();

        virtual const char* what() const throw();

};
static SocketBinddingException sockbdgex;

class SocketConfigurationException: public Throwable {

    public:
        SocketConfigurationException();
        virtual ~SocketConfigurationException() throw();

        virtual const char* what() const throw();

};
static SocketConfigurationException sockcfgex;

class PackedSendException: public Throwable {

    public:
        PackedSendException();
        virtual ~PackedSendException() throw();

        virtual const char* what() const throw();

};
static PackedSendException packsndex;

class PackedReceiveException: public Throwable {

    public:
        PackedReceiveException();
        virtual ~PackedReceiveException() throw();

        virtual const char* what() const throw();

};
static PackedReceiveException packrcvex;

class IllegalStateException: public Throwable {

    public:
        IllegalStateException();
        virtual ~IllegalStateException() throw();

        virtual const char* what() const throw();

};
static IllegalStateException illegalex;

class UnsupportedOperationException: public Throwable {

    public:
        UnsupportedOperationException();
        virtual ~UnsupportedOperationException() throw();

        virtual const char* what() const throw();

};
static UnsupportedOperationException unsuppex;

class ConnectionException: public Throwable {

    public:
        ConnectionException();
        virtual ~ConnectionException() throw();

        virtual const char* what() const throw();
};
static ConnectionException connex;

#endif // EXCEPTIONS_H_INCLUDED
