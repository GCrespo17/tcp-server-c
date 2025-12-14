#include "server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(){
    constexpr int port{8080};
    constexpr int maximumConnections{50};
    struct sockaddr_in mySocketAddress{};
    int socketFileDescriptor{};
    constexpr int defaultProtocol{0};

    socketFileDescriptor = createSocket(AF_INET, SOCK_STREAM, defaultProtocol);

    mySocketAddress.sin_family = AF_INET;
    mySocketAddress.sin_addr.s_addr = INADDR_ANY;
    mySocketAddress.sin_port = htons(port);


    bindSocket(socketFileDescriptor, reinterpret_cast<const struct sockaddr *> (&mySocketAddress));
    listenToMessages(socketFileDescriptor, maximumConnections, port);

    return 0;
}

