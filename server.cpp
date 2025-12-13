#include "server.h"
#include <stdexcept>
#include <sys/socket.h>

int createSocket(int domain, int type, int protocol){
    int socketFileDescriptor{socket(domain, type, protocol)};
    if(socketFileDescriptor<0){
        throw std::runtime_error("Socket creation failed");
    }
    return socketFileDescriptor;
}

int bindSocket(int socketFileDescriptor, const struct sockaddr *addr){    
    int bindMySocket{bind(socketFileDescriptor, addr, sizeof(*addr))};
    if(bindMySocket<0){
        throw std::runtime_error("Failed to bind the socket");
    }
    return bindMySocket;
}
