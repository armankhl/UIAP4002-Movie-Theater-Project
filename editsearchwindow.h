#ifndef EDITSEARCHWINDOW_H
#define EDITSEARCHWINDOW_H

#include <QMainWindow>

namespace Ui {
class EditSearchWindow;
}

class EditSearchWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit EditSearchWindow(QWidget *parent = nullptr);
	~EditSearchWindow();

private slots:
	void on_pushButton_clicked();
	void on_BackButton_clicked();
	void PrintData();

	void on_SaveButton_clicked();

private:
	Ui::EditSearchWindow *ui;
};

#endif // EDITSEARCHWINDOW_H
