#ifndef REMOVEWINDOW_H
#define REMOVEWINDOW_H

#include <QMainWindow>

namespace Ui {
class RemoveWindow;
}

class RemoveWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit RemoveWindow(QWidget *parent = nullptr);
	~RemoveWindow();


private slots:
	void on_back2Button_clicked();
	void setData();
	void hideEmpty();
	void on_pushButton_1_clicked();

	void on_pushButton_2_clicked();

	void on_pushButton_3_clicked();

	void on_pushButton_4_clicked();

	void on_pushButton_5_clicked();

	void on_pushButton_6_clicked();

	void on_pushButton_7_clicked();

	void on_pushButton_8_clicked();

	void on_pushButton_9_clicked();

private:
	Ui::RemoveWindow *ui;


};

#endif // REMOVEWINDOW_H
