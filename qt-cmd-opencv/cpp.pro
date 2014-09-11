TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt

INCLUDEPATH += g:/opencv/build/include/opencv \
INCLUDEPATH += g:/opencv/build/include/opencv2 \
INCLUDEPATH += g:/opencv/build/include \
INCLUDEPATH += H:/FTP/testdir/tcpservergui/package_bgs
LIBS += -Lg:/opencv/build/x64/vc11/lib \
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

SOURCES += main.cpp \
    testfile.cpp

HEADERS += \
    testfile.h

