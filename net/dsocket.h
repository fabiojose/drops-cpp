#ifndef USOCKET_H_INCLUDED
#define USOCKET_H_INCLUDED

#ifdef _WIN32
  #include <winsock2.h>
  #include <ws2tcpip.h>
#else
  #include <sys/types.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
  #define INVALID_SOCKET (unsigned int)(~0)
  #define SOCKET_ERROR	(-1)
#endif

#include "dpacket.h"
#include "../lang/exception/exceptions.h"

/**
 * UPD Sockets
 * fabiojose@gmail.com
 */
class DatagramSocket {

    protected:
        unsigned int socksend;
        unsigned int sockrecv;

        struct sockaddr_in localhost;
        struct ip_mreq from;

        /**
         * Init socket parameters.
         */
        void init();

        /**
         * Create a socket for receive.
         */
        void initrecv();

        /**
         * Create a socket for send.
         */
        void initsend();

    public:
        DatagramSocket();
        virtual ~DatagramSocket();

        void receive(DatagramPacket* packet);
        void send(DatagramPacket* packet);
        void close();
};

#endif // USOCKET_H_INCLUDED
