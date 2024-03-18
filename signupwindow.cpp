#include "signupwindow.h"
#include "ui_signupwindow.h"
#include <QFile>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include "costumerwindow.h"

SignUpWindow::SignUpWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::SignUpWindow)
{
	ui->setupUi(this);
}

SignUpWindow::~SignUpWindow()
{
	delete ui;
}

void SignUpWindow::on_SignButton_clicked()
{
	QString PlayerUsername = ui->UsernameEntry->text();
	QString PlayerPass = ui->PasswordEntry->text();
	QString PlayerPhone = ui->PhoneEntry->text();

	//check lines:
	if(PlayerUsername == nullptr || PlayerPass == nullptr || PlayerPhone == nullptr)
	{
		ui->InvalidLabel->setText("Please Fill All Of The Items");
	}
	else
	{
		QFile xfile("UserList.txt");
		xfile.open(QIODevice::Append);
		QTextStream in(&xfile);
		in << PlayerUsername << endl<< PlayerPass << endl;
		xfile.close();

		this->close();
		CostumerWindow *Nmain = new CostumerWindow();
		Nmain->show();
	}
}
