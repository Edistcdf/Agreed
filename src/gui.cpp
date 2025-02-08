#include <QMainWindow>
#include "chatwindow.h"
#include "TCPClient.h"
#include "TCPServer.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ChatWindow window;
    window.setWindowTitle("CryptoChat");
    window.show();
    return app.exec();
}
