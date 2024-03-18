#include "removesearchwindow.h"
#include "ui_removesearchwindow.h"
#include "QFile"
#include "QStringList"
#include "QTextStream"
#include "homewindow.h"
#include "QMessageBox"
#include "removewindow.h"

RemoveSearchWindow::RemoveSearchWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::RemoveSearchWindow)
{
	ui->setupUi(this);
	PrintData();
}

RemoveSearchWindow::~RemoveSearchWindow()
{
	delete ui;
}

int CountUsers0()
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

void RemoveSearchWindow::PrintData()
{
	struct MovieData
	{
		QString Name, Genre, Director, Actors, Release_date, Playin_day, Playing_time,
		Ticket_num ;
	}CMovie;


	QFile file("RemoveMovie.txt");
	file.open(QIODevice::ReadOnly);
	QTextStream rd(&file);
	file.seek(0);
	CMovie.Name = rd.readLine();
	file.close();

	QFile cfile(CMovie.Name+".txt");
	cfile.open(QIODevice::ReadOnly);
	QTextStream brd(&cfile);
	cfile.seek(0);
	brd.readLine();
	CMovie.Genre = brd.readLine();
	CMovie.Director = brd.readLine();
	CMovie.Actors = brd.readLine();
	CMovie.Release_date = brd.readLine();
	CMovie.Playin_day = brd.readLine();
	CMovie.Playing_time = brd.readLine();
	CMovie.Ticket_num = brd.readLine();
	cfile.close();

	ui->Name_label->setText(CMovie.Name+" Movie");
	ui->Genre_label->setText(CMovie.Genre);
	ui->Director_label->setText(CMovie.Director);
	ui->RDate_label->setText(CMovie.Release_date);
	ui->Actors_label->setText(CMovie.Actors);
	ui->Day_label->setText(CMovie.Playin_day);
	ui->Time_label->setText(CMovie.Playing_time);
	ui->TicketEntry->setText(CMovie.Ticket_num);

}

void RemoveSearchWindow::on_BackButton_clicked()
{
	RemoveWindow *XX = new RemoveWindow();
	XX->show();
	this->close();
}



void RemoveSearchWindow::on_RemoveButton_clicked()
{
	if(QMessageBox::question(this,"Remove","Are you sure you want to Remove this movie?","No","Yes")==1)
	{

		int MovieNum;
		struct MovieData
		{
			QString Name ;
		}CMovie;
		struct MovieDataa
		{
			QString Name ;
			QString ticket;
		};
		QFile file("RemoveMovie.txt");
		file.open(QIODevice::ReadOnly);
		QTextStream rd(&file);
		file.seek(0);
		CMovie.Name = rd.readLine();
		file.close();

		QFile cfile(CMovie.Name+".txt");
		cfile.remove();
		cfile.close();

		MovieNum = CountUsers0();
		MovieDataa *XMovie = new MovieDataa[MovieNum];

		QFile xfile("Movies.txt");
		xfile.open(QIODevice::ReadOnly);
		QTextStream xrd(&xfile);
		xfile.seek(0);
		for(int i = 0 ; i < MovieNum ; i++)
		{
			XMovie[i].Name = xrd.readLine();
			XMovie[i].ticket = xrd.readLine();
		}
		xfile.close();

		QFile zfile("Movies.txt");
		zfile.open(QIODevice::WriteOnly);
		QTextStream zrd(&xfile);
		zfile.seek(0);
		for(int i = 0 ; i < MovieNum ; i++)
		{
			if( XMovie[i].Name == CMovie.Name) continue;

			zrd << XMovie[i].Name << endl
				<<  XMovie[i].ticket << endl;
		}
		zfile.close();

		RemoveWindow *XX = new RemoveWindow();
		XX->show();
		this->close();
	}
}
