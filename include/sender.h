#ifndef UDP_SENDER_H
#define UDP_SENDER_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>

class UDPSender {
public:
    UDPSender(const std::string& address, uint16_t port);
    ~UDPSender();

    bool sendMessage(const std::string& message);

private:
    int sockfd;
    struct sockaddr_in serverAddr;
};

#endif // UDP_SENDER_H
