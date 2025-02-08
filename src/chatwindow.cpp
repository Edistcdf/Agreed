#include "chatwindow.h"
#include "TCPServer.h"
#include "TCPClient.h"
#include "chatwindow.moc"
ChatWindow::ChatWindow(QWidget *parent) : QWidget(parent), server_("127.0.0.1", 8080), client_("127.0.0.1", 8080){
	server_.start();
	client_.connectToServer();
	textInput = new QLineEdit(this);
	textInput->setPlaceholderText("write...");
	QVBoxLayout *layout = new QVBoxLayout();
	layout->addWidget(textInput);
	setLayout(layout);

	connect(textInput, &QLineEdit::returnPressed, this, &ChatWindow::onEnterPressed);
}

void ChatWindow::onEnterPressed() {
	QString inputText = textInput->text();
	if (!inputText.isEmpty()) {
		client_.communicate(inputText.toStdString());
		qDebug() << "text: " << inputText;
		textInput->clear();
	}
}

