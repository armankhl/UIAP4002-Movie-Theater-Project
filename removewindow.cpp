#include "removewindow.h"
#include "ui_removewindow.h"
#include <QFile>
#include "QStringList"
#include "QTextStream"
#include "bosswindow.h"
#include "removesearchwindow.h"

RemoveWindow::RemoveWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::RemoveWindow)
{
	ui->setupUi(this);
	setData();
	hideEmpty();
}

RemoveWindow::~RemoveWindow()
{
	delete ui;

}

int CountUsers3()
{
	int n = 0;
	QFile file("Movies.txt");
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

void RemoveWindow::setData()
{
	int Mnum = CountUsers3();
	QString Movie[Mnum];
	int i=0;
	QFile file("Movies.txt");
	file.open(QIODevice::ReadOnly);
	QTextStream rd(&file);
	file.seek(0);
	for(i=0 ; i < Mnum ; i++)
	{
		Movie[i] = rd.readLine();
		rd.readLine();
	}
	file.close();

	i=0;
	while(i < Mnum)
	{
		ui->label_1->setText(Movie[0]); i++;
		if(i == Mnum) break;
		ui->label_1->setText(Movie[1]); i++;
		if(i == Mnum) break;
		ui->label_2->setText(Movie[2]); i++;
		if(i == Mnum) break;
		ui->label_3->setText(Movie[3]); i++;
		if(i == Mnum) break;
		ui->label_4->setText(Movie[4]); i++;
		if(i == Mnum) break;
		ui->label_5->setText(Movie[5]); i++;
		if(i == Mnum) break;
		ui->label_6->setText(Movie[6]); i++;
		if(i == Mnum) break;
		ui->label_7->setText(Movie[7]); i++;
		if(i == Mnum) break;
		ui->label_8->setText(Movie[8]); i++;
		break;
	}
}

void RemoveWindow::hideEmpty()
{
	if(ui->label_1->text() == nullptr)
	{
		ui->pushButton_1->hide();
	}
	if(ui->label_2->text() == nullptr)
	{
		ui->pushButton_2->hide();
	}
	if(ui->label_3->text() == nullptr)
	{
		ui->pushButton_3->hide();
	}
	if(ui->label_4->text() == nullptr)
	{
		ui->pushButton_4->hide();
	}
	if(ui->label_5->text() == nullptr)
	{
		ui->pushButton_5->hide();
	}
	if(ui->label_6->text() == nullptr)
	{
		ui->pushButton_6->hide();
	}
	if(ui->label_7->text() == nullptr)
	{
		ui->pushButton_7->hide();
	}
	if(ui->label_8->text() == nullptr)
	{
		ui->pushButton_8->hide();
	}
	if(ui->label_9->text() == nullptr)
	{
		ui->pushButton_9->hide();
	}
}

void RemoveWindow::on_back2Button_clicked()
{
	this->close();
	BossWindow *neWM = new BossWindow();
	neWM->show();

}

void RemoveWindow::on_pushButton_1_clicked()
{
	QFile bfile("RemoveMovie.txt");
	bfile.open(QIODevice::WriteOnly);
	QTextStream bin(&bfile);
	bin << ui->label_1->text() << endl;
	bfile.close();

	RemoveSearchWindow *NbM = new RemoveSearchWindow();
	NbM->show();
	this->close();
}

void RemoveWindow::on_pushButton_2_clicked()
{
	QFile bfile("RemoveMovie.txt");
	bfile.open(QIODevice::WriteOnly);
	QTextStream bin(&bfile);
	bin << ui->label_2->text() << endl;
	bfile.close();

	RemoveSearchWindow *NbM = new RemoveSearchWindow();
	NbM->show();
	this->close();
}

void RemoveWindow::on_pushButton_3_clicked()
{
	QFile bfile("RemoveMovie.txt");
	bfile.open(QIODevice::WriteOnly);
	QTextStream bin(&bfile);
	bin << ui->label_3->text() << endl;
	bfile.close();

	RemoveSearchWindow *NbM = new RemoveSearchWindow();
	NbM->show();
	this->close();
}

void RemoveWindow::on_pushButton_4_clicked()
{
	QFile bfile("RemoveMovie.txt");
	bfile.open(QIODevice::WriteOnly);
	QTextStream bin(&bfile);
	bin << ui->label_4->text() << endl;
	bfile.close();

	RemoveSearchWindow *NbM = new RemoveSearchWindow();
	NbM->show();
	this->close();
}

void RemoveWindow::on_pushButton_5_clicked()
{
	QFile bfile("RemoveMovie.txt");
	bfile.open(QIODevice::WriteOnly);
	QTextStream bin(&bfile);
	bin << ui->label_5->text() << endl;
	bfile.close();

	RemoveSearchWindow *NbM = new RemoveSearchWindow();
	NbM->show();
	this->close();
}

void RemoveWindow::on_pushButton_6_clicked()
{
	QFile bfile("RemoveMovie.txt");
	bfile.open(QIODevice::WriteOnly);
	QTextStream bin(&bfile);
	bin << ui->label_6->text() << endl;
	bfile.close();

	RemoveSearchWindow *NbM = new RemoveSearchWindow();
	NbM->show();
	this->close();
}

void RemoveWindow::on_pushButton_7_clicked()
{
	QFile bfile("RemoveMovie.txt");
	bfile.open(QIODevice::WriteOnly);
	QTextStream bin(&bfile);
	bin << ui->label_7->text() << endl;
	bfile.close();

	RemoveSearchWindow *NbM = new RemoveSearchWindow();
	NbM->show();
	this->close();
}

void RemoveWindow::on_pushButton_8_clicked()
{
	QFile bfile("RemoveMovie.txt");
	bfile.open(QIODevice::WriteOnly);
	QTextStream bin(&bfile);
	bin << ui->label_8->text() << endl;
	bfile.close();

	RemoveSearchWindow *NbM = new RemoveSearchWindow();
	NbM->show();
	this->close();
}

void RemoveWindow::on_pushButton_9_clicked()
{
	QFile bfile("RemoveMovie.txt");
	bfile.open(QIODevice::WriteOnly);
	QTextStream bin(&bfile);
	bin << ui->label_9->text() << endl;
	bfile.close();

	RemoveSearchWindow *NbM = new RemoveSearchWindow();
	NbM->show();
	this->close();
}
