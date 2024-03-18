#ifndef BOSSWINDOW_H
#define BOSSWINDOW_H

#include <QMainWindow>

namespace Ui {
class BossWindow;
}

class BossWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit BossWindow(QWidget *parent = nullptr);
	~BossWindow();

private slots:
	void on_ExitButton_clicked();

	void on_AddButton_clicked();

	void on_HomeButton_clicked();

	void on_EditButton_clicked();

	void on_RemoveButton_clicked();

private:
	Ui::BossWindow *ui;
};

#endif // BOSSWINDOW_H
