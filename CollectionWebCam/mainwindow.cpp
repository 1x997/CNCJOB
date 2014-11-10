#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :secend(0),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cap=VideoCapture(0);
    if(!cap.isOpened()){

//        qDebug()<<"init webcam  error ,program exit...";
        return;
    }
    videoSize=Size(320,240);
    cap.set(CV_CAP_PROP_FRAME_WIDTH, videoSize.width);      /* set width */
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, videoSize.height);     /* set height */
//init size is 320*240

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(getlocalframe()));
    timer->start(50);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_setsavepath_clicked()
{
    dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                            "/home",
                                            QFileDialog::ShowDirsOnly
                                            | QFileDialog::DontResolveSymlinks);

}

void MainWindow::getlocalframe()
{
    Mat frame;
    cap>>frame;

    if(frame.empty()) return;

    Mat resizeframe;

    cv::resize(frame,resizeframe,Size(320,240));

    QImage image = QImage((const uchar*)resizeframe.data, resizeframe.cols, resizeframe.rows, QImage::Format_RGB888).rgbSwapped();
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->repaint();
    writer<<frame;

}

void MainWindow::setlablepic(QLabel *lable, Mat image)
{
    QImage labelimage= QImage((uchar*) image.data, image.cols, image.rows, image.step, QImage::Format_RGB888).rgbSwapped();
    lable->setPixmap(QPixmap::fromImage(labelimage));

}

void MainWindow::on_startrecord_clicked()
{

    if(ui->size1->isChecked())
        videoSize=Size(320,240);
    if(ui->size2->isChecked())
        videoSize=Size(640,480);

    cap.set(CV_CAP_PROP_FRAME_WIDTH, videoSize.width);      /* set width */
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, videoSize.height);     /* set height */

    showtime = new QTimer(this);
    connect(showtime,SIGNAL(timeout()),this,SLOT(on_show_time()));
    showtime->start(1000);

    QString savefilename;



    savefilename= dir +QDir::separator()+ ui->lineEdit->text();
    qDebug()<<savefilename;
    ui->filepathname->setText(savefilename);
    writer.open(savefilename.toStdString().c_str(),CV_FOURCC('M', 'J', 'P', 'G'),15,videoSize);//'I','Y','U','V'//'D','I','V','X'

}

void MainWindow::on_stoprecord_clicked()
{
    disconnect(showtime,SIGNAL(timeout()),this,SLOT(on_show_time()));
    secend = 0;
    ui->label_time->setText(QString::number(secend));
    writer.release();

}

void MainWindow::on_show_time()
{
    secend++;
    ui->label_time->setText(QString::number(secend));
}
