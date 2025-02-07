#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDebug>

class ChatWindow : public QWidget {
    Q_OBJECT

public:
    ChatWindow(QWidget *parent = nullptr) : QWidget(parent) {
        textInput = new QLineEdit(this);
        textInput->setPlaceholderText("write...");
        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(textInput);
        setLayout(layout);

        connect(textInput, &QLineEdit::returnPressed, this, &ChatWindow::onEnterPressed);
    }

private slots:
    void onEnterPressed() {
        QString inputText = textInput->text();
        if (!inputText.isEmpty()) {
            qDebug() << "text: " << inputText;
            textInput->clear();
        }
    }

private:
    QLineEdit *textInput;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ChatWindow window;
    window.setWindowTitle("CryptoChat");
    window.show();
    return app.exec();
}

#include "gui.moc"
