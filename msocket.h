/**
 *
 * Multicast Sockets.
 *
 */

class MulticastSocket: public DatagramSocket {

    private:
        int port;
        InetAddress* group;

    public:
        MulticastSocket(int port): DatagramSocket(){
            this->port = port;

            initsend();

            //bidding em qualquer interface de rede disponível para ENVIAR
            this->localhost.sin_addr.s_addr = INADDR_ANY;
            if(setsockopt(this->socksend, IPPROTO_IP, IP_MULTICAST_IF, (char *)&this->localhost, sizeof(this->localhost)) != SOCKET_ERROR){


            } else {
                throw sockcfgex;
            }
        }

        ~MulticastSocket(){

        }

        void joinGroup(InetAddress* group){
            initrecv();

            this->group = group;

            //configurar o mesmo socket para enviar e/ou receber pacotes
            int _option = 1;
            if(setsockopt(this->sockrecv, SOL_SOCKET, SO_REUSEADDR, (char *)&_option, sizeof(_option)) != SOCKET_ERROR){

                struct sockaddr_in _localhost;
                _localhost.sin_family      = AF_INET;
                _localhost.sin_addr.s_addr = INADDR_ANY;
                _localhost.sin_port        = htons(this->port);

                //bindding para recepção de datagramas do grupo
                if(bind(this->sockrecv, (struct sockaddr*)&_localhost, sizeof(_localhost)) != SOCKET_ERROR){

                    //associando-se ao grupo multicast
                    this->from.imr_multiaddr.s_addr = inet_addr(group->getHost());
                    this->from.imr_interface.s_addr = INADDR_ANY;
                    if(setsockopt(this->sockrecv, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *)&this->from, sizeof(this->from)) != SOCKET_ERROR){

                    } else {
                        throw sockcfgex;
                    }
                } else {
                    throw sockbdgex;
                }
            } else {
                throw sockcfgex;
            }
        }

        void receive(DatagramPacket* packet){
            packet->setTarget(this->group);
            packet->setPort(this->port);

            //invocar a implementação de receive na superclasse
            DatagramSocket::receive(packet);
        }

        void send(DatagramPacket* packet){
             packet->setTarget(this->group);
             packet->setPort(this->port);

             //invocar a implementação de send na superclasse
             DatagramSocket::send(packet);
        }
};
