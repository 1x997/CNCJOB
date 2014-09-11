#include "shizheyunsuang.h"

shizheyunsuang::shizheyunsuang(QObject *parent) :
    QObject(parent)
{
}

int shizheyunsuang::add(int a, int b)
{
    return a+b;

}

int shizheyunsuang::sub(int a, int b)
{
    return a-b;
}

int shizheyunsuang::mult(int a, int b)
{
    return a*b;
}

int shizheyunsuang::div(int a, int b)
{
    return a/b;
}
