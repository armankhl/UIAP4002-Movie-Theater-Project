#ifndef REMOVESEARCHWINDOW_H
#define REMOVESEARCHWINDOW_H

#include <QMainWindow>

namespace Ui {
class RemoveSearchWindow;
}

class RemoveSearchWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit RemoveSearchWindow(QWidget *parent = nullptr);
	~RemoveSearchWindow();

private slots:
	void on_BackButton_clicked();
	void PrintData();

	void on_RemoveButton_clicked();

private:
	Ui::RemoveSearchWindow *ui;
};

#endif // REMOVESEARCHWINDOW_H
