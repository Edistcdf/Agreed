#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QCloseEvent>
#include <QLabel>
#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDebug>
#include "TCPServer.h"
#include "TCPClient.h"

class ChatWindow : public QWidget {
	Q_OBJECT

	public:
		ChatWindow(QWidget *parent = nullptr);
		~ChatWindow();
protected:
    void closeEvent(QCloseEvent *event) override;

		private slots:
			void onEnterPressed();

	private:
		TCPServer server_;
		TCPClient client_;
		QLineEdit *textInput;
};

#endif // CHATWINDOW_H
