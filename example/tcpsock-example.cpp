#include "tcpsock-example.h"

#define HOST "10.10.10.200"
#define PORT 8255

TcpsockExample::TcpsockExample(){

}

TcpsockExample::~TcpsockExample(){

}

int TcpsockExample::execute(int argc, char* argv[]){
    int _result = EXIT_SUCCESS;

    try{
        Socket* _socket       = new Socket(HOST, PORT);

        OutputStream* _output = _socket->getOutputStream();
        char* _obuffer = "Fabio Jose de Moraes drops-cpp";
        _output->write(_obuffer, strlen(_obuffer));

        InputStream* _input = _socket->getInputStream();
        char* _ibuffer = new char[256];
        int _length = _input->read(_ibuffer, 256);
        cout<<"Received data: "<<_ibuffer<<endl;
        _socket->close();

        delete _socket;
    }catch(exception& e){
        cout<<"Exception: "<<e.what()<<endl;

        _result = EXIT_FAILURE;
    }

    return _result;
}
