#ifndef SHOWDATAWINDOW_H
#define SHOWDATAWINDOW_H

#include <QMainWindow>

namespace Ui {
class ShowDataWindow;
}

class ShowDataWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit ShowDataWindow(QWidget *parent = nullptr);
	~ShowDataWindow();

private slots:
	void on_BackButton_clicked();
	void PrintData();

private:
	Ui::ShowDataWindow *ui;

};

#endif // SHOWDATAWINDOW_H
