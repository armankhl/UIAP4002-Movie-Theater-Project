#include "homewindow.h"
#include "ui_homewindow.h"
#include <QFile>
#include "QStringList"
#include "QTextStream"
#include "QMessageBox"
#include "bosswindow.h"
#include "searchwindow.h"
#include "showdatawindow.h"

HomeWindow::HomeWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::HomeWindow)
{
	ui->setupUi(this);
	setData();
	hideEmpty();
}

HomeWindow::~HomeWindow()
{
	delete ui;
}

int CountUsers2()
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

void HomeWindow::setData()
{
	int Mnum = CountUsers2();
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

void HomeWindow::hideEmpty()
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

void HomeWindow::on_backButton_clicked()
{
	BossWindow *neWM = new BossWindow();
	neWM->show();
	this->close();
}

void HomeWindow::on_searchButton_clicked()
{
	QString Sch = ui->Search_line->text();
	QFile xfile("SearchedWord.txt");
	xfile.open(QIODevice::WriteOnly);
	QTextStream in(&xfile);
	in << Sch << endl;
	xfile.close();

	SearchWindow *NbM = new SearchWindow();
	NbM->show();
	this->close();
}

void HomeWindow::on_pushButton_1_clicked()
{
	QFile bfile("CurrentMovie.txt");
	bfile.open(QIODevice::WriteOnly);
	QTextStream bin(&bfile);
	bin << ui->label_1->text() << endl;
	bfile.close();

	ShowDataWindow *NM = new ShowDataWindow();
	NM->show();
	this->close();
}

void HomeWindow::on_pushButton_2_clicked()
{
	QFile bfile("CurrentMovie.txt");
	bfile.open(QIODevice::WriteOnly);
	QTextStream bin(&bfile);
	bin << ui->label_2->text() << endl;
	bfile.close();

	ShowDataWindow *NM = new ShowDataWindow();
	NM->show();
	this->close();
}

void HomeWindow::on_pushButton_3_clicked()
{
	QFile bfile("CurrentMovie.txt");
	bfile.open(QIODevice::WriteOnly);
	QTextStream bin(&bfile);
	bin << ui->label_3->text() << endl;
	bfile.close();

	ShowDataWindow *NM = new ShowDataWindow();
	NM->show();
	this->close();
}

void HomeWindow::on_pushButton_4_clicked()
{
	QFile bfile("CurrentMovie.txt");
	bfile.open(QIODevice::WriteOnly);
	QTextStream bin(&bfile);
	bin << ui->label_4->text() << endl;
	bfile.close();

	ShowDataWindow *NM = new ShowDataWindow();
	NM->show();
	this->close();
}

void HomeWindow::on_pushButton_5_clicked()
{
	QFile bfile("CurrentMovie.txt");
	bfile.open(QIODevice::WriteOnly);
	QTextStream bin(&bfile);
	bin << ui->label_5->text() << endl;
	bfile.close();

	ShowDataWindow *NM = new ShowDataWindow();
	NM->show();
	this->close();
}


void HomeWindow::on_pushButton_6_clicked()
{
	QFile bfile("CurrentMovie.txt");
	bfile.open(QIODevice::WriteOnly);
	QTextStream bin(&bfile);
	bin << ui->label_6->text() << endl;
	bfile.close();

	ShowDataWindow *NM = new ShowDataWindow();
	NM->show();
	this->close();
}

void HomeWindow::on_pushButton_7_clicked()
{
	QFile bfile("CurrentMovie.txt");
	bfile.open(QIODevice::WriteOnly);
	QTextStream bin(&bfile);
	bin << ui->label_7->text() << endl;
	bfile.close();

	ShowDataWindow *NM = new ShowDataWindow();
	NM->show();
	this->close();
}

void HomeWindow::on_pushButton_8_clicked()
{
	QFile bfile("CurrentMovie.txt");
	bfile.open(QIODevice::WriteOnly);
	QTextStream bin(&bfile);
	bin << ui->label_8->text() << endl;
	bfile.close();

	ShowDataWindow *NM = new ShowDataWindow();
	NM->show();
	this->close();
}

void HomeWindow::on_pushButton_9_clicked()
{
	QFile bfile("CurrentMovie.txt");
	bfile.open(QIODevice::WriteOnly);
	QTextStream bin(&bfile);
	bin << ui->label_9->text() << endl;
	bfile.close();

	ShowDataWindow *NM = new ShowDataWindow();
	NM->show();
	this->close();
}
