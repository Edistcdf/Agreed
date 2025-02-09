#include "TCPClient.h"
#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

TCPClient::TCPClient(const std::string& ip, int port)
    : ip_(ip), port_(port), sock_(-1) {
    if ((sock_ = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    memset(&server_addr_, 0, sizeof(server_addr_));
    server_addr_.sin_family = AF_INET;
    server_addr_.sin_port = htons(port_);
    
    if (inet_pton(AF_INET, ip_.c_str(), &server_addr_.sin_addr) <= 0) {
        perror("Invalid address");
        exit(1);
    }
}

TCPClient::~TCPClient() {
    if (sock_ != -1) {
        close(sock_);
    }
}

void TCPClient::connectToServer() {
    if (connect(sock_, (struct sockaddr *)&server_addr_, sizeof(server_addr_)) == -1) {
        perror("Connection failed");
        exit(1);
    }
}

void TCPClient::communicate(std::string msg) {
	char buffer[1024];
	memset(buffer, 0, 1024);
	memcpy(buffer, msg.c_str(), msg.length());
	send(sock_, buffer, strlen(buffer), 0);
}
