#include "iaddress.h"

InetAddress::InetAddress(char* host){
    this->host = host;

    //configure the default host in the structure
    //piece of code by OS
    #ifdef _WIN32
      address.sin_addr.s_addr = inet_addr(this->host);
    #else
      inet_pton(AF_INET, this->host, &address.sin_addr);
    #endif
}

InetAddress::~InetAddress(){

}

char* InetAddress::getHost(){
    return this->host;
}

void InetAddress::setHost(char* host){
    this->host = host;
}
