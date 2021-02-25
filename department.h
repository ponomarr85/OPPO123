#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <QString>
#include <QDataStream>

class Department
{
public:
    Department();

    friend QDataStream &operator >>(QDataStream &inputStream, Department &department);

    friend QDataStream &operator <<(QDataStream &outputStream, const Department &department);

    const QString &name() const;

    void setName(const QString &name);

    const QString &director() const;

    void setDirector(const QString &director);

    const int &id() const;

    void setId(const int &id);
private:
    QString mName, mDirector;
    int mId;
};

#endif // DEPARTMENT_H
