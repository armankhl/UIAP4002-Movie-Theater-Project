#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include "QStringList"
#include "QTextStream"
#include "bosswindow.h"
#include "costumerwindow.h"
#include "signupwindow.h"
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QFile xfile("BossData.txt");
	xfile.open(QIODevice::WriteOnly);
	QTextStream in(&xfile);
	in << "unison" << endl<< "11228" << endl;
	xfile.close();
}

MainWindow::~MainWindow()
{
	delete ui;
}

int CountUsers()
{
	int n = 0;
	QFile file("UserList.txt");
	file.open(QIODevice::ReadOnly);
	QTextStream rd(&file);
	while(!rd.atEnd())
	{
		n++;
		rd.readLine();
	}
	file.close();

	return n/2 ;
}


void MainWindow::on_LogInButton_clicked()
{
	QString PlayerUsername = ui->UsernameEntry->text();
	QString PlayerPass = ui->PasswordEntry->text();

	if(PlayerUsername == "unison" && PlayerPass == "11228")
	{
		this->close();
		BossWindow *newmain= new BossWindow();
		newmain->show();
	}

	else
	{
		int UNum = CountUsers() ;
		struct UserData
		{
			QString Name;
			QString Pass;
		};
		bool NewUser = true;
		UserData *User = new UserData[UNum];

		QFile file("UserList.txt");
		file.open(QIODevice::ReadOnly);
		QTextStream rd(&file);
		file.seek(0);
		for(int i = 0 ; i < UNum ; i++)
		{
			User[i].Name = rd.readLine();
			User[i].Pass = rd.readLine();
		}
		file.close();

		for(int i = 0 ; i < UNum ; i++)
		{
			if(User[i].Name == PlayerUsername && User[i].Pass == PlayerPass)
			{
				NewUser = false;
				break;
			}
		}

		if(NewUser)
		{
			ui->InvalidLabel->setText("Invalid username/password");
		}
		else
		{
			this->close();
			CostumerWindow *Newmain= new CostumerWindow();
			Newmain->show();
		}
	}

}

void MainWindow::on_SignButton_clicked()
{
	this->close();
	SignUpWindow *FreshMain = new SignUpWindow();
	FreshMain->show();
}
