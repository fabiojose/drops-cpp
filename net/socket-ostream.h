#ifndef SOCKET_OSTREAM_H_INCLUDED
#define SOCKET_OSTREAM_H_INCLUDED

#ifdef _WIN32
  #include <winsock2.h>
  #include <ws2tcpip.h>
#else
  #include <sys/socket.h>
#endif

#include "../io/output-stream.h"

class SocketOutputStream: public OutputStream {

    private:
        unsigned int sock;

    public:
        SocketOutputStream(unsigned int);
        virtual ~SocketOutputStream();

        void write(char*, int);
};

#endif // SOCKET_OSTREAM_H_INCLUDED
