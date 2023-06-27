#ifndef CLIENTCPWINDOW_H
#define CLIENTCPWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QStandardItem>
#include <QLineEdit>

namespace Ui {
class ClienTCPWindow;
}

class ClienTCPWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClienTCPWindow(QWidget *parent = nullptr);
    ~ClienTCPWindow();

    QTcpSocket* socket;
    QByteArray Data;
    QJsonDocument doc;
    QJsonParseError docError;
    QString ani_name;

public slots:

    void sockReady();

    void sockDisconnect();

private slots:
    void on_pushButtonConnection_clicked();

    void on_pushButtonFind_clicked();

    void on_pushButtonDownload_clicked();

private:
    Ui::ClienTCPWindow *ui;
};

#endif // CLIENTCPWINDOW_H
