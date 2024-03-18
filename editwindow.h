#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QMainWindow>

namespace Ui {
class EditWindow;
}

class EditWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit EditWindow(QWidget *parent = nullptr);
	~EditWindow();

private slots:
	void on_backButton_clicked();
	void setData();
	void hideEmpty();
	void on_pushButton_1_clicked();

	void on_pushButton_2_clicked();

	void on_pushButton_3_clicked();

	void on_pushButton_4_clicked();

private:
	Ui::EditWindow *ui;

};

#endif // EDITWINDOW_H
