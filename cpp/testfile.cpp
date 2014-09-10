#include "testfile.h"
#include <QFile>
#include <QDebug>
testfile::testfile()
{
}

void testfile::testwrite()
{

    QFile file("out.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << "The magic number is: " << 49 << "\n";

}

void testfile::testread()
{
    //    方法1
    //        QFile file("in.txt");
    //        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    //            return;

    //        while (!file.atEnd()) {
    //            QByteArray line = file.readLine();
    //            //process_line(line);
    //            qDebug()<<line;
    //        }


    //    方法2
    //       QFile file("in.txt");
    //       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    //           return;

    //       QTextStream in(&file);



    //方法3
    //          QFile file("/proc/modules");
    //          if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    //              return;

    //          QTextStream in(&file);
    //          QString line = in.readLine();
    //          while (!line.isNull()) {
    //              process_line(line);
    //              line = in.readLine();
    //          }


    QFile file;
    QDir::setCurrent(".");
    file.setFileName("in.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QDir::setCurrent("..");
    QFile file2("out.txt");
    if (!file2.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out2(&file2);


    // for out file
    //       QFile file2("out.txt");
    //       if (!file2.open(QIODevice::WriteOnly | QIODevice::Text))
    //           return;
    //       QTextStream out2(&file2);

    //copy file in.txt -----> out.txt
    while (!in.atEnd()) {
        QString line = in.readLine();
        qDebug()<<line;
        out2<<line<<"\n";
    }


}

void testfile::printError(const char *msg)
{
    QFile file;
    file.open(stdout, QIODevice::WriteOnly);//stdeer
    file.write(msg, qstrlen(msg));        // write to stderr
    file.close();

}

void testfile::testrename()
{
    QFile file2("out.txt");
    file2.rename("out2.txt");

}

void testfile::testremove()
{
    QDir::setCurrent("..");//某文件夹下out.txt文件如果存在则删除
    if(QFile::exists("out.txt")){
        QFile::remove("out.txt");//remove file
    }

//    QFile::remove("out2.txt");//remove file

}
