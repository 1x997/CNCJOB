#ifndef PROCESSHOGWORK_H
#define PROCESSHOGWORK_H

#include <QObject>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/core/core.hpp>
#include <opencv2/gpu/gpu.hpp>
using namespace cv;
class processhogwork : public QObject
{
    Q_OBJECT
public:
    processhogwork(Mat image);
    ~processhogwork();
    Mat image;
    Mat resultimage;


signals:
    void finished();

public slots:
    void process();

};

#endif // PROCESSHOGWORK_H
