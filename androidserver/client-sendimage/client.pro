#-------------------------------------------------
#
# Project created by QtCreator 2014-09-23T09:59:25
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app
INCLUDEPATH += P:/soft/opencv/build/include/opencv \
INCLUDEPATH += P:/soft/opencv/build/include/opencv2 \
INCLUDEPATH += P:/soft/opencv/build/include \

#INCLUDEPATH += f:/opencv/build/include/opencv
#INCLUDEPATH += f:/opencv/build/include/opencv2
#INCLUDEPATH += f:/opencv/build/include

#LIBS += -Lf:/opencv/build/x86/vc11/lib \
#    -lopencv_calib3d248d \
#    -lopencv_contrib248d \
#    -lopencv_core248d \
#    -lopencv_features2d248d \
#    -lopencv_flann248d \
#    -lopencv_gpu248d \
#    -lopencv_highgui248d \
#    -lopencv_imgproc248d \
#    -lopencv_legacy248d \
#    -lopencv_ml248d \
#    -lopencv_nonfree248d \
#    -lopencv_objdetect248d \
#    -lopencv_ocl248d \
#    -lopencv_photo248d \
#    -lopencv_stitching248d \
#    -lopencv_superres248d \
#    -lopencv_ts248d \
#    -lopencv_video248d \
#    -lopencv_videostab248d

LIBS += -LP:/soft/opencv/build/x64/vc11/lib \
    -lopencv_calib3d249d \
    -lopencv_contrib249d \
    -lopencv_core249d \
    -lopencv_features2d249d \
    -lopencv_flann249d \
    -lopencv_gpu249d \
    -lopencv_highgui249d \
    -lopencv_imgproc249d \
    -lopencv_legacy249d \
    -lopencv_ml249d \
    -lopencv_nonfree249d \
    -lopencv_objdetect249d \
    -lopencv_ocl249d \
    -lopencv_photo249d \
    -lopencv_stitching249d \
    -lopencv_superres249d \
    -lopencv_ts249d \
    -lopencv_video249d \
    -lopencv_videostab249d

SOURCES += main.cpp\
        dialog.cpp

HEADERS  += dialog.h

FORMS    += dialog.ui

RESOURCES += \
    rc.qrc
