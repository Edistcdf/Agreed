#include "chatwindow.h"

ChatWindow::ChatWindow(QWidget *parent) : QWidget(parent) {
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
		qDebug() << "text: " << inputText;
		textInput->clear();
	}
}
