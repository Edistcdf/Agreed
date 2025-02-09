#ifndef CONTACTSWINDOW_H
#define CONTACTSWINDOW_H

#include <QCloseEvent>
#include <QLabel>
#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>

class ContactsWindow : public QWidget {
	Q_OBJECT

	public:
		ContactsWindow(QWidget *parent = nullptr);
		~ContactsWindow();
	protected:
		void closeEvent(QCloseEvent *event) override;
};

#endif // CONTACTSWINDOW_H
