#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>
#include <opencv/cv.h>
#include <opencv/highgui.h>
using namespace cv;
using namespace std;
class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = 0);
    Mat  img;
    bool stable;
    bool busy;
signals:
    void buildimage();
public slots:
    void newConnection();
    void readyRead();
    void disconnected();

public:
    QTcpServer *server;
    QTcpSocket *socket;
};

#endif // MYTCPSERVER_H

