#ifndef SOCKET_H_INCLUDED
#define SOCKET_H_INCLUDED

#include <iostream>
using namespace std;

#ifdef _WIN32
  #include <winsock2.h>
  #include <ws2tcpip.h>
#else
  #include <sys/types.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
#endif

#include "../lang/exception/exceptions.h"
#include "socket-ostream.h"
#include "socket-istream.h"

/**
 * Socket.
 * fabiojose@gmail.com
 */
class Socket {

    private:
        char* host;
        int port;

        unsigned int socksend;
        sockaddr_in target;
        OutputStream* output;
        InputStream* input;

    protected:
        void init();
        void start();

    public:
        Socket(char*, int);
        virtual ~Socket();

        OutputStream* getOutputStream();
        InputStream* getInputStream();

        void close();
};

#endif // SOCKET_H_INCLUDED
