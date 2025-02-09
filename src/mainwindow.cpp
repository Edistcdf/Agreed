#include "mainwindow.h"
#include "chatwindow.h"
#include "contactswindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	QWidget *centralWidget = new QWidget(this);
	setCentralWidget(centralWidget);

	QVBoxLayout *layout = new QVBoxLayout(centralWidget);
	QPushButton *chatButton = new QPushButton("Open Chat", this);
	QPushButton *contactsButton = new QPushButton("Contacts", this);
	layout->addWidget(chatButton);
	layout->addWidget(contactsButton);

	centralWidget->setLayout(layout);

	connect(chatButton, &QPushButton::clicked, this, &MainWindow::openChat);
	connect(contactsButton, &QPushButton::clicked, this, &MainWindow::openContacts);
}

void MainWindow::openChat() {
	ChatWindow *chat = new ChatWindow();
	chat->show();
}

void MainWindow::openContacts() {
	ContactsWindow *contacts = new ContactsWindow();
	contacts->show();
}
