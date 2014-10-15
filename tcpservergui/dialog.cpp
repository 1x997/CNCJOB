#include "dialog.h"
#include "ui_dialog.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <QDebug>
#include <QThread>
#include <QDir>

using namespace cv;
using namespace std;
static bool stable2;
static QList<QString> imagelist;
static  int carframe=0;
static Mat writetoavi;

Dialog::Dialog(QWidget *parent) :carspeedflag(false),capture(NULL),resize_factor(100),bgscarspeed(new PixelBasedAdaptiveSegmenter),vehicleCouting(new VehicleCouting),blobTracking(NULL),IP("192.168.1.102"),PORT(6000),videoSize(Size(320,240)),
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);
    //设置接受拖拽
    setAcceptDrops(true);
    init();

    ui->ipEdit->setText(IP);
    ui->portEdit->setText(QString::number(PORT));

    ui->comboBox->addItem ("FrameDifferenceBGS");
    ui->comboBox->addItem ("AdaptiveBackgroundLearning");
    ui->comboBox->addItem ("StaticFrameDifferenceBGS");

}

Dialog::~Dialog()
{
    delete ui;
}
//从网络获取图像
void Dialog::getFrame(){
    if(server->stable){
        QByteArray b1=server->socket->read(230400); //socket->readAll();
        std::vector<uchar> vectordata(b1.begin(),b1.end());
        cv::Mat data_mat(vectordata,true);
        showimg= data_mat.reshape(3,240);       /* reshape to 3 channel and 240 rows */
        Mat peopletestimage;
        showimg.copyTo(peopletestimage);
        //server->img.copyTo(showimg);
        //imshow("recv",showimg);
        setlablepic(ui->labelrecv,showimg);
        //如果设置了行人检测，同时不是很忙时候,就开始HOG检测
        if(!server->busy){
            server->busy=true;
            if(multiflag){
                Mat showmulti = multitrack(peopletestimage);
                setlablepic(ui->labelmult,showmulti);
            }
            if(hogflag){
                Mat peopleimage=hogpeople(showimg);
                setlablepic(ui->labelperson,peopleimage);
                if(havepeople){
                    ui->label_6->setText("检测结果：有人");
                }else{
                    ui->label_6->setText("检测结果：没人");
                }
            }
            server->busy=false;//解除忙状态，这样，客户端发来的图像就不会通过read掉而不保存
            //            use for 多线程
            //            QThread* thread = new QThread;
            //            worker = new processhogwork(showimg);
            //            worker->moveToThread(thread);
            //           // connect(worker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
            //            connect(thread, SIGNAL(started()), worker, SLOT(process()));
            //            connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
            //            connect(worker, SIGNAL(finished()), this, SLOT(showprocess()));
            //           // connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
            //            showimg.copyTo(worker->image);
            //            thread->start();

        }
        waitKey(2);
    }
}
//车辆统计
//一定要在build文件夹下建立config文件夹！！！！！
void Dialog::getlocalFrame()
{
    int key = 0;
    QString imagename;
    if (carframe < imagelist.size()){
        imagename = imagelist.at(carframe);
    }
    Mat img_input =imread(imagename.toStdString().c_str());
//    qDebug()<<imagename.toStdString().c_str();
    rectangle(img_input, Point( 0, 120 ), Point( 320, 170),Scalar( 0, 255, 255 ), 1, 8, 0);
    cv::Mat img_mask;
    cv::Mat img_bkgmodel;
    bgs->process(img_input, img_mask, img_bkgmodel);
    Mat submask = img_mask(rect);
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(8, 8));
    cv::erode(submask,submask,element);
    cv::dilate(submask,submask,element);
    int rowsum=0;
    for (int jj=0;jj<submask.cols;jj++)
    {
        if (submask.at<uchar>(25,jj)>125)
        {
            rowsum +=1;
        }
    }
    if (rowsum<17)
    {
        carnum +=0;
    }else
    {
        if (rowsum<40)
        {
            carnum+=1;    //车辆宽度约为1辆车
        }else
        {
            if(rowsum<200)
            {
                carnum +=2;//车辆宽度约为2辆车
            }
        }
    }

    ////        //string <---- int
    QString text = QString::number(carnum);

    int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
    double fontScale = 1;
    int thickness = 2;
    cv::Point textOrg(0, 50);
    cv::putText(img_input, text.toStdString().c_str(), textOrg, fontFace, fontScale, Scalar(255,0,0,0), thickness,8);

    setlablepic(ui->labelcar,img_input);
    waitKey(10);
    carframe++;

}

//多线程
void Dialog::showprocess()
{
    if(!worker->resultimage.empty())
    {
        imshow("process",worker->resultimage);
        waitKey(2);

    }
}
//run button
void Dialog::on_pushButton_clicked()
{
    //connect(timer,SIGNAL(timeout()),this,SLOT(getFrame())); //超时就去取 when is used timer but here wo use the signal
    connect(server,SIGNAL(buildimage()),this,SLOT(getFrame()));
}
//HOG BUTTON
void Dialog::on_pushButton_2_clicked()
{
    hogflag=true;
}

//set image show in dialog
void Dialog::setlablepic(QLabel * lable, Mat image){
    QImage labelimage= QImage((uchar*) image.data, image.cols, image.rows, image.step, QImage::Format_RGB888).rgbSwapped();
    lable->setPixmap(QPixmap::fromImage(labelimage));

}


void Dialog::setLablePicAutoRefresh(QLabel * lable, Mat image){
    QImage labelimage= QImage((uchar*) image.data, image.cols, image.rows, image.step, QImage::Format_RGB888).rgbSwapped();
    lable->setPixmap(QPixmap::fromImage(labelimage));
    lable->repaint();

}

//HOG行人检测后把检测后的图像return
Mat Dialog::hogpeople(Mat image){
    Mat tempimg;
    image.copyTo(tempimg);
    vector<Rect> found;
    HOGDescriptor defaultHog;
    defaultHog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
    defaultHog.detectMultiScale(tempimg, found);

    if(found.size()>0){
        havepeople=true;
    }else{
        havepeople=false;
    }
    for(int i = 0; i < found.size(); i++)
    {
        Rect r = found[i];
        rectangle(tempimg, r.tl(), r.br(), Scalar(0, 255, 0), 2);//top left     bottom right
    }

    return tempimg;

}
void Dialog::init(){

    //dialog init
    setWindowTitle("服务器端");
    server = new MyTcpServer();

    //hog 行人检测 init
    hogflag=false;
    havepeople=false;


    //multi object init
    MHI_DURATION = 1;//0.5s为运动跟踪的最大持续时间
    N = 3;
    CONTOUR_MAX_AERA = 1000;
    buf = 0;
    last = 0;
    mhi = 0; // MHI: motion history image 运动历史图像
    motion = 0;
    multiflag=false;
    //初始化车辆统计





    carnum =0;
    rect = Rect(0,120,320,50);
    bgs = new MixtureOfGaussianV2BGS;
    ui->labelrecv->setText("");
    ui->labelmult->setText("");
    ui->labelcar->setText("");
    ui->labelperson->setText("");
    //mkdir config   QDir::mkdir  如果配置文件目录不存在，则先创建配置文件目录
    QDir dir("config");
    if (!dir.exists()){
        qWarning("Cannot find the config directory");
        dir.mkdir(".");
    }

    //write avi to hdd
    writer.open("result.avi",CV_FOURCC('D','I','V','X'),15,videoSize);





}
//多目标检测 历史图像
void Dialog::update_mhi(IplImage *img, IplImage *dst)
{
    double timestamp = clock()/100.; // get current time in seconds 时间戳
    CvSize size = cvSize(img->width,img->height);
    int i, idx1, idx2;
    IplImage* silh;
    IplImage* pyr = cvCreateImage( cvSize((size.width & -2)/2, (size.height & -2)/2), 8, 1 );
    CvMemStorage *stor;
    CvSeq *cont;
    if( !mhi || mhi->width != size.width || mhi->height != size.height )
    {
        if( buf == 0 ) //若尚没有初始化则分配内存给他
        {
            buf = (IplImage**)malloc(N*sizeof(buf[0]));
            memset( buf, 0, N*sizeof(buf[0]));
        }

        for( i = 0; i < N; i++ )
        {
            cvReleaseImage( &buf[i] );
            buf[i] = cvCreateImage( size, IPL_DEPTH_8U, 1 );
            cvZero( buf[i] );// clear Buffer Frame at the beginning
        }
        cvReleaseImage( &mhi );
        mhi = cvCreateImage( size, IPL_DEPTH_32F, 1 );
        cvZero( mhi ); // clear MHI at the beginning
    }
    cvCvtColor( img, buf[last], CV_BGR2GRAY ); // convert frame to grayscale
    idx1 = last;
    idx2 = (last + 1) % N; // index of (last - (N-1))th frame
    last = idx2;
    silh = buf[idx2];//差值的指向idx2 |idx2-idx1|-->idx2(<-silh)
    cvAbsDiff( buf[idx1], buf[idx2], silh ); // get difference between frames
    cvThreshold( silh, silh, 50, 255, CV_THRESH_BINARY ); //threshold it,二值化
    cvUpdateMotionHistory( silh, mhi, timestamp, MHI_DURATION ); // update MHI

    cvConvert( mhi, dst );//将mhi转化为dst,dst=mhi
    cvSmooth( dst, dst, CV_MEDIAN, 3, 0, 0, 0 );
    cvPyrDown( dst, pyr, CV_GAUSSIAN_5x5 );// 向下采样，去掉噪声，图像是原图像的四分之一
    cvDilate( pyr, pyr, 0, 1 ); // 做膨胀操作，消除目标的不连续空洞
    cvPyrUp( pyr, dst, CV_GAUSSIAN_5x5 );// 向上采样，恢复图像，图像是原图像的四倍
    stor = cvCreateMemStorage(0);
    cont = cvCreateSeq(CV_SEQ_ELTYPE_POINT, sizeof(CvSeq), sizeof(CvPoint) , stor);
    cvFindContours( dst, stor, &cont, sizeof(CvContour),
                    CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));

    for(;cont;cont = cont->h_next)
    {
        CvRect r = ((CvContour*)cont)->rect;
        if(r.height * r.width > CONTOUR_MAX_AERA) // 面积小的方形抛弃掉
        {
            cvRectangle( img, cvPoint(r.x,r.y),
                         cvPoint(r.x + r.width, r.y + r.height),
                         CV_RGB(255,0,0), 1, CV_AA,0);


            //写到视频文件里

            writetoavi = Mat(img,false);
            writer<<writetoavi;

            //发送消息到android

            emit sendtoandroid();
        }
    }

    cvReleaseMemStorage(&stor);
    cvReleaseImage( &pyr );
}

Mat Dialog::multitrack(Mat image)
{
    IplImage* img = new IplImage(image);
    if( !motion )
    {
        motion = cvCreateImage( cvSize(img->width,img->height), 8, 1 );
        cvZero( motion );
        motion->origin = img->origin;
    }
    update_mhi( img, motion);//更新历史图像
    Mat multiimage = Mat(img,false);
    return multiimage;
}

//enable multithread
//设置车辆检测处理的图像所在目录
void Dialog::on_pushButton_3_clicked()
{
    multiflag = true;
}

void Dialog::on_setimagedir_clicked()
{
    dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                            "/home",
                                            QFileDialog::ShowDirsOnly
                                            | QFileDialog::DontResolveSymlinks);

}
//设置车辆检测的datalist.txt文件
void Dialog::on_setdatalist_clicked()
{

    fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), "/home/datalist.txt", tr("Text files (*.txt)"));
}

void Dialog::on_pushButton_4_clicked()//统计车辆开始
{

    static QFile datalist(fileName);
    if (datalist.open(QIODevice::ReadOnly))
    {
        QTextStream in(&datalist);

        while ( !in.atEnd() )
        {
            QString line = in.readLine();
            imagelist<<(dir+'/'+line);
            //imagelist.push_back(line);
            //Mat image =imread((dir+'/'+line).toStdString().c_str());
            //setlablepic(ui->labelcar,image);
            //emit getlocalFrameSignal();

            //              imshow("car",image);
            //              waitKey(10);
        }
        datalist.close();
    }
    //emit getlocalFrameSignal();
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(getlocalFrame()));
    timer->start(50);
    carframe=0;


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
//          emit carSpeedFileNameSetSignal();

            timerforcarspeed = new QTimer(this);
            connect(timerforcarspeed, SIGNAL(timeout()), this, SLOT(carSpeedFileNameSetProcess()));
            timerforcarspeed->start(50);
        }
    }
}

//处理车速
void Dialog::carSpeedFileNameSetProcess()
{
    if(capture == NULL){
        capture = cvCaptureFromAVI(AVIfilename.toStdString().c_str());

     }

    frame_aux = cvQueryFrame(capture);
    if(frame_aux == NULL){
        disconnect(timerforcarspeed, SIGNAL(timeout()), this, SLOT(carSpeedFileNameSetProcess()));
        return;
     }
    frame = cvCreateImage(cvSize((int)((frame_aux->width*resize_factor)/100) , (int)((frame_aux->height*resize_factor)/100)), frame_aux->depth, frame_aux->nChannels);

    if(blobTracking==NULL)
         blobTracking = new BlobTracking;

/* Vehicle Counting Algorithm */
//    VehicleCouting* vehicleCouting;
//    vehicleCouting = new VehicleCouting;

    int key = 0;
    if(key != 'q' & !this->carspeedflag)
    {
        frame_aux = cvQueryFrame(capture);
        if(!frame_aux)
        {
            disconnect(timerforcarspeed, SIGNAL(timeout()), this, SLOT(carSpeedFileNameSetProcess()));
            return;
        }
        cvResize(frame_aux, frame);
        cv::Mat img_input(frame);
        cv::Mat img_mask;
        cv::Mat img_background;
        bgscarspeed->process(img_input, img_mask,img_background);
        if(!img_mask.empty())
        {
//  Perform blob tracking
            blobTracking->process(img_input, img_mask, img_blob);
            //  cv:imshow("img_blob",img_blob);
            // Perform vehicle counting
            vehicleCouting->setInput(img_blob);
            vehicleCouting->setTracks(blobTracking->getTracks());
            vehicleCouting->process();
            Mat carspeed =vehicleCouting->getInput();
            setLablePicAutoRefresh(ui->labelcarspeed,carspeed);
//            imshow("carspeed",carspeed);
        }
        key = cvWaitKey(1);
    }

//    delete vehicleCouting;
//    delete blobTracking;
//    delete bgs;
//    cvDestroyAllWindows();
//    cvReleaseCapture(&capture);


}
//停止车速测量
void Dialog::on_stopcarspeed_clicked()
{
    this->carspeedflag=true; //stop 测量
    disconnect(timerforcarspeed, SIGNAL(timeout()), this, SLOT(carSpeedFileNameSetProcess()));

}


//绑定IP地址和端口
void Dialog::on_bindIP_clicked()
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

}
void Dialog::connected()
{
//    socket->write("some body come in");
//    socket->close();
    Mat sentframe = writetoavi.reshape(0,1);
    std::string message((char *)sentframe.data,230400);
    socket->write(message.c_str(),230400);

    socket->close();
    qDebug()<<"connected and image send finished...";

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
void Dialog::sendtoandroidprocess()
{
            qDebug() << "connecting...";
            if(socket->isOpen()){
                qDebug()<<"already opened ,wait please...";
                return;
            }
            socket->connectToHost(IP.toStdString().c_str(), PORT);
}
