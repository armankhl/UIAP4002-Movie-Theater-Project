#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QMainWindow>

namespace Ui {
class SearchWindow;
}

class SearchWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit SearchWindow(QWidget *parent = nullptr);
	~SearchWindow();


private slots:
	void on_BackButton_clicked();
	void PrintData();

private:
	Ui::SearchWindow *ui;
};

#endif // SEARCHWINDOW_H
