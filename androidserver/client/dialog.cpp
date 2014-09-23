#include "dialog.h"
#include "ui_dialog.h"

static bool recodeflag=false;
static cv::Mat frame;
static cv::Mat back;
static cv::Mat fore;
static Mat copyimg;
static std::vector<std::vector<cv::Point> > contours;
static int count=0;

Dialog::Dialog(QWidget *parent) :IP("192.168.1.102"),PORT(6000),
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->ipEdit->setText(IP);

    ui->portEdit->setText(QString::number(PORT));

    timer = new QTimer(this);
    initwebcam();
    initBackgroundSubtractorMOG2();
    connect(timer,SIGNAL(timeout()),this,SLOT(getFrame())); //超时就去取
    timer->start(5); //1000为1秒，10毫秒去取一帧
}

void Dialog::initwebcam()
{
    cap=VideoCapture(0);
    if(!cap.isOpened()){

        qDebug()<<"init webcam  error ,program exit...";
        return;
    }
    cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);      /* set width */
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);     /* set height */

    videoSize=Size(320,240);

}

void Dialog::getFrame(){
    cap>>frame;

    if(frame.empty()) return;

    frame.copyTo(copyimg);
    QImage image = QImage((const uchar*)frame.data, frame.cols, frame.rows, QImage::Format_RGB888).rgbSwapped(); //简单地转换一下为Image对象，rgbSwapped是为了显示效果色彩好一些。
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->repaint();
    bg.operator ()(frame,fore);
    bg.getBackgroundImage(back);
    cv::erode(fore,fore,cv::Mat());
    cv::dilate(fore,fore,cv::Mat());
    cv::findContours(fore,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);
    if (contours.size()>0 &&count>0)
    {
        //如果轮廓的面积太小了也不用写到输出视频
        for (int i = 0; i< contours.size(); i++)
        {
            double a=contourArea( contours[i],false);
            if (a>500)//面积小于500
            {
                cv::drawContours(frame,contours,i,cv::Scalar(0,0,255),2);
                recodeflag=true;
            }
            else
            {
                recodeflag=false;
            }
        }

    }
    else
    {
        recodeflag=false;
    }
    if(recodeflag){
        QImage imagelable2 = QImage((const uchar*)frame.data, frame.cols, frame.rows, QImage::Format_RGB888).rgbSwapped();
        ui->label_2->setPixmap(QPixmap::fromImage(imagelable2));
        ui->label_2->repaint();
        ui->label_2->setText("found some one in the lab");
        emit sendtoandroid();


    }else {
        ui->label_2->repaint();
        ui->label_2->setText("no thing in the lab");

    }
    if (recodeflag)
    {
        writer<<copyimg;
    }
    count++;
}


void Dialog::initBackgroundSubtractorMOG2()
{
    bg.setInt("nmixtures", 3);
    bg.setBool("detectShadows", false);
    writer.open("result.avi",CV_FOURCC('D','I','V','X'),15,videoSize);

}

void Dialog::sendtoandroidprocess()
{
            qDebug() << "connecting...";
//            socket->connectToHost("192.168.1.102", 6000);
            socket->connectToHost(IP.toStdString().c_str(), PORT);
            ui->label_2->setText("waring sending to android...");

}


Dialog::~Dialog()
{
    timer->stop(); //停止取帧
    delete ui;
}

//设置手机IP
void Dialog::on_pushButton_clicked()
{

    this->IP=ui->ipEdit->text();
    this->PORT=ui->portEdit->text().toInt();

    if(IP.length()==0){
        // set ip first please
        return;

    }

    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));


    connect(this, SIGNAL(sendtoandroid()),this, SLOT(sendtoandroidprocess()));
//    qDebug() << "connecting...";
//    socket->connectToHost("192.168.1.102", 6000);
}

void Dialog::connected()
{
    socket->write("some body come in");
    socket->close();

}

void Dialog::disconnected()
{
    qDebug() << "disconnected...";

}
void Dialog::bytesWritten(qint64 bytes)
{

    qDebug() << bytes << " bytes written...";
}

void Dialog::readyRead()
{
    qDebug() << "reading...";
    qDebug() << socket->readAll();
}
