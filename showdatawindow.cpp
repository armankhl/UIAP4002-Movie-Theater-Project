#include "showdatawindow.h"
#include "ui_showdatawindow.h"
#include <QFile>
#include "QStringList"
#include "QTextStream"
#include "homewindow.h"

ShowDataWindow::ShowDataWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::ShowDataWindow)
{
	ui->setupUi(this);
	PrintData();
}

ShowDataWindow::~ShowDataWindow()
{
	delete ui;
}

void ShowDataWindow::PrintData()
{
	struct MovieData
	{
		QString Name, Genre, Director, Actors, Release_date, Playin_day, Playing_time,
		Ticket_num ;
	}CMovie;


	QFile file("CurrentMovie.txt");
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









void ShowDataWindow::on_BackButton_clicked()
{
	HomeWindow *HH = new HomeWindow();
	HH->show();
	this->close();
}
