#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <string>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

class TCPClient {
public:
    TCPClient(const std::string& ip, int port);
    ~TCPClient();
    void connectToServer();
    void communicate(std::string msg);

private:
    std::string ip_;
    int port_;
    int sock_;
    sockaddr_in server_addr_;
};

#endif // TCPCLIENT_H
