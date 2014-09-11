#ifndef PERSON_H
#define PERSON_H
#include <QDebug>
#include <QString>
class Person
{
public:
    Person();
private:
    int age;
    QString name;

public:
    QString eat();
    int getAge() const;
    void setAge(int value);
    QString getName() const;
    void setName(const QString &value);
};

#endif // PERSON_H
