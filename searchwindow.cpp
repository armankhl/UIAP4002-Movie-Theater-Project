#include "searchwindow.h"
#include "ui_searchwindow.h"
#include "QStringList"
#include "QTextStream"
#include <QFile>
#include "homewindow.h"

SearchWindow::SearchWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::SearchWindow)
{
	ui->setupUi(this);
	PrintData();
}

SearchWindow::~SearchWindow()
{
	delete ui;
}

int CountMovies2()
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

void SearchWindow::PrintData()
{
	struct MovieData
	{
		QString Name, Genre, Director, Actors, Release_date, Playin_day, Playing_time,Ticket_num ;
	};
	bool found = false;
	QString SearchedWord;
	QFile file("SearchedWord.txt");
	file.open(QIODevice::ReadOnly);
	QTextStream rd(&file);
	file.seek(0);
	SearchedWord = rd.readLine();
	file.close();

	int Mnum = CountMovies2();

	MovieData *SMovie = new MovieData[Mnum];

	QFile bfile("Movies.txt");
	bfile.open(QIODevice::ReadOnly);
	QTextStream brd(&bfile);
	bfile.seek(0);
	for(int i = 0 ; i < Mnum ; i++)
	{
		SMovie[i].Name = brd.readLine();
		brd.readLine();
	}
	bfile.close();

	for(int i = 0 ; i < Mnum ; i++)
	{
		QFile cfile(SMovie[i].Name+".txt");
		cfile.open(QIODevice::ReadOnly);
		QTextStream crd(&cfile);
		crd.readLine();
		SMovie[i].Genre = crd.readLine();
		SMovie[i].Director = crd.readLine();
		SMovie[i].Actors = crd.readLine();
		SMovie[i].Release_date = crd.readLine();
		SMovie[i].Playin_day = crd.readLine();
		SMovie[i].Playing_time = crd.readLine();
		SMovie[i].Ticket_num = crd.readLine();
		cfile.close();
	}
	int i = 0;
	for(i = 0 ; i < Mnum ; i++)
	{
		if(SearchedWord == SMovie[i].Name)
		{
			found = true;
			break;
		}
		if(SearchedWord == SMovie[i].Genre)
		{
			found = true;
			break;
		}
		if(SearchedWord == SMovie[i].Director)
		{
			found = true;
			break;
		}
		if(SearchedWord == SMovie[i].Actors)
		{
			found = true;
			break;
		}
	}

	if(!found)
	{
		ui->Name_label->setText("NO MOVIE FOUND");
		ui->label_1->hide();
		ui->label_2->hide();
		ui->label_3->hide();
		ui->label_4->hide();
		ui->label_5->hide();
		ui->label_6->hide();
		ui->TicketEntry->hide();
	}

	else
	{
		ui->Name_label->setText(SMovie[i].Name+" Movie");
		ui->Genre_label->setText(SMovie[i].Genre);
		ui->Director_label->setText(SMovie[i].Director);
		ui->RDate_label->setText(SMovie[i].Release_date);
		ui->Actors_label->setText(SMovie[i].Actors);
		ui->Day_label->setText(SMovie[i].Playin_day);
		ui->Time_label->setText(SMovie[i].Playing_time);
		ui->TicketEntry->setText(SMovie[i].Ticket_num);
	}

}
void SearchWindow::on_BackButton_clicked()
{
	HomeWindow *neWM = new HomeWindow();
	neWM->show();
	this->close();
}
