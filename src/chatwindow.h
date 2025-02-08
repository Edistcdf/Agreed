#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDebug>

class ChatWindow : public QWidget {
    Q_OBJECT

public:
    ChatWindow(QWidget *parent = nullptr);

private slots:
    void onEnterPressed();

private:
    QLineEdit *textInput;
};

#include "gui.moc"
#endif // CHATWINDOW_H
