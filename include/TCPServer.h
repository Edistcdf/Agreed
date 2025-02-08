#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <string>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

class TCPServer {
public:
    TCPServer(const std::string& ip, int port);
    ~TCPServer();
    void start();
    void handleClient();

private:
    std::string ip_;
    int port_;
    int server_fd_;
    int client_fd_;
    sockaddr_in server_addr_;
    sockaddr_in client_addr_;
};

#endif // TCPSERVER_H
