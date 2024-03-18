#ifndef RESERVEWINDOW_H
#define RESERVEWINDOW_H

#include <QMainWindow>

namespace Ui {
class ReserveWindow;
}

class ReserveWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReserveWindow(QWidget *parent = 0);
    ~ReserveWindow();

private:
    Ui::ReserveWindow *ui;
};

#endif // RESERVEWINDOW_H
