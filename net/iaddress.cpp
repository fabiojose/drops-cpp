#include "iaddress.h"

InetAddress::InetAddress(char* host){
    this->host = host;

    //configure the default host in the structure
    address.sin_addr.s_addr = inet_addr(this->host);
}

InetAddress::~InetAddress(){

}

char* InetAddress::getHost(){
    return this->host;
}

void InetAddress::setHost(char* host){
    this->host = host;
}
