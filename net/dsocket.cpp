#include "dsocket.h"

//protected
void DatagramSocket::init(){
    //piece of code by OS
    #ifdef _WIN32
      WSADATA data;
      WORD version = MAKEWORD(8, 4);
      WSAStartup(version, &data);
    #endif // WINDOWS
}

void DatagramSocket::initrecv(){
    if(this->sockrecv == INVALID_SOCKET){

        this->sockrecv = socket(AF_INET, SOCK_DGRAM, 0);
        if(this->sockrecv != INVALID_SOCKET){

        } else {
            throw sockbdgex;
        }
    }
}

void DatagramSocket::initsend(){
    if(this->socksend == INVALID_SOCKET){

        this->socksend = socket(AF_INET, SOCK_DGRAM, 0);
        if(this->socksend != INVALID_SOCKET){

        } else {
            throw sockbdgex;
        }
    }
}

//public
DatagramSocket::DatagramSocket() {
    init();

    this->sockrecv = INVALID_SOCKET;
    this->socksend = INVALID_SOCKET;

}

DatagramSocket::~DatagramSocket(){

}

void DatagramSocket::receive(DatagramPacket* packet){
     initrecv();

     if(packet->getTarget() != NULL && packet->getPort() > 0){

         char* _buffer = new char[DEFAULT_BUFFER_SIZE];
         int _sizeof   = sizeof(struct sockaddr);

         //recebendo datagram do remetente
         if(recvfrom(this->sockrecv, _buffer, DEFAULT_BUFFER_SIZE, 0, (struct sockaddr*)&this->from, &_sizeof) != SOCKET_ERROR){

             packet->setData(_buffer);
             packet->setLength(sizeof(_buffer));

         } else {
             throw packrcvex;
         }
     } else {
         illegalex.setMessage("Sem origem e/ou porta configurado(s)");
         throw illegalex;
     }
}

void DatagramSocket::send(DatagramPacket* packet){
    initsend();

    if(packet->getTarget() != NULL && packet->getPort() > 0){

        struct sockaddr_in _target;
        _target.sin_family      = AF_INET;
        _target.sin_addr.s_addr = inet_addr(packet->getTarget()->getHost());
        _target.sin_port        = htons(packet->getPort());

        //enviar bytes
        if(sendto(this->socksend, packet->getData(), packet->getLength(), MSG_DONTROUTE, (LPSOCKADDR) &_target, sizeof(_target)) != SOCKET_ERROR){

        } else {
            throw packsndex;
        }

    } else {
        illegalex.setMessage("Sem destino e/ou porta configurado(s)");
        throw illegalex;
    }
}

void DatagramSocket::close(){
    closesocket(this->socksend);
    closesocket(this->sockrecv);
}
