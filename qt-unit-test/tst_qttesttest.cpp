#include <QString>
#include <QtTest>
#include "person.h"
#include "shizheyunsuang.h"
class QttestTest : public QObject
{
    Q_OBJECT

public:
    QttestTest();

private Q_SLOTS:
    void testCase1();
    void testCase2();
};

QttestTest::QttestTest()
{
}

void QttestTest::testCase1()
{
    QString str = "Hello";
    QVERIFY(str.toUpper() == "HELLO");
    //QVERIFY2(true, "Failure");
//  测试类的属性
    Person *p= new Person();
    p->setAge(10);
    p->setName("leeyoung");
    QVERIFY(p->getAge() == 10);


    //测试数学运算
    shizheyunsuang test = shizheyunsuang();

    QVERIFY(test.add(1,2) == 3);
    QVERIFY(test.sub(1,2) == -1);
    QVERIFY(test.mult(1,2) == 2);
    QVERIFY(test.div(10,3) == 3);

}

//测试类的方法
void QttestTest::testCase2()
{
//    QString str = "Hello";
//    QVERIFY(str.toUpper() == "HELLO");
//    QVERIFY2(true, "Failure");

    Person *p= new Person();
    p->setAge(10);
    p->setName("leeyoung");
    QVERIFY(p->eat() == QString("eating"));
}


QTEST_APPLESS_MAIN(QttestTest)

#include "tst_qttesttest.moc"
