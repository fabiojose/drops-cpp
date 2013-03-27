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
        
        static InetAddress* getByName(char* host){
            InetAddress* _result = new InetAddress(host);       
        
            return _result;
        }
};
