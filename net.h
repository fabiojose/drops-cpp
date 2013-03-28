/**
 *
 * Network.
 *
 */

#include <iostream>
using namespace std;

#ifdef LINUX
  #include <sys/socket.h>
#else
  #include <winsock.h>
#endif

const int DEFAULT_BUFFER_SIZE = 256;

class InetAddress {

    private:
        char* host;
        struct sockaddr_in address;

    public:
        InetAddress(char* host){
            this->host = host;

            //configurar host na estrura padrao
            address.sin_addr.s_addr = inet_addr(this->host);
        }

        ~InetAddress(){

        }

        char* getHost(){
            return this->host;
        }

        void setHost(char* host){
            this->host = host;
        }

        static InetAddress* getByName(char* host){
            InetAddress* _result = new InetAddress(host);

            return _result;
        }
};

class Socket {

    protected:
        void init(){
            #ifdef WINDOWS
              WSADATA data;
              WORD version = MAKEWORD(8, 4);
              WSAStartup(version, &data);
            #endif // WINDOWS
        }

    public:
        Socket(){
            init();
        }

        ~Socket(){

        }
};
