#-------------------------------------------------
#
# Project created by QtCreator 2014-04-30T21:53:27
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tcpservergui
TEMPLATE = app
#公用机环境目录
#INCLUDEPATH += P:/soft/opencv/build/include/opencv \
#INCLUDEPATH += P:/soft/opencv/build/include/opencv2 \
#INCLUDEPATH += P:/soft/opencv/build/include \

#自己电脑环境目录
INCLUDEPATH += f:/opencv/build/include/opencv \
INCLUDEPATH += f:/opencv/build/include/opencv2 \
INCLUDEPATH += f:/opencv/build/include \

#公用机环境目录
#INCLUDEPATH += P:/publicinstall/boost_1_56_0  \
#LIBS += -LP:/publicinstall/boost_1_56_0/lib64-msvc-11.0  \

#自己电脑环境目录
INCLUDEPATH += f:/boost_1_56_0  \
LIBS += -Lf:/boost_1_56_0/lib32-msvc-11.0  \
        -llibboost_atomic-vc110-mt-sgd-1_56 \
        -llibboost_chrono-vc110-mt-sgd-1_56 \
        -llibboost_container-vc110-mt-sgd-1_56 \
        -llibboost_system-vc110-mt-sgd-1_56 \
        -llibboost_context-vc110-mt-sgd-1_56 \
        -llibboost_thread-vc110-mt-sgd-1_56 \
        -llibboost_date_time-vc110-mt-sgd-1_56 \
        -llibboost_exception-vc110-mt-sgd-1_56 \
        -llibboost_coroutine-vc110-mt-sgd-1_56 \
        -llibboost_filesystem-vc110-mt-sgd-1_56 \
        -llibboost_regex-vc110-mt-sgd-1_56 \
        -llibboost_bzip2-vc110-mt-sgd-1_56 \
        -llibboost_graph-vc110-mt-sgd-1_56 \
        -llibboost_zlib-vc110-mt-sgd-1_56 \
        -llibboost_iostreams-vc110-mt-sgd-1_56 \
        -llibboost_locale-vc110-mt-sgd-1_56 \
        -llibboost_log-vc110-mt-sgd-1_56 \
        -llibboost_log_setup-vc110-mt-sgd-1_56 \
        -llibboost_math_tr1f-vc110-mt-sgd-1_56 \
        -llibboost_math_tr1-vc110-mt-sgd-1_56 \
        -llibboost_math_c99f-vc110-mt-sgd-1_56 \
        -llibboost_math_c99l-vc110-mt-sgd-1_56 \
        -llibboost_math_c99-vc110-mt-sgd-1_56 \
        -llibboost_math_tr1l-vc110-mt-sgd-1_56 \
        -llibboost_program_options-vc110-mt-sgd-1_56 \
        -llibboost_python-vc110-mt-sgd-1_56 \
        -llibboost_random-vc110-mt-sgd-1_56 \
        -llibboost_serialization-vc110-mt-sgd-1_56 \
        -llibboost_wserialization-vc110-mt-sgd-1_56 \
        -llibboost_signals-vc110-mt-sgd-1_56 \
        -llibboost_prg_exec_monitor-vc110-mt-sgd-1_56 \
        -llibboost_test_exec_monitor-vc110-mt-sgd-1_56 \
        -llibboost_unit_test_framework-vc110-mt-sgd-1_56 \
        -llibboost_timer-vc110-mt-sgd-1_56 \
        -llibboost_atomic-vc110-mt-s-1_56 \
        -llibboost_system-vc110-mt-s-1_56 \
        -llibboost_container-vc110-mt-s-1_56 \
        -llibboost_chrono-vc110-mt-s-1_56 \
        -llibboost_context-vc110-mt-s-1_56 \
        -llibboost_thread-vc110-mt-s-1_56 \
        -llibboost_wave-vc110-mt-sgd-1_56 \
        -llibboost_coroutine-vc110-mt-s-1_56 \
        -llibboost_date_time-vc110-mt-s-1_56 \
        -llibboost_exception-vc110-mt-s-1_56 \
        -llibboost_filesystem-vc110-mt-s-1_56 \
        -llibboost_regex-vc110-mt-s-1_56 \
        -llibboost_bzip2-vc110-mt-s-1_56 \
        -llibboost_graph-vc110-mt-s-1_56 \
        -llibboost_zlib-vc110-mt-s-1_56 \
        -llibboost_iostreams-vc110-mt-s-1_56 \
        -llibboost_locale-vc110-mt-s-1_56 \
        -llibboost_log-vc110-mt-s-1_56 \
        -llibboost_log_setup-vc110-mt-s-1_56 \
        -llibboost_math_tr1-vc110-mt-s-1_56 \
        -llibboost_math_c99f-vc110-mt-s-1_56 \
        -llibboost_math_c99-vc110-mt-s-1_56 \
        -llibboost_math_tr1f-vc110-mt-s-1_56 \
        -llibboost_math_tr1l-vc110-mt-s-1_56 \
        -llibboost_math_c99l-vc110-mt-s-1_56 \
        -llibboost_program_options-vc110-mt-s-1_56 \
        -llibboost_python-vc110-mt-s-1_56 \
        -llibboost_random-vc110-mt-s-1_56 \
        -llibboost_serialization-vc110-mt-s-1_56 \
        -llibboost_wserialization-vc110-mt-s-1_56 \
        -llibboost_signals-vc110-mt-s-1_56 \
        -llibboost_prg_exec_monitor-vc110-mt-s-1_56 \
        -llibboost_test_exec_monitor-vc110-mt-s-1_56 \
        -llibboost_timer-vc110-mt-s-1_56 \
        -llibboost_unit_test_framework-vc110-mt-s-1_56 \
        -llibboost_system-vc110-sgd-1_56 \
        -llibboost_container-vc110-sgd-1_56 \
        -llibboost_chrono-vc110-sgd-1_56 \
        -llibboost_context-vc110-sgd-1_56 \
        -llibboost_date_time-vc110-sgd-1_56 \
        -llibboost_exception-vc110-sgd-1_56 \
        -llibboost_coroutine-vc110-sgd-1_56 \
        -llibboost_wave-vc110-mt-s-1_56 \
        -llibboost_filesystem-vc110-sgd-1_56 \
        -llibboost_regex-vc110-sgd-1_56 \
        -llibboost_bzip2-vc110-sgd-1_56 \
        -llibboost_graph-vc110-sgd-1_56 \
        -llibboost_zlib-vc110-sgd-1_56 \
        -llibboost_iostreams-vc110-sgd-1_56 \
        -llibboost_log-vc110-sgd-1_56 \
        -llibboost_log_setup-vc110-sgd-1_56 \
        -llibboost_math_tr1f-vc110-sgd-1_56 \
        -llibboost_math_tr1-vc110-sgd-1_56 \
        -llibboost_math_c99f-vc110-sgd-1_56 \
        -llibboost_math_c99l-vc110-sgd-1_56 \
        -llibboost_math_c99-vc110-sgd-1_56 \
        -llibboost_math_tr1l-vc110-sgd-1_56 \
        -llibboost_program_options-vc110-sgd-1_56 \
        -llibboost_python-vc110-sgd-1_56 \
        -llibboost_random-vc110-sgd-1_56 \
        -llibboost_serialization-vc110-sgd-1_56 \
        -llibboost_signals-vc110-sgd-1_56 \
        -llibboost_prg_exec_monitor-vc110-sgd-1_56 \
        -llibboost_wserialization-vc110-sgd-1_56 \
        -llibboost_test_exec_monitor-vc110-sgd-1_56 \
        -llibboost_unit_test_framework-vc110-sgd-1_56 \
        -llibboost_timer-vc110-sgd-1_56 \
        -llibboost_system-vc110-s-1_56 \
        -llibboost_chrono-vc110-s-1_56 \
        -llibboost_container-vc110-s-1_56 \
        -llibboost_wave-vc110-sgd-1_56 \
        -llibboost_context-vc110-s-1_56 \
        -llibboost_date_time-vc110-s-1_56 \
        -llibboost_exception-vc110-s-1_56 \
        -llibboost_coroutine-vc110-s-1_56 \
        -llibboost_filesystem-vc110-s-1_56 \
        -llibboost_regex-vc110-s-1_56 \
        -llibboost_bzip2-vc110-s-1_56 \
        -llibboost_graph-vc110-s-1_56 \
        -llibboost_zlib-vc110-s-1_56 \
        -llibboost_iostreams-vc110-s-1_56 \
        -llibboost_log-vc110-s-1_56 \
        -llibboost_log_setup-vc110-s-1_56 \
        -llibboost_math_c99-vc110-s-1_56 \
        -llibboost_math_tr1f-vc110-s-1_56 \
        -llibboost_math_tr1l-vc110-s-1_56 \
        -llibboost_math_tr1-vc110-s-1_56 \
        -llibboost_math_c99f-vc110-s-1_56 \
        -llibboost_math_c99l-vc110-s-1_56 \
        -llibboost_program_options-vc110-s-1_56 \
        -llibboost_python-vc110-s-1_56 \
        -llibboost_random-vc110-s-1_56 \
        -llibboost_serialization-vc110-s-1_56 \
        -llibboost_wserialization-vc110-s-1_56 \
        -llibboost_signals-vc110-s-1_56 \
        -llibboost_prg_exec_monitor-vc110-s-1_56 \
        -llibboost_test_exec_monitor-vc110-s-1_56 \
        -llibboost_timer-vc110-s-1_56 \
        -llibboost_unit_test_framework-vc110-s-1_56 \
        -llibboost_wave-vc110-s-1_56 \
        -llibboost_exception-vc110-mt-1_56 \
        -llibboost_test_exec_monitor-vc110-mt-1_56 \
        -lboost_atomic-vc110-mt-1_56 \
        -lboost_chrono-vc110-mt-1_56 \
        -lboost_container-vc110-mt-1_56 \
        -lboost_context-vc110-mt-1_56 \
        -lboost_coroutine-vc110-mt-1_56 \
        -lboost_system-vc110-mt-1_56 \
        -lboost_thread-vc110-mt-1_56 \
        -lboost_date_time-vc110-mt-1_56 \
        -lboost_filesystem-vc110-mt-1_56 \
        -lboost_regex-vc110-mt-1_56 \
        -lboost_bzip2-vc110-mt-1_56 \
        -lboost_graph-vc110-mt-1_56 \
        -lboost_iostreams-vc110-mt-1_56 \
        -lboost_locale-vc110-mt-1_56 \
        -lboost_log_setup-vc110-mt-1_56 \
        -lboost_log-vc110-mt-1_56 \
        -lboost_math_tr1f-vc110-mt-1_56 \
        -lboost_math_tr1l-vc110-mt-1_56 \
        -lboost_math_tr1-vc110-mt-1_56 \
        -lboost_zlib-vc110-mt-1_56 \
        -lboost_math_c99f-vc110-mt-1_56 \
        -lboost_math_c99l-vc110-mt-1_56 \
        -lboost_math_c99-vc110-mt-1_56 \
        -lboost_prg_exec_monitor-vc110-mt-1_56 \
        -lboost_program_options-vc110-mt-1_56 \
        -lboost_python-vc110-mt-1_56 \
        -lboost_random-vc110-mt-1_56 \
        -lboost_serialization-vc110-mt-1_56 \
        -lboost_signals-vc110-mt-1_56 \
        -lboost_unit_test_framework-vc110-mt-1_56 \
        -lboost_wserialization-vc110-mt-1_56 \
        -lboost_timer-vc110-mt-1_56 \
        -lboost_wave-vc110-mt-1_56 \
        -lboost_atomic-vc110-mt-gd-1_56 \
        -lboost_chrono-vc110-mt-gd-1_56 \
        -lboost_container-vc110-mt-gd-1_56 \
        -lboost_context-vc110-mt-gd-1_56 \
        -lboost_coroutine-vc110-mt-gd-1_56 \
        -lboost_date_time-vc110-mt-gd-1_56 \
        -lboost_system-vc110-mt-gd-1_56 \
        -lboost_thread-vc110-mt-gd-1_56 \
        -lboost_bzip2-vc110-mt-gd-1_56 \
        -lboost_filesystem-vc110-mt-gd-1_56 \
        -lboost_graph-vc110-mt-gd-1_56 \
        -lboost_iostreams-vc110-mt-gd-1_56 \
        -lboost_locale-vc110-mt-gd-1_56 \
        -lboost_log_setup-vc110-mt-gd-1_56 \
        -lboost_log-vc110-mt-gd-1_56 \
        -lboost_math_c99f-vc110-mt-gd-1_56 \
        -lboost_math_c99l-vc110-mt-gd-1_56 \
        -lboost_math_c99-vc110-mt-gd-1_56 \
        -lboost_math_tr1f-vc110-mt-gd-1_56 \
        -lboost_math_tr1l-vc110-mt-gd-1_56 \
        -lboost_math_tr1-vc110-mt-gd-1_56 \
        -lboost_prg_exec_monitor-vc110-mt-gd-1_56 \
        -lboost_program_options-vc110-mt-gd-1_56 \
        -lboost_python-vc110-mt-gd-1_56 \
        -lboost_random-vc110-mt-gd-1_56 \
        -lboost_regex-vc110-mt-gd-1_56 \
        -lboost_serialization-vc110-mt-gd-1_56 \
        -lboost_signals-vc110-mt-gd-1_56 \
        -lboost_wserialization-vc110-mt-gd-1_56 \
        -lboost_zlib-vc110-mt-gd-1_56 \
        -lboost_timer-vc110-mt-gd-1_56 \
        -lboost_unit_test_framework-vc110-mt-gd-1_56 \
        -lboost_wave-vc110-mt-gd-1_56 \
        -llibboost_exception-vc110-mt-gd-1_56 \
        -llibboost_atomic-vc110-mt-gd-1_56 \
        -llibboost_system-vc110-mt-gd-1_56 \
        -llibboost_container-vc110-mt-gd-1_56 \
        -llibboost_test_exec_monitor-vc110-mt-gd-1_56 \
        -llibboost_chrono-vc110-mt-gd-1_56 \
        -llibboost_context-vc110-mt-gd-1_56 \
        -llibboost_thread-vc110-mt-gd-1_56 \
        -llibboost_date_time-vc110-mt-gd-1_56 \
        -llibboost_coroutine-vc110-mt-gd-1_56 \
        -llibboost_filesystem-vc110-mt-gd-1_56 \
        -llibboost_regex-vc110-mt-gd-1_56 \
        -llibboost_bzip2-vc110-mt-gd-1_56 \
        -llibboost_graph-vc110-mt-gd-1_56 \
        -llibboost_zlib-vc110-mt-gd-1_56 \
        -llibboost_iostreams-vc110-mt-gd-1_56 \
        -llibboost_locale-vc110-mt-gd-1_56 \
        -llibboost_log-vc110-mt-gd-1_56 \
        -llibboost_log_setup-vc110-mt-gd-1_56 \
        -llibboost_math_tr1f-vc110-mt-gd-1_56 \
        -llibboost_math_tr1l-vc110-mt-gd-1_56 \
        -llibboost_math_tr1-vc110-mt-gd-1_56 \
        -llibboost_math_c99f-vc110-mt-gd-1_56 \
        -llibboost_math_c99l-vc110-mt-gd-1_56 \
        -llibboost_math_c99-vc110-mt-gd-1_56 \
        -llibboost_program_options-vc110-mt-gd-1_56 \
        -llibboost_python-vc110-mt-gd-1_56 \
        -llibboost_random-vc110-mt-gd-1_56 \
        -llibboost_serialization-vc110-mt-gd-1_56 \
        -llibboost_wserialization-vc110-mt-gd-1_56 \
        -llibboost_prg_exec_monitor-vc110-mt-gd-1_56 \
        -llibboost_signals-vc110-mt-gd-1_56 \
        -llibboost_timer-vc110-mt-gd-1_56 \
        -llibboost_unit_test_framework-vc110-mt-gd-1_56 \
        -llibboost_atomic-vc110-mt-1_56 \
        -llibboost_system-vc110-mt-1_56 \
        -llibboost_container-vc110-mt-1_56 \
        -llibboost_wave-vc110-mt-gd-1_56 \
        -llibboost_chrono-vc110-mt-1_56 \
        -llibboost_context-vc110-mt-1_56 \
        -llibboost_thread-vc110-mt-1_56 \
        -llibboost_coroutine-vc110-mt-1_56 \
        -llibboost_date_time-vc110-mt-1_56 \
        -llibboost_filesystem-vc110-mt-1_56 \
        -llibboost_regex-vc110-mt-1_56 \
        -llibboost_bzip2-vc110-mt-1_56 \
        -llibboost_graph-vc110-mt-1_56 \
        -llibboost_zlib-vc110-mt-1_56 \
        -llibboost_iostreams-vc110-mt-1_56 \
        -llibboost_locale-vc110-mt-1_56 \
        -llibboost_log-vc110-mt-1_56 \
        -llibboost_log_setup-vc110-mt-1_56 \
        -llibboost_math_c99-vc110-mt-1_56 \
        -llibboost_math_tr1f-vc110-mt-1_56 \
        -llibboost_math_tr1-vc110-mt-1_56 \
        -llibboost_math_c99f-vc110-mt-1_56 \
        -llibboost_math_c99l-vc110-mt-1_56 \
        -llibboost_math_tr1l-vc110-mt-1_56 \
        -llibboost_program_options-vc110-mt-1_56 \
        -llibboost_python-vc110-mt-1_56 \
        -llibboost_random-vc110-mt-1_56 \
        -llibboost_serialization-vc110-mt-1_56 \
        -llibboost_wserialization-vc110-mt-1_56 \
        -llibboost_prg_exec_monitor-vc110-mt-1_56 \
        -llibboost_signals-vc110-mt-1_56 \
        -llibboost_unit_test_framework-vc110-mt-1_56 \
        -llibboost_timer-vc110-mt-1_56 \
        -llibboost_wave-vc110-mt-1_56 \


