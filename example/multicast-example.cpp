#include "multicast-example.h"

#define MCAST_ADDRESS "237.8.2.5"
#define MCAST_PORT    8254

/**
 *The receiver thread.
 */
class Receiver: public Thread{

    public:
        Receiver(){

        }

        ~Receiver(){

        }

        void run(){
            try{

                InetAddress*  _target       = InetAddress::getByName(MCAST_ADDRESS);
                MulticastSocket* _multicast = new MulticastSocket(MCAST_PORT);
                DatagramPacket* _packet     = new DatagramPacket();

                _multicast->joinGroup(_target);

                _multicast->receive(_packet);

                cout<<"Received datagram: "<<_packet->getData()<<endl;

                _multicast->close();

                delete _target;
                delete _multicast;
                delete _packet;
            }catch(exception& e){
                cout<<e.what();
            }
        }
};

MulticastExample::MulticastExample(){

}

MulticastExample::~MulticastExample(){

}

int MulticastExample::execute(int argc, char *argv[]){
    int _result = EXIT_SUCCESS;

    cout<<"OS: "<<Drops::runningOn()<<endl;

    //the receiver thread
    Receiver* _receiver = new Receiver();
    _receiver->start();

    char *_message;
    _message = (char *)malloc(255 * sizeof(char));

    //getting de user message
    gets(_message);
    printf("\tthe typped message is: %s\n", _message);

    int _option = 0;

    try{
        InetAddress*  _target       = InetAddress::getByName(MCAST_ADDRESS);
        MulticastSocket* _multicast = new MulticastSocket(MCAST_PORT);
        DatagramPacket* _packet     = new DatagramPacket(_message, strlen(_message));

        //joining on the multicast group
        _multicast->joinGroup(_target);

        //sending the to the group
        _multicast->send(_packet);

        //close the socket
        _multicast->close();

        delete _target;
        delete _multicast;
        delete _packet;
    }catch(exception& e){
        cout<<e.what();
    }

    delete _message;
    delete _receiver;

    system("PAUSE");
    return _result;
}

