#include "editsearchwindow.h"
#include "ui_editsearchwindow.h"
#include <QFile>
#include "QStringList"
#include "QTextStream"
#include "bosswindow.h"

EditSearchWindow::EditSearchWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::EditSearchWindow)
{
	ui->setupUi(this);
	PrintData();
}

EditSearchWindow::~EditSearchWindow()
{
	delete ui;
}

int CountUsers5()
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

void EditSearchWindow::PrintData()
{
	struct MovieData
	{
		QString Name, Genre, Director, Actors, Release_date, Playin_day, Playing_time,
		Ticket_num ;
	}CMovie;


	QFile file("EditMovie.txt");
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

	ui->NameEntry->setText(CMovie.Name);
	ui->GenreEntry->setText(CMovie.Genre);
	ui->DirEntry->setText(CMovie.Director);
	ui->DateEntry->setText(CMovie.Release_date);
	ui->ActorsEntry->setText(CMovie.Actors);
	ui->DayEntry->setText(CMovie.Playin_day);
	ui->TimeEntry->setText(CMovie.Playing_time);
	ui->TicketEntry->setText(CMovie.Ticket_num);

}

void EditSearchWindow::on_BackButton_clicked()
{
	BossWindow *HH = new BossWindow();
	HH->show();
	this->close();
}

void EditSearchWindow::on_SaveButton_clicked()
{
	QFile xfile(ui->NameEntry->text()+".txt");
	xfile.open(QIODevice::WriteOnly);
	QTextStream in(&xfile);
	in << ui->NameEntry->text() << endl
		  << ui->GenreEntry->text() << endl
			 << ui->DirEntry->text() << endl
				<< ui->ActorsEntry->text() << endl
				   << ui->DateEntry->text() << endl
					  << ui->DayEntry->text() << endl
						 << ui->TimeEntry->text() << endl
							<< ui->TicketEntry->text() << endl;

	xfile.close();

	BossWindow *HH = new BossWindow();
	HH->show();
	this->close();

//	int mnum = CountUsers5();
//	struct Mov
//	{
//		QString Name;
//		int ticket;
//	};

//	Mov *Movy = new Mov[mnum];
//	QFile tfile("Movies.txt");
//	tfile.open(QIODevice::ReadOnly);
//	QTextStream trd(&tfile);
//	tfile.seek(0);
//	for(int i = 0 ; i < mnum ; i++)
//	{
//		Movy[i].Name = trd.readLine();
//		Movy[i].ticket = trd.readLine().toInt();
//	}
//	tfile.close();

//	QFile zfile("Movies.txt");
//	zfile.open(QIODevice::WriteOnly);
//	QTextStream zrd(&xfile);
//	zfile.seek(0);
//	for(int i = 0 ; i < mnum ; i++)
//	{
//		if( Movy[i].Name == ui->NameEntry->text())
//		{
//			zrd << ui->NameEntry->text() << endl
//				<<  ui->TicketEntry->text() << endl;
//		}
//		else
//		{
//			zrd << Movy[i].Name << endl
//				<<  Movy[i].ticket << endl;
//		}
//	}
//	zfile.close();
}
