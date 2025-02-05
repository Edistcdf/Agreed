#include "client.h"
#include <netinet/in.h>
#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

UDPSender::UDPSender(const std::string& address, uint16_t port) {
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);

    if (inet_pton(AF_INET, address.c_str(), &serverAddr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
    }
}

UDPSender::~UDPSender() {
    if (sockfd >= 0) {
        close(sockfd);
    }
}

bool UDPSender::sendMessage(const std::string& message) {
    ssize_t sent_bytes = sendto(sockfd, message.c_str(), message.size(), 0,
                                (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if (sent_bytes < 0) {
        perror("Send failed");
        return false;
    }
    return true;
}
