#include "server.h"
#include <exception>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(){
    constexpr int port{8080};
    struct sockaddr_in mySocketAddress{};
    int socketFileDescriptor{};

    try{
        socketFileDescriptor = createSocket(AF_INET, SOCK_STREAM, 0);
        std::cout<<"Socket created\n";
    }catch(const std::exception& e){
        return 1;
    }

    mySocketAddress.sin_family = AF_INET;
    mySocketAddress.sin_addr.s_addr = INADDR_ANY;
    mySocketAddress.sin_port = htons(port);


    try{
        int binded=bindSocket(socketFileDescriptor, reinterpret_cast<struct sockaddr*>(&mySocketAddress));
        std::cout<<"Socket binded successfully\n";
    }catch(const std::exception &e){
        std::cout<<"Socket could not be binded\n";
        return 1;
    }


    return 0;
}

