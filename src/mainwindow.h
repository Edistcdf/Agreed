#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

class MainWindow : public QMainWindow {
	Q_OBJECT
	public:
		MainWindow(QWidget *parent = nullptr);

		private slots:
			void openChat();
			void openContacts();
};
