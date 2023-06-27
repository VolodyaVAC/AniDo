#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "clientcpwindow.h"
#include "mediawindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonMedia_clicked();

    void on_pushButtonTcpClient_clicked();

private:
    Ui::MainWindow *ui;
    ClienTCPWindow* clientcpwindow;
    MediaWindow* mediawindow;
};
#endif // MAINWINDOW_H
