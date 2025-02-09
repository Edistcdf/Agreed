#include <iostream>
#include "contactswindow.h"

ContactsWindow::ContactsWindow(QWidget *parent) :
       	QWidget(parent)
{
	setWindowTitle("Contacts");
        resize(300, 200);
        setAttribute(Qt::WA_StyledBackground);
        setStyleSheet("background-color: #f0f0f0; border-radius: 15px;");

        QVBoxLayout *layout = new QVBoxLayout(this);
        QLabel *label = new QLabel("Contacts", this);
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet("font-size: 18px; font-weight: bold;");

        QPushButton *addButton = new QPushButton("Add", this);
        QPushButton *removeButton = new QPushButton("Remove", this);

        addButton->setStyleSheet("background-color: #4CAF50; color: white; border-radius: 10px; padding: 5px;");
        removeButton->setStyleSheet("background-color: #FF5733; color: white; border-radius: 10px; padding: 5px;");

        layout->addWidget(label);
        layout->addWidget(addButton);
        layout->addWidget(removeButton);
        setLayout(layout);
}

ContactsWindow::~ContactsWindow() {
	std::cout <<  "dtor invoked.." << std::endl;
}

void ContactsWindow::closeEvent(QCloseEvent *event) {
	deleteLater();
	event->accept();
}
