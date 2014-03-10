#include "dpacket.h"

DatagramPacket::DatagramPacket(){
    this->buffer = new char[DEFAULT_BUFFER_SIZE];
    this->length = DEFAULT_BUFFER_SIZE;
}

DatagramPacket::DatagramPacket(char* buffer, int length){
    this->buffer  = buffer;
    this->length  = length;
    this->target  = NULL;
    this->port    = 0;
}

DatagramPacket::DatagramPacket(char* buffer, int length, InetAddress* target, int port){
    this->buffer = buffer;
    this->length = length;
    this->target = target;
    this->port   = port;
}

DatagramPacket::~DatagramPacket(){

}

char* DatagramPacket::getData(){
    return this->buffer;
}

void DatagramPacket::setData(char* data){
    this->buffer = data;
}

int DatagramPacket::getLength(){
    return this->length;
}

void DatagramPacket::setLength(int length){
    this->length = length;
}

InetAddress* DatagramPacket::getTarget(){
    return this->target;
}

void DatagramPacket::setTarget(InetAddress* target){
    this->target = target;
}

int DatagramPacket::getPort(){
    return this->port;
}

void DatagramPacket::setPort(int port){
    this->port = port;
}
