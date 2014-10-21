TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

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

#boost头文件目录
INCLUDEPATH += F:/boost_1_56_0  \

#boost库文件目录
LIBS += -LF:/boost_1_56_0/lib32-msvc-11.0  \
        -lboost_system-vc110-mt-1_56 \
        -lboost_thread-vc110-mt-1_56 \
        -llibboost_system-vc110-mt-1_56 \
        -llibboost_thread-vc110-mt-1_56 \

SOURCES += main.cpp

