#include <cstdlib>
#include <iostream>

#include <winsock2.h>
#include <ws2tcpip.h>

#include "s.h"
#include "socket.h"

#define MCAST_ADDRESS "237.8.2.5"
#define MCAST_PORT    8254

using namespace std;

DWORD WINAPI Thread(void* data){
    
    try{
        InetAddress*  _target       = InetAddress::getByName(MCAST_ADDRESS);
        MulticastSocket* _multicast = new MulticastSocket(MCAST_PORT);
        DatagramPacket* _packet     = new DatagramPacket();
        
        //associar-se ao grupo multicast
        _multicast->joinGroup(_target);
        
        //enviar mensagem ao grupo
        _multicast->receive(_packet);
        
        cout<<"Datagrama recebido: "<<_packet->getData()<<endl;
        
        //fechar socket
        //_multicast->close();
        
        delete _target;        
        delete _multicast;
        delete _packet;
    }catch(exception& e){
        cout<<e.what();
    }
    
    /*SOCKET _socket;
    struct sockaddr_in _local;
    ip_mreq _group;
    
    int _option;
    
    _socket = socket(AF_INET, SOCK_DGRAM, 0);
    if(_socket != INVALID_SOCKET){
    
        _option = 1;
        if(setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&_option, sizeof(_option)) != SOCKET_ERROR){
            
            _local.sin_family      = AF_INET;
            _local.sin_addr.s_addr = INADDR_ANY;
            _local.sin_port        = htons(MCAST_PORT);
            if(bind(_socket, (struct sockaddr*)&_local, sizeof(_local)) != SOCKET_ERROR){
                
                _group.imr_multiaddr.s_addr = inet_addr(MCAST_ADDRESS);
                _group.imr_interface.s_addr = INADDR_ANY;
                if(setsockopt(_socket, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *)&_group, sizeof(_group)) != SOCKET_ERROR){
                    
                    char _buffer[256];
                    int _size   = sizeof(_buffer);
                    int _length = sizeof(struct sockaddr);
                    if(recvfrom(_socket, _buffer, _size, 0, (struct sockaddr *)&_group, &_length) != SOCKET_ERROR){
                        printf("Mensagem recebida: %s\n", _buffer);
                    } else {
                        printf ("\nError on receiving datagram message - %d\n", WSAGetLastError());           
                    }
                } else {
                    printf ("\nError joining on the group - %d\n", WSAGetLastError());
                }
            } else {
                printf ("\nError bindding socket - %d\n", WSAGetLastError());
            }
        } else {
            printf("\nError setting SO_REUSEADDR option - %d", WSAGetLastError());
        }
    } else {
        printf ("\nError creating socket - %d\n", WSAGetLastError());
    }
    */
    return 0;      
}

int main(int argc, char *argv[])
{
    int _result = EXIT_SUCCESS;
    WSADATA data;
    WORD version = MAKEWORD(8, 4);
    WSAStartup(version, &data);
    
    cout<<S::runningOn()<<endl;
    
    try{
        thw.setMessage("Mensagem modificada.");
        throw thw;
    }catch(exception& e){
        cout<<"Exception: "<<e.what()<<endl;
    }
    
    HANDLE _thread = CreateThread(NULL, 0, Thread, NULL, 0, NULL);
    if(!_thread){
        printf ("\nError on creating thread - %d", WSAGetLastError());
    }
    
    char *_message;
    _message = (char *)malloc(255 * sizeof(char));
    
    //obter mensagem do usuario
    gets(_message);
    printf("\tthe typped message is: %s\n", _message);
    
    int _option = 0;
    
    try{
        InetAddress*  _target       = InetAddress::getByName(MCAST_ADDRESS);
        MulticastSocket* _multicast = new MulticastSocket(MCAST_PORT);
        DatagramPacket* _packet     = new DatagramPacket(_message, strlen(_message));
        
        //associar-se ao grupo multicast
        _multicast->joinGroup(_target);
        
        //enviar mensagem ao grupo
        _multicast->send(_packet);
        
        //enviar um lote de 1000 pacotes ao grupo
        /*for(int _counter = 0; _counter < 1000; _counter++){
            sprintf(_message, "%d", _counter);
            
            _packet->setData(_message);
            _packet->setLength(strlen(_message));
            
            _multicast->send(_packet);
        }*/
        
        //_multicast->close();
        
        delete _target;        
        delete _multicast;
        delete _packet;
    }catch(exception& e){
        cout<<e.what();
    }
    /*//obter socket
    _socket = socket(PF_INET, SOCK_DGRAM, 0); 
    if (_socket != INVALID_SOCKET) { 
         
         //bindding em qualquer interface de rede
         _from.sin_addr.s_addr = INADDR_ANY;
         
         if (setsockopt(_socket, IPPROTO_IP, IP_MULTICAST_IF, (char *)&_from, sizeof(_from)) != SOCKET_ERROR){
             
             //configurar opção para enviar pacotes para fora da rede local
             _option = 64;
             if (setsockopt(_socket, IPPROTO_IP, IP_MULTICAST_IF, (char *)&_option, sizeof(_option)) != SOCKET_ERROR) {
         
                //enviar mensagem datagrama para o endereço multicast
                _to.sin_family      = AF_INET;
                _to.sin_addr.s_addr = inet_addr(MCAST_ADDRESS);
                _to.sin_port        = htons(MCAST_PORT);
                 
                if (sendto(_socket, _message, strlen(_message), MSG_DONTROUTE, (LPSOCKADDR) &_to, sizeof(_to)) != SOCKET_ERROR){
                    printf("Mensagem envidada.\n");
                } else {
                    printf ("\nError on sendding datagram message - %d\n", WSAGetLastError());
                    _result = EXIT_FAILURE;
                } 
             } else {
                 printf ("\nError setting socket option - %d\n", WSAGetLastError());
                 _result = EXIT_FAILURE;
             }
             
             
         } else {
             printf ("\nError bindding socket - %d\n", WSAGetLastError());
             _result = EXIT_FAILURE;
         }
    } else {
         printf ("\nError creating socket - %d\n", WSAGetLastError());
         _result = EXIT_FAILURE;
    }
    
    closesocket(_socket);*/
    delete _message;
    
    system("PAUSE");
    return _result;
}

