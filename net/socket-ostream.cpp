#include "socket-ostream.h"

SocketOutputStream::SocketOutputStream(unsigned int sock){
    this->sock = sock;
}

SocketOutputStream::~SocketOutputStream(){

}

void SocketOutputStream::write(char* buffer, int length){

    if(send(sock, buffer, length, 0) != SOCKET_ERROR){

    } else {

    }

}
