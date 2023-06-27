#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonMedia_clicked()
{
    mediawindow = new MediaWindow(this);
    mediawindow->show();
}


void MainWindow::on_pushButtonTcpClient_clicked()
{
    clientcpwindow = new ClienTCPWindow(this);
    clientcpwindow->show();
}

