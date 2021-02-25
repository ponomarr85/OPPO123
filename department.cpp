#include "department.h"

Department::Department()
{
}

QDataStream &operator >>(QDataStream &inputStream, Department &department)
{
    inputStream >> department.mName
        >> department.mDirector
        >> department.mId;
    return inputStream;
}

QDataStream &operator <<(QDataStream &outputStream, const Department &department)
{
    outputStream << department.mName
        << department.mDirector
        << department.mId;
    return outputStream;
}

const QString &Department::name() const
{
    return mName;
}

void Department::setName(const QString &name)
{
    mName = name;
}

const QString &Department::director() const
{
    return mDirector;
}

void Department::setDirector(const QString &director)
{
    mDirector = director;
}

const int &Department::id() const
{
    return mId;
}

void Department::setId(const int &id)
{
    mId = id;
}