#公用机器
#LIBS += -LP:/soft/opencv/build/x64/vc11/lib \
#    -lopencv_calib3d249d \
#    -lopencv_contrib249d \
#    -lopencv_core249d \
#    -lopencv_features2d249d \
#    -lopencv_flann249d \
#    -lopencv_gpu249d \
#    -lopencv_highgui249d \
#    -lopencv_imgproc249d \
#    -lopencv_legacy249d \
#    -lopencv_ml249d \
#    -lopencv_nonfree249d \
#    -lopencv_objdetect249d \
#    -lopencv_ocl249d \
#    -lopencv_photo249d \
#    -lopencv_stitching249d \
#    -lopencv_superres249d \
#    -lopencv_ts249d \
#    -lopencv_video249d \
#    -lopencv_videostab249d


#自己电脑
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
        dialog.cpp \
    mytcpserver.cpp \
    package_bgs/FrameDifferenceBGS.cpp \
    processhogwork.cpp \
    package_bgs/MixtureOfGaussianV2BGS.cpp \
    package_tracking/BlobTracking.cpp \
    package_tracking/cvblob/cvaux.cpp \
    package_tracking/cvblob/cvblob.cpp \
    package_tracking/cvblob/cvcolor.cpp \
    package_tracking/cvblob/cvcontour.cpp \
    package_tracking/cvblob/cvlabel.cpp \
    package_tracking/cvblob/cvtrack.cpp \
    package_analysis/VehicleCouting.cpp \
    package_bgs/pt/PBAS.cpp \
    package_bgs/pt/PixelBasedAdaptiveSegmenter.cpp

HEADERS  += dialog.h \
    mytcpserver.h \
    processhogwork.h \
    package_bgs/MixtureOfGaussianV2BGS.h \
    package_bgs/FrameDifferenceBGS.h \
    package_tracking/BlobTracking.h \
    package_tracking/cvblob/cvblob.h \
    package_analysis/VehicleCouting.h \
    package_bgs/pt/PBAS.h \
    package_bgs/pt/PixelBasedAdaptiveSegmenter.h

FORMS    += dialog.ui

RESOURCES += \
    myres.qrc
