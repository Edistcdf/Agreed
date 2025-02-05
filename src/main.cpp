#include <QApplication>
#include <QWidget>
#include <QLabel>

int main(int argc, char *argv[]) {
    // Create the Qt application object
    QApplication app(argc, argv);

    // Create a QWidget as the main window
    QWidget window;

    // Create a label and set its text
    QLabel *label = new QLabel("Hello, World!", &window);
    label->move(100, 50);  // Move the label to a specific location within the window

    // Set the window size and show the window
    window.resize(300, 200);
    window.setWindowTitle("Hello World in Qt");
    window.show();

    // Enter the Qt event loop
    return app.exec();
}
