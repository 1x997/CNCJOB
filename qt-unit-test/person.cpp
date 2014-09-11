#include "person.h"

Person::Person()
{

}
QString Person::getName() const
{
    return name;
}

void Person::setName(const QString &value)
{
    name = value;
}

int Person::getAge() const
{
    return age;
}

void Person::setAge(int value)
{
    age = value;
}


QString Person::eat()
{

   // qDebug()<<"eating";
    return QString("eating");

}
