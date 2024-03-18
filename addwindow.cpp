#include "addwindow.h"
#include "ui_addwindow.h"
#include "QMessageBox"
#include "bosswindow.h"
#include "QString"
#include "QFile"
#include "QStringList"
#include "QTextStream"

AddWindow::AddWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::AddWindow)
{
	ui->setupUi(this);
}

AddWindow::~AddWindow()
{
	delete ui;
}

//struct MovieData
//{
//	QString Name, Genre, Director, Actors, Release_date, Playin_day, Playing_time;
//	int Ticket_num ;
//};

void AddWindow::on_BackButton_clicked()
{
	if(QMessageBox::question(this,"Exit","Are you sure you want to exit? Data wont be saved.","No","Yes")==1)
	  {
		BossWindow *neWM = new BossWindow();
		neWM->show();
		this->close();
	  }
}

void AddWindow::on_SaveButton_clicked()
{
//	MovieData NewMovie;
//	NewMovie.Name = ui->NameEntry->text();
//	NewMovie.Genre = ui->GenreEntry->text();
//	NewMovie.Director = ui->DirEntry->text();
//	NewMovie.Actors = ui->ActorsEntry->text();
//	NewMovie.Release_date = ui->DateEntry->text();
//	NewMovie.Playin_day = ui->DayEntry->text();
//	NewMovie.Playing_time = ui->TimeEntry->text();
//	NewMovie.Ticket_num = ui->TicketEntry->text().toInt();

	//save data
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

	QFile file("Movies.txt");
	file.open(QIODevice::Append);
	QTextStream inn(&file);
	inn << ui->NameEntry->text() << endl <<  ui->TicketEntry->text() << endl;
	file.close();

	BossWindow *neWM = new BossWindow();
	neWM->show();
	this->close();

}
