#ifndef IADDRESS_H_INCLUDED
#define IADDRESS_H_INCLUDED

//include by OS
#ifdef _WIN32
  #include <winsock.h>
#else
  #include <sys/socket.h>
#endif

class InetAddress {

    private:
        char* host;
        struct sockaddr_in address;

    public:
        InetAddress(char* host);
        virtual ~InetAddress();

        char* getHost();
        void setHost(char* host);

        static InetAddress* getByName(char* host){
            InetAddress* _result = new InetAddress(host);

            return _result;
        }
};

#endif // IADDRESS_H_INCLUDED
