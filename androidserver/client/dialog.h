#ifndef DIALOG_H
#define DIALOG_H
#include <QDebug>
#include <QDialog>
#include <QTcpSocket>
#include <QTimer>



#include <QPixmap>

#include <opencv2/opencv.hpp>
using namespace cv;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QTcpSocket *socket;
    void initwebcam();
    void initBackgroundSubtractorMOG2();
    Mat frame ;

    int PORT;
    QString IP;

signals:
    void sendtoandroid(); //获取车辆图像

private slots:
    void sendtoandroidprocess();
    void on_pushButton_clicked();
    void getFrame(); //实现定时从摄像头取图并显示在label上的功能。

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();

private:
    Ui::Dialog *ui;
    VideoCapture cap; //highgui 里提供的一个专门处理摄像头图像的结构体
    cv::BackgroundSubtractorMOG2 bg;
    VideoWriter writer; //摄像头每次抓取的图像为一帧，使用该指针指向一帧图像的内存空间
    Size videoSize;
    QTimer *timer;
};

#endif // DIALOG_H
