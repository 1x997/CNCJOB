#ifndef SHIZHEYUNSUANG_H
#define SHIZHEYUNSUANG_H

#include <QObject>

class shizheyunsuang : public QObject
{
    Q_OBJECT
public:
    explicit shizheyunsuang(QObject *parent = 0);

signals:

public:
    int add(int a,int b);
    int sub(int a,int b);
    int mult(int a ,int b);
    int div(int a,int b);

public slots:

};

#endif // SHIZHEYUNSUANG_H
