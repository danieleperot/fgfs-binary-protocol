#include "UDPConnect.h"

UDPConnect::UDPConnect(char* ip_addr, int port) {
    this->ip_addr = ip_addr;
    this->port = port;
    this->boot();
}
UDPConnect::~UDPConnect() {
    this->close();
}
int UDPConnect::send(const void* message, int size) {
    return sendto(
        this->socket_fd,
        message,
        size,
        MSG_CONFIRM,
        this->socket_addr,
        this->socket_addr_size
    ); 
}
int UDPConnect::close() {
    return close();
}

void UDPConnect::boot() {
    this->socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    this->socket_addr_in.sin_family = AF_INET;
    this->socket_addr_in.sin_port = htons(this->port);
    this->socket_addr_in.sin_addr.s_addr = inet_addr(this->ip_addr);
    this->socket_addr_size = sizeof(this->socket_addr_in);
    this->socket_addr = (struct sockaddr*)&this->socket_addr_in;
}