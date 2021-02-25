#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainUI = new mainui();
    mainUI->resize(400,400);
    mainUI->show();

}

MainWindow::~MainWindow()
{
}

