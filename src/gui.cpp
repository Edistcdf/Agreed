#include <QMainWindow>
#include "chatwindow.h"
#include "mainwindow.h"
#include "TCPClient.h"
#include "TCPServer.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.setWindowTitle("Main Window");
    mainWindow.resize(400, 300);
    mainWindow.show();

    return app.exec();
}
