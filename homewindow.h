#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>

namespace Ui {
class HomeWindow;
}

class HomeWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit HomeWindow(QWidget *parent = nullptr);
	~HomeWindow();

private slots:
	void on_pushButton_1_clicked();
	void on_backButton_clicked();
	void setData();
	void hideEmpty();

	void on_searchButton_clicked();

	void on_pushButton_2_clicked();

	void on_pushButton_3_clicked();

	void on_pushButton_4_clicked();

	void on_pushButton_5_clicked();

	void on_pushButton_6_clicked();

	void on_pushButton_7_clicked();

	void on_pushButton_8_clicked();

	void on_pushButton_9_clicked();

private:
	Ui::HomeWindow *ui;
};

#endif // HOMEWINDOW_H
