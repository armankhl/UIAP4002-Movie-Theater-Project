#include "bosswindow.h"
#include "ui_bosswindow.h"
#include "addwindow.h"
#include "homewindow.h"
#include "editwindow.h"
#include "removewindow.h"

BossWindow::BossWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::BossWindow)
{
	ui->setupUi(this);
}

BossWindow::~BossWindow()
{
	delete ui;
}

void BossWindow::on_ExitButton_clicked()
{
	this->close();
}

void BossWindow::on_AddButton_clicked()
{
	this->close();
	AddWindow *Main = new AddWindow();
	Main->show();
}

void BossWindow::on_HomeButton_clicked()
{
	this->close();
	HomeWindow *Main = new HomeWindow();
	Main->show();
}

void BossWindow::on_EditButton_clicked()
{
	this->close();
	EditWindow *Main = new EditWindow();
	Main->show();
}

void BossWindow::on_RemoveButton_clicked()
{
	RemoveWindow *Main = new RemoveWindow();
	Main->show();
	this->close();
}
