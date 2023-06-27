#include "clientcpwindow.h"
#include "ui_clientcpwindow.h"

ClienTCPWindow::ClienTCPWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClienTCPWindow)
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);
        connect(socket, SIGNAL(readyRead()), this, SLOT(sockReady()));
        connect(socket, SIGNAL(disconnected()), this, SLOT(sockDisconnect()));
        qDebug() << "hello socket";
}

ClienTCPWindow::~ClienTCPWindow()
{
    delete ui;
}

void ClienTCPWindow::sockReady() // принятые данные
{
    if (socket->waitForConnected(2000))
    {
        socket->waitForReadyRead(2000);
        Data = socket->readAll();

        doc = QJsonDocument::fromJson(Data, &docError);

        if (docError.errorString() == "no error occurred")
        {
            if ((doc.object().value("type").toString() == "connect") && (doc.object().value("status").toString() == "yes"))
            {
                QMessageBox::information(this, "Информация", "Соединение установлено");
                ui->label_result->setText("Соединение установлено");
            }
            //"{\"type\":\"Find_Result\",\"messge\":\"File_Found\"}";
            else if ((doc.object().value("type").toString() == "Find_Result" && ((doc.object().value("message").toString() == "File_Found") || doc.object().value("status").toString() == "File_Not_Found")))
            {
                if (doc.object().value("message").toString() == "File_Found")
                {
                    ui->label_result->setText("File Found :)");
                }
                else
                {
                    ui->label_result->setText("File Not Found :)");
                }

            }
            else if (doc.object().value("type").toString() == "DownloadDatas")
            {


            }
            else if (doc.object().value("type").toString() == "VideoFile")
            {

            }
            else
            {
                qDebug() << "Error 2";
                QMessageBox::information(this, "Информация", "Соединение не установлено");
            }
        }
        else
        {
            QMessageBox::information(this, "Информация", "Ошибка с форматом передачи данных" + docError.errorString());
        }
    }
}

void ClienTCPWindow::sockDisconnect()
{
    socket->deleteLater();
}

void ClienTCPWindow::on_pushButtonConnection_clicked()
{
    socket->connectToHost("127.0.0.1", 9679);
}


void ClienTCPWindow::on_pushButtonFind_clicked()
{
    ani_name = ui->lineEdit->text();

    QString sheet("{\"type\":\"Find_File\", \"message\":\"" + ani_name + "\"}");

    QByteArray MessageToSend = sheet.toUtf8();

    if (socket->isOpen())
    {
        qDebug() << "Soket is open for send ani name";
        socket->write(MessageToSend);
        socket->waitForBytesWritten(2000);
    }
    else
    {
        QMessageBox::information(this, "Информация", "Соединение не установлено");
    }
}


void ClienTCPWindow::on_pushButtonDownload_clicked()
{
    QString sheet("{\"type\":\"Download\", \"message\":\"" + ani_name + "\"}");

    QByteArray MessageToSend = sheet.toUtf8();

    if (socket->isOpen())
    {
        socket->write(MessageToSend);
        socket->waitForBytesWritten(2000);
    } else
    {
        qDebug() << "Error";
        QMessageBox::information(this, "Информация", "Соединение не установлено");
    }
}

