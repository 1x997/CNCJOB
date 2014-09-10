#include <iostream>
#include "opencv/cv.h"
#include "opencv2/opencv.hpp"
#include <QFile>
#include <QDir>
#include "testfile.h"

using namespace std;
using namespace cv;

//opencv qtcreator 模板
int main()
{
//    tree /f | clip   copy the stand out to the clipboard
//    卷 新加卷 的文件夹 PATH 列表
//    卷序列号为 0CB6-9CCD
//    H:.
//    │  1.jpg   *** 在qtcreator里调用的文件目录结构
//    │  clip
//    │  Makefile
//    │  Makefile.Debug
//    │  Makefile.Release
//    │
//    ├─debug
//    │      cpp.exe
//    │      cpp.exe.embed.manifest
//    │      cpp.exe_manifest.rc
//    │      cpp.exe_manifest.res
//    │      cpp.ilk
//    │      cpp.pdb
//    │      main.obj
//    │
//    └─release


//    test the opencv
//    Mat image=imread("1.jpg");
//    imshow("image1",image);
//    waitKey();



//    testfile t= testfile();
//    t.testread();
//    t.printError("std out ........................\n kkkkkkkkkkkkkkkkkkkkk");
//    t.testwrite();
//    t.testrename();
//    t.testremove();


//    QDir dir("example");
//    if (!dir.exists())
//        qWarning("Cannot find the example directory");


    /* QDir dir*/("H:/yuliyang/QT/build-cpp-Desktop_Qt_5_2_1_MSVC2012_64bit-Debug/debug");
     QDir dir;
     dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
     dir.setSorting(QDir::Size | QDir::Reversed);

     QFileInfoList list = dir.entryInfoList();
     std::cout << "Bytes Filename" << std::endl;
     for (int i = 0; i < list.size(); ++i) {
         QFileInfo fileInfo = list.at(i);
         std::cout << qPrintable(QString("%1 %2").arg(fileInfo.size(), 10)
                                                 .arg(fileInfo.fileName()));
         std::cout << std::endl;
     }





//    cout << "Hello World!" << endl;
    return 0;
}

