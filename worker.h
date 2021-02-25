#ifndef WORKER_H
#define WORKER_H

#include <QDataStream>
#include <QDate>
#include <QString>

class Worker
{
public:
    Worker();

    friend QDataStream &operator >>(QDataStream &inputStream, Worker &worker);

    friend QDataStream &operator <<(QDataStream &outputStream, const Worker &user);

    const QString &username() const;

    void setUsername(const QString &username);

    const QString &password() const;

    void setPassword(const QString &password);

    const QString &role() const;

    void setRole(const QString &role);

    const QString &lastName() const;

    void setLastName(const QString &lastName);

    const QString &firstName() const;

    void setFirstName(const QString &firstName);

    const QString &middleName() const;

    void setMiddleName(const QString &middleName);

    const QString &birthday() const;

    void setBirthday(const QString &birthday);

    const QString &familiyStatus() const;

    void setFamilyStatus(const QString &familyStatus);

    const int &numberOfChildren() const;

    void setNumberOfChildren(const int &numberOfChildren);

    const int &serialNumber() const;

    void setSerialNumber(const int &serialNumber);

    const QString &education() const;

    void setEducation(const QString &education);

    const QString &profession() const;

    void setProfession(const QString &profession);

    const bool &isFired() const;

    void setIsFired(const bool &isFired);

    const int &departmentId() const;

    void setDepartmentId(const int &departmentId);

private:
    QString mUsername, mPassword, mRole; // Поля для авторизации
    QString mLastName, mFirstName, mMiddleName, mBirthday, mFamilyStatus;
    int mNumberOfChildren;
    QString mEducation, mProfession;
    int mSerialNumber, mDepartmentId;
};

#endif // WORKER_H
