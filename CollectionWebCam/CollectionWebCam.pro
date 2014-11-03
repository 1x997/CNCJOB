#-------------------------------------------------
#
# Project created by QtCreator 2014-11-03T10:24:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CollectionWebCam
TEMPLATE = app

INCLUDEPATH += f:/opencv/build/include/opencv
INCLUDEPATH += f:/opencv/build/include/opencv2
INCLUDEPATH += f:/opencv/build/include

LIBS += -Lf:/opencv/build/x86/vc11/lib \
    -lopencv_calib3d248d \
    -lopencv_contrib248d \
    -lopencv_core248d \
    -lopencv_features2d248d \
    -lopencv_flann248d \
    -lopencv_gpu248d \
    -lopencv_highgui248d \
    -lopencv_imgproc248d \
    -lopencv_legacy248d \
    -lopencv_ml248d \
    -lopencv_nonfree248d \
    -lopencv_objdetect248d \
    -lopencv_ocl248d \
    -lopencv_photo248d \
    -lopencv_stitching248d \
    -lopencv_superres248d \
    -lopencv_ts248d \
    -lopencv_video248d \
    -lopencv_videostab248d


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
