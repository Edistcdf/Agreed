#include "sender.h"
#include <iostream>

int main() {
    const std::string ip = "127.0.0.1";
    const uint16_t port = 8080;

    UDPSender sender(ip, port);

    std::string message = "Hello, UDP!";
    if (sender.sendMessage(message)) {
        std::cout << "Message sent successfully!\n";
    } else {
        std::cerr << "Failed to send message.\n";
    }

    return 0;
}
