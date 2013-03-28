/**
 *
 * System.
 *
 */

#ifdef _WIN32
  #define WINDOWS "WINDOWS"
#else
  #define LINUX "LINUX"
#endif

const int MAX_EXP_MSG_LENGTH = 256;

#include <exception>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#ifdef WINDOWS
  #include <windows.h>
  #include <ws2tcpip.h>
#endif // WINDOWS

using namespace std;

class S {

    public:
        S(){

        }

        ~S(){

        }

        static char* runningOn(){
            #ifdef WINDOWS
              return WINDOWS;
            #else
              return LINUX;
            #endif
        }
};

class Format {

    public:
        Format(){

        }

        ~Format(){
        }

        char* exception(char* message){
            char* _result = new char[MAX_EXP_MSG_LENGTH];
            char _code[20];

            strcpy(_result, message);

            int _errorno = 0;
            #ifdef LINUX
                _errorno = errno;
            #else
                _errorno = GetLastError();
            #endif

            sprintf(_code, " - %d", _errorno);
            strcat(_result, _code);

            return _result;
        }
} fmt;

class Throwable:public exception {

    private:
        char* message;
        int code;

    public:
        Throwable(){

        }

        Throwable(char* message){
            this->message = message;
        }

        Throwable(char* message, int code){
            this->message = message;
            this->code    = code;
        }

        virtual ~Throwable() throw(){
        }

        void setMessage(char* message) {
            this->message = message;
        }

        void setCode(int code){
             this->code = code;
        }

        virtual const char* what() const throw(){
            return this->message;
        }

} thw("Default Exception", 9999);

class InitializationException: public Throwable{

    public:
        InitializationException(){
        }

        virtual ~InitializationException() throw(){
        }

        virtual const char* what() const throw(){
            return fmt.exception("Exception on initialization");
        }

} initex;

class SocketBinddingException: public Throwable{

    public:
        SocketBinddingException(){
        }

        virtual ~SocketBinddingException() throw(){
        }

        virtual const char* what() const throw(){
            return fmt.exception("Exception in socket bidding");
        }

} sockbdgex;

class SocketConfigurationException: public Throwable {

    public:
        SocketConfigurationException(){
        }

        virtual ~SocketConfigurationException() throw(){
        }

        virtual const char* what() const throw(){
            return fmt.exception("Exception in socket configuration");
        }

} sockcfgex;

class PackedSendException: public Throwable {

    public:
        PackedSendException(){
        }

        virtual ~PackedSendException() throw(){
        }

        virtual const char* what() const throw(){
            return fmt.exception("Packet not sent");
        }

} packsndex;

class PackedReceiveException: public Throwable {

    public:
        PackedReceiveException(){
        }

        virtual ~PackedReceiveException() throw(){
        }

        virtual const char* what() const throw(){
            return fmt.exception("Packet not received");
        }

} packrcvex;

class IllegalStateException: public Throwable {

    public:
        IllegalStateException(){
        }

        virtual ~IllegalStateException() throw(){
        }

        virtual const char* what() const throw(){
            "Illegal state";
        }

} illegalex;

class UnsupportedOperationException: public Throwable {

    public:
        UnsupportedOperationException(){

        }

        virtual ~UnsupportedOperationException() throw(){

        }

        virtual const char* what() const throw(){
            "Operation not supported";
        }
} unsuppex;


