#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    qDebug()<<"hello clicked";
    IplImage * pInpImg = 0;

          // Load an image from file - change this based on your image name
          pInpImg = cvLoadImage("H:\\FTP\\1.jpg", CV_LOAD_IMAGE_UNCHANGED);
          if(!pInpImg)
          {
            fprintf(stderr, "failed to load input image\n");

          }
          cvShowImage("sourse",pInpImg);
          cvWaitKey();



}
