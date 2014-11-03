#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QTimer>
#include <QLabel>
#include <QImage>
#include <QDebug>

#include <opencv/cv.h>
#include <opencv/highgui.h>
using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_setsavepath_clicked();
    void getlocalframe();

    void on_startrecord_clicked();

    void on_stoprecord_clicked();
    void on_show_time();

private:
    Ui::MainWindow *ui;
    QString dir;
    QString filename;
    QTimer *timer;
    QTimer *showtime;
    VideoCapture cap;
    Size videoSize;
    VideoWriter writer;
    int secend;
    void setlablepic(QLabel * lable, Mat image);

};

#endif // MAINWINDOW_H
