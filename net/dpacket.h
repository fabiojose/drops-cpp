#ifndef DPACKET_H_INCLUDED
#define DPACKET_H_INCLUDED

#include "iaddress.h"

const int DEFAULT_BUFFER_SIZE = 256;

class DatagramPacket {

    private:
        char* buffer;
        int length;
        InetAddress* target;
        int port;

    public:
        DatagramPacket();
        DatagramPacket(char* buffer, int length);
        DatagramPacket(char* buffer, int length, InetAddress* target, int port);
        virtual ~DatagramPacket();

        char* getData();
        void setData(char* data);

        int getLength();
        void setLength(int length);

        InetAddress* getTarget();
        void setTarget(InetAddress* target);

        int getPort();
        void setPort(int port);
};

#endif // DPACKET_H_INCLUDED
