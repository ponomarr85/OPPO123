#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    authWindow = new Auth(this);

    int res = authWindow->exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

