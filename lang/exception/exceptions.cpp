#include "exceptions.h"

//SocketBinddingException
SocketBinddingException::SocketBinddingException(){

}

SocketBinddingException::~SocketBinddingException() throw(){

}

const char* SocketBinddingException::what() const throw(){
    return exutil.exception("Exception in socket bindding");
}

//SocketConfigurationException
SocketConfigurationException::SocketConfigurationException(){
}

SocketConfigurationException::~SocketConfigurationException() throw(){
}

const char* SocketConfigurationException::what() const throw(){
    return exutil.exception("Exception in socket configuration");
}

//PackedSendException
PackedSendException::PackedSendException(){
}

PackedSendException::~PackedSendException() throw(){
}

const char* PackedSendException::what() const throw(){
    return exutil.exception("Packet not sent");
}

//PackedReceiveException
PackedReceiveException::PackedReceiveException(){
}

PackedReceiveException::~PackedReceiveException() throw(){
}

const char* PackedReceiveException::what() const throw(){
    return exutil.exception("Packet not received");
}

//IllegalStateException
IllegalStateException::IllegalStateException(){
}

IllegalStateException::~IllegalStateException() throw(){
}

const char* IllegalStateException::what() const throw(){
    "Illegal state";
}

//UnsupportedOperationException
UnsupportedOperationException::UnsupportedOperationException(){

}

UnsupportedOperationException::~UnsupportedOperationException() throw(){

}

const char* UnsupportedOperationException::what() const throw(){
    "Operation not supported";
}

//ConnectionException
ConnectionException::ConnectionException(){

}

ConnectionException::~ConnectionException() throw(){

}

const char* ConnectionException::what() const throw(){
    "Can not connect.";
}
