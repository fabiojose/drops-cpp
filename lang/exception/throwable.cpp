#include "throwable.h"

Throwable::Throwable(){

}

Throwable::Throwable(char* message){
    this->message = message;
}

Throwable::Throwable(char* message, int code){
    this->message = message;
    this->code    = code;
}

Throwable::~Throwable() throw(){
}

void Throwable::setMessage(char* message) {
    this->message = message;
}

void Throwable::setCode(int code){
     this->code = code;
}

const char* Throwable::what() const throw(){
    return this->message;
}
