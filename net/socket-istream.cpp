#include "socket-istream.h"

SocketInputStream::SocketInputStream(unsigned int sock){
    this->sock = sock;
}

SocketInputStream::~SocketInputStream(){

}

int SocketInputStream::read(char* buffer, int length){

    return recv(sock, buffer, length, 0);

}
