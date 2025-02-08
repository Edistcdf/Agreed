#include <QMainWindow>
#include "chatwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ChatWindow window;
    window.setWindowTitle("CryptoChat");
    window.show();
    return app.exec();
}
