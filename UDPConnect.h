#ifndef UDP_CONNECT
#define UDP_CONNECT

#include <cstdio> 
#include <cstdlib> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

// I chose to implement this class to learn
// better how a UDP Connection in C++ works.
// I'm aware that there are C++ libraries around
// even cross-platform that to this, but I felt
// like this was an easier solution for now =)
class UDPConnect {
    private:
        struct sockaddr_in socket_addr_in;
        struct sockaddr* socket_addr;
        int socket_addr_size;
        char* ip_addr;
        int port;
        int socket_fd;
    public:
        UDPConnect(char* ip_addr, int port);
        ~UDPConnect();
        int send(const void* message, int size);
        int closeStream();
    private:
        void boot();
};

#endif