#ifndef MEDIAWINDOW_H
#define MEDIAWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>

namespace Ui {
class MediaWindow;
}

class MediaWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MediaWindow(QWidget *parent = nullptr);
    ~MediaWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionStop_triggered();

private:
    Ui::MediaWindow *ui;
    QMediaPlayer* player;
    QVideoWidget* vw;
    QProgressBar* bar;
    QSlider* slider;
};

#endif // MEDIAWINDOW_H
