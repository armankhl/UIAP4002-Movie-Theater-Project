#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QMainWindow>

namespace Ui {
class AddWindow;
}

class AddWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit AddWindow(QWidget *parent = nullptr);
	~AddWindow();

private slots:
	void on_BackButton_clicked();

	void on_SaveButton_clicked();

private:
	Ui::AddWindow *ui;
};

#endif // ADDWINDOW_H
