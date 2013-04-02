/**
 *
 * UPD Sockets
 * fabiojose@gmail.com
 */

#include <iostream>

using namespace std;

class DatagramPacket {

    private:
        char* buffer;
        int length;
        InetAddress* target;
        int port;

    public:
        DatagramPacket(){
            this->buffer = new char[DEFAULT_BUFFER_SIZE];
            this->length = DEFAULT_BUFFER_SIZE;
        }

        DatagramPacket(char* buffer, int length){
            this->buffer  = buffer;
            this->length  = length;
            this->target  = NULL;
            this->port    = 0;
        }

        DatagramPacket(char* buffer, int length, InetAddress* target, int port): DatagramPacket(buffer, length) {
            this->target = target;
            this->port   = port;
        }

        ~DatagramPacket(){

        }

        char* getData(){
            return this->buffer;
        }

        void setData(char* data){
            this->buffer = data;
        }

        int getLength(){
            return this->length;
        }

        void setLength(int length){
            this->length = length;
        }

        InetAddress* getTarget(){
            return this->target;
        }

        void setTarget(InetAddress* target){
            this->target = target;
        }

        int getPort(){
            return this->port;
        }

        void setPort(int port){
            this->port = port;
        }
};

class DatagramSocket: public Socket {

    protected:
        SOCKET socksend;
        SOCKET sockrecv;

        struct sockaddr_in localhost;
        struct ip_mreq from;

        /**
         * Obter socket para RECEBER.
         */
        void initrecv(){
            if(this->sockrecv == INVALID_SOCKET){

                this->sockrecv = socket(AF_INET, SOCK_DGRAM, 0);
                if(this->sockrecv != INVALID_SOCKET){

                } else {
                    throw sockbdgex;
                }
            }
        }

        /**
         * Obter socket para ENVIAR.
         */
        void initsend(){
            if(this->socksend == INVALID_SOCKET){

                this->socksend = socket(AF_INET, SOCK_DGRAM, 0);
                if(this->socksend != INVALID_SOCKET){

                } else {
                    throw sockbdgex;
                }
            }
        }

    public:
        DatagramSocket(): Socket(){

            this->sockrecv = INVALID_SOCKET;
            this->socksend = INVALID_SOCKET;

        }

        ~DatagramSocket(){

        }

        /**
         * Receber.
         */
        void receive(DatagramPacket* packet){
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

        /**
         * Enviar
         */
        void send(DatagramPacket* packet){
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

        void close(){
            closesocket(this->socksend);
            closesocket(this->sockrecv);
        }
};
