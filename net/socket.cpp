#include "socket.h"

//protected
void Socket::init(){
    //piece of code by OS
    #ifdef _WIN32
      WSADATA data;
      WORD version = MAKEWORD(8, 4);
      WSAStartup(version, &data);
    #endif // WINDOWS
}

void Socket::start(){
    target.sin_family = AF_INET;
    //piece of code by OS
    #ifdef _WIN32
      target.sin_addr.s_addr = inet_addr(host);
    #else
      inet_pton(AF_INET, host, &target.sin_addr);
    #endif
    target.sin_port = htons(port);

    socksend = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(socksend != INVALID_SOCKET){
        if(connect(socksend, (sockaddr*)&target, sizeof(sockaddr)) != SOCKET_ERROR){

        } else {
            throw connex;
        }
    } else {
        throw sockbdgex;
    }
}

//public
Socket::Socket(char* host, int port){
    init();

    this->host   = host;
    this->port   = port;

    this->output = NULL;
    this->input  = NULL;

    start();
}

Socket::~Socket(){
    close();

    if(NULL!= output){
        delete output;
    }

    if(NULL!= input){
        delete input;
    }
}

OutputStream* Socket::getOutputStream(){
    if(NULL== output){
        output = new SocketOutputStream(socksend);
    }

    return output;
}

InputStream* Socket::getInputStream(){
    if(NULL== input){
        input = new SocketInputStream(socksend);
    }

    return input;
}

void Socket::close(){
    if(socksend){
        //piece of code by OS
        #ifdef _WIN32
          closesocket(socksend);
          WSACleanup();
        #else
          ::close(socksend);
        #endif // _WIN32
    }
}
