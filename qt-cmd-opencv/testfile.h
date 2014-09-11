#ifndef TESTFILE_H
#define TESTFILE_H
#include <QFile>
#include <QDir>
class testfile
{
public:
    testfile();
    void testwrite();
    void testread();
    void printError(const char* msg);
    void testrename();
    void testremove();
};

#endif // TESTFILE_H
