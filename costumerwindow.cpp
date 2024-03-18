#include "costumerwindow.h"
#include "ui_costumerwindow.h"
#include "mainwindow.h"
#include "reservewindow.h"
#include "historywindow.h"

CostumerWindow::CostumerWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::CostumerWindow)
{
	ui->setupUi(this);
}

CostumerWindow::~CostumerWindow()
{
	delete ui;
}

void CostumerWindow::on_exit_clicked()
{
    this->close();
    MainWindow *bazgasht = new MainWindow();
    bazgasht->show();
}

void CostumerWindow::on_reserve_clicked()
{
    this->close();
    ReserveWindow *reserve = new ReserveWindow();
    reserve->show();
}

void CostumerWindow::on_history_clicked()
{
    this->close();
    HistoryWindow *history = new HistoryWindow();
    history->show();
}
