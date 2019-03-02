#include <cstdio> 
#include <cstdlib> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <iostream>

using namespace std;

class UDPConnect {
    private:
        struct sockaddr_in socket_addr_in;
        struct sockaddr* socket_addr;
        int socket_addr_size;
        char* ip_addr;
        int port;
        int socket_fd;
    public:
        UDPConnect(char* ip_addr, int port) {
            this->ip_addr = ip_addr;
            this->port = port;
            this->boot();
        }
        ~UDPConnect() {
            this->close();
        }
        int send(const void* message, int size) {
            return sendto(
                this->socket_fd,
                message,
                size,
                MSG_CONFIRM,
                this->socket_addr,
                this->socket_addr_size
            ); 
        }
        int close() {
            return close();
        }
    private:
        void boot() {
            this->socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
            this->socket_addr_in.sin_family = AF_INET;
            this->socket_addr_in.sin_port = htons(this->port);
            this->socket_addr_in.sin_addr.s_addr = inet_addr(this->ip_addr);
            this->socket_addr_size = sizeof(this->socket_addr_in);
            this->socket_addr = (struct sockaddr*)&this->socket_addr_in;
        }
};

typedef struct {
    int magnetos = 0;
    double mixture = 0.0;
    double throttle = 0.0;
    double aileron = 0.0;
    double elevator = 0.0;
    double rudder = 0.0;
} fgfs_data;

int main() {
    UDPConnect* udp_connection = new UDPConnect("127.0.0.1", 2115);
    fgfs_data test_data;

    test_data.magnetos = 1;
    test_data.aileron = 0.01;
    udp_connection->send(&test_data, sizeof(test_data));

    cout << sizeof(test_data) << "\n";

    return 0; 
} 