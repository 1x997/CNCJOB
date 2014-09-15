
#include "mytcpserver.h"
#include <QDebug>
MyTcpServer::MyTcpServer(QObject *parent) :
    QObject(parent)
{
    stable=false;
    busy=false;
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()),
            this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any, 3200))
    {
        qDebug() << "Server could not start";
    }
    else
    {
        qDebug() << "Server started! listen port is 3200";
    }
}

void MyTcpServer::newConnection()
{

    qDebug() << "newConnection...";
    socket = server->nextPendingConnection();

    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
}

void MyTcpServer::readyRead()
{

  //  qDebug() << "readyRead...";
  //  qDebug() << socket->bytesAvailable();

    qint64 blockSize = 230400; //320*240*3
    if (socket->bytesAvailable() < blockSize)//直到读到230400byte数据
        {
           // stable=false;
            return;
        }

    if(busy){
        socket->read(230400);
    }else{
        emit buildimage();
        stable=true;
    }

//    QByteArray b1=socket->read(230400); //socket->readAll();
//    std::vector<uchar> vectordata(b1.begin(),b1.end());
//    cv::Mat data_mat(vectordata,true);
//    img= data_mat.reshape(3,240);       /* reshape to 3 channel and 240 rows */
//    imshow("recv",img);
//    waitKey(10);
}

void MyTcpServer::disconnected()
{
    qDebug() << "disconnected...";

}


