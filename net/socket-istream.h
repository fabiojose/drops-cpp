#ifndef SOCKET_ISTREAM_H_INCLUDED
#define SOCKET_ISTREAM_H_INCLUDED

#ifdef _WIN32
  #include <winsock2.h>
  #include <ws2tcpip.h>
#else
  #include <sys/socket.h>
#endif

#include "../io/input-stream.h"

class SocketInputStream: public InputStream {

    private:
        unsigned int sock;

    public:
        SocketInputStream(unsigned int);
        virtual ~SocketInputStream();

        int read(char*, int);
};

#endif // SOCKET_ISTREAM_H_INCLUDED
