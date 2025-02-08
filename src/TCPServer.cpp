#include "TCPServer.h"
#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <thread>

TCPServer::TCPServer(const std::string& ip, int port)
	: ip_(ip), port_(port), server_fd_(-1), client_fd_(-1) {
		if ((server_fd_ = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
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

		if (bind(server_fd_, (struct sockaddr *)&server_addr_, sizeof(server_addr_)) == -1) {
			perror("Binding failed");
			exit(1);
		}

		if (listen(server_fd_, 3) == -1) {
			perror("Listen failed");
			exit(1);
		}
	}

TCPServer::~TCPServer() {
	if (client_fd_ != -1) {
		close(client_fd_);
	}
	if (server_fd_ != -1) {
		close(server_fd_);
	}
}

void TCPServer::start() {
	std::thread server_thread(&TCPServer::handleClient, this);
	server_thread.detach();
}
void TCPServer::handleClient() {
	socklen_t addr_len = sizeof(client_addr_);
	client_fd_ = accept(server_fd_, (struct sockaddr *)&client_addr_, &addr_len);
	if (client_fd_ == -1) {
		perror("Accept failed");
		abort();
	}

	while (true) {
		char buffer[1024];
		memset(buffer, 0, 1024);
		int bytes_read;
		while ((bytes_read = recv(client_fd_, buffer, sizeof(buffer), 0)) > 0) {
			memset(buffer, 0, bytes_read);
		}

		if (bytes_read == -1) {
			perror("Recv failed");
			break;
		}
	}

	close(client_fd_);
	client_fd_ = -1;
}
