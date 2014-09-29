#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QTimer>
#include <QPixmap>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QLabel>
#include "mytcpserver.h"
#include "processhogwork.h"


#include "package_bgs/MixtureOfGaussianV2BGS.h"
#include "package_bgs/FrameDifferenceBGS.h"
#include "package_bgs/pt/PixelBasedAdaptiveSegmenter.h"


#include "package_analysis/VehicleCouting.h"
#include "package_tracking/BlobTracking.h"


//拖拽头文件
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QPoint>
#include <QRect>


using namespace cv;
using namespace std;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    Mat showimg;                                /* 可以去掉 */
    MyTcpServer *server;                        /* 服务器端 */
    Mat hogpeople(Mat image);
    void setlablepic(QLabel *lable, Mat image);                 //label显示Mat图像
    void setLablePicAutoRefresh(QLabel * lable, Mat image);
    bool hogflag;
    void init();
    bool havepeople;
    processhogwork* worker; //多线程

                                      //背景建模车辆统计使用
    IBGS *bgs;
    int carnum;
    Rect rect;
    QString dir;                      //车辆文件夹
    QString fileName;                 //datalist.txt
    Mat subImg;


                                      //多物体检测
    bool multiflag;
    double MHI_DURATION;
    int N;
    int CONTOUR_MAX_AERA;
    IplImage **buf;
    int last;
    IplImage *mhi;
    IplImage* motion;
    void update_mhi(IplImage* img, IplImage* dst);
    Mat multitrack(Mat image);
    IplImage* image;

                                                //    车速检测
    bool carspeedflag;
    CvCapture *capture;
    int resize_factor;
    VehicleCouting* vehicleCouting;

    cv::Mat img_blob;
    BlobTracking* blobTracking;
    IplImage *frame_aux;
    IplImage *frame;
    QTimer *timerforcarspeed;
    IBGS *bgscarspeed;




                                                        //    车速测量
    QString AVIfilename;
signals:
    void getlocalFrameSignal(); //获取车辆图像
    void carSpeedFileNameSetSignal();

private:
    Ui::Dialog *ui;



    //检测入侵,写入视频和发消息到android
    VideoWriter writer; //摄像头每次抓取的图像为一帧，使用该指针指向一帧图像的内存空间
    Size videoSize;
    int PORT;
    QString IP;
    QTcpSocket *socket;


    //getlocalimage
    QTimer *timer;                              /* 定时器，更新界面 */


public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();


signals:
    void sendtoandroid();

private slots:
    void sendtoandroidprocess();


private slots:
    void getFrame(); //获取网络图像
    void getlocalFrame();
    void showprocess();
    void on_pushButton_clicked(); //
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_setimagedir_clicked(); //设置车辆目录
    void on_setdatalist_clicked(); //设置车辆datalist.txt
    void on_pushButton_4_clicked(); //车辆统计
    void carSpeedFileNameSetProcess();

    // QWidget interface
    void on_stopcarspeed_clicked();

    void on_bindIP_clicked();

protected:
    void dragEnterEvent(QDragEnterEvent * e);
    void dropEvent(QDropEvent *e);
};

#endif // DIALOG_H
