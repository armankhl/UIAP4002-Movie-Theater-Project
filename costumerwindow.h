#ifndef COSTUMERWINDOW_H
#define COSTUMERWINDOW_H

#include <QMainWindow>

namespace Ui {
class CostumerWindow;
}

class CostumerWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit CostumerWindow(QWidget *parent = nullptr);
	~CostumerWindow();

private slots:
    void on_exit_clicked();

    void on_reserve_clicked();

    void on_history_clicked();

private:
	Ui::CostumerWindow *ui;
};

#endif // COSTUMERWINDOW_H
