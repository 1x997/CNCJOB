#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setAcceptDrops(true);
//    ui->framedrag->acceptDrops();
    connect(this, SIGNAL(carSpeedFileNameSetSignal()), this, SLOT(carSpeedFileNameSetProcess()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::dragEnterEvent(QDragEnterEvent *e)
{
    if (e->mimeData()->hasUrls()) {
        e->acceptProposedAction();
    }

}

void Dialog::dropEvent(QDropEvent *e)
{
    QPoint p= e->pos();
    QPoint lp= ui->labeldrag->pos();
    QRect r(lp.x(),lp.y(),ui->labeldrag->width(),ui->labeldrag->height());
    if(r.contains(p)){
        foreach (const QUrl &url, e->mimeData()->urls()) {
            const QString &fileName = url.toLocalFile();
            ui->message->setText(fileName);

            this->AVIfilename=fileName;
            emit carSpeedFileNameSetSignal();
        }
    }

}


void Dialog::setlablepic(QLabel * lable, Mat image){
    QImage labelimage= QImage((uchar*) image.data, image.cols, image.rows, image.step, QImage::Format_RGB888).rgbSwapped();
    lable->setPixmap(QPixmap::fromImage(labelimage));
    //    lable->update(); //do not work !!!!!!!!!!!!!!!!!!!

    //*********************************更新图像，非常重要********************************
    lable->repaint();

}


void Dialog::carSpeedFileNameSetProcess()
{


    //    ---------------------show the drag image-----------------------
    //    qDebug()<<"Process AVIfile";
    //    qDebug()<<AVIfilename;

    //    Mat image =imread(AVIfilename.toStdString().c_str());
    //    if(!image.empty()){

    //        imshow("image",image);
    //        waitKey(0);

    //    }

    //    ------------------------show the drag vedio-----------------------
    CvCapture *capture = 0;
    capture = cvCaptureFromAVI(AVIfilename.toStdString().c_str());
    if(!capture){
        std::cerr << "Cannot open video!" << std::endl;
        return ;
    }

    IplImage *frame_aux = cvQueryFrame(capture);
    int key = 0;
    while(key != 'q'){
        frame_aux = cvQueryFrame(capture);
        if(!frame_aux) break;
        cv::Mat img_input(frame_aux);
//        cv::imshow("video", img_input);
        cv::Mat showimg;
        img_input.copyTo(showimg);
        setlablepic(ui->label,showimg);
        key = cvWaitKey(100);
    }



}
