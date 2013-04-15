/**
 * Multicast Sockets.
 * fabiojose@gmail.com
 */

#ifndef MSOCKET_H_INCLUDED
#define MSOCKET_H_INCLUDED

#include "dsocket.h"

class MulticastSocket: public DatagramSocket {

    private:
        int port;
        InetAddress* group;

    public:
        MulticastSocket(int port);
        virtual ~MulticastSocket();

        void joinGroup(InetAddress* group);

        void receive(DatagramPacket* packet);
        void send(DatagramPacket* packet);
};

#endif // MSOCKET_H_INCLUDED
