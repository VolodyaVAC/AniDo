#include "mediawindow.h"
#include "ui_mediawindow.h"

MediaWindow::MediaWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MediaWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
    player->setVideoOutput(vw);
    this->setCentralWidget(vw);
}

MediaWindow::~MediaWindow()
{
    delete ui;
}

void MediaWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open a File", "", "Video File (*.mpg)");
    on_actionStop_triggered();

    player->setMedia(QUrl::fromLocalFile(filename));

    on_actionPlay_triggered();
}


void MediaWindow::on_actionPlay_triggered()
{
    player->play();
    ui->statusbar->showMessage("Playing");
}


void MediaWindow::on_actionPause_triggered()
{
    player->pause();
    ui->statusbar->showMessage("Pause");
}


void MediaWindow::on_actionStop_triggered()
{
    player->stop();
    ui->statusbar->showMessage("Stoped");
}

