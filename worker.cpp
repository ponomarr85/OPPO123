#include "worker.h"

Worker::Worker()
{
}

QDataStream &operator >>(QDataStream &inputStream, Worker &worker)
{
    inputStream >> worker.mLastName
        >> worker.mFirstName
        >> worker.mMiddleName
        >> worker.mBirthday

        >> worker.mFamilyStatus
        >> worker.mNumberOfChildren
        >> worker.mSerialNumber

        >> worker.mUsername
        >> worker.mPassword
        >> worker.mRole

        >> worker.mEducation
        >> worker.mProfession


        >> worker.mDepartmentId;

    return inputStream;
}

QDataStream &operator <<(QDataStream &outputStream, const Worker &worker)
{
    outputStream << worker.mLastName
        << worker.mFirstName
        << worker.mMiddleName
        << worker.mBirthday

        << worker.mFamilyStatus
        << worker.mNumberOfChildren
        << worker.mSerialNumber

        << worker.mUsername
        << worker.mPassword
        << worker.mRole

        << worker.mEducation
        << worker.mProfession


        << worker.mDepartmentId;
    return outputStream;
}

const QString &Worker::username() const
{
    return mUsername;
}

void Worker::setUsername(const QString &username)
{
    mUsername = username;
}

const QString &Worker::password() const
{
    return mPassword;
}

void Worker::setPassword(const QString &password)
{
    mPassword = password;
}

const QString &Worker::role() const
{
    return mRole;
}

void Worker::setRole(const QString &role)
{
    mRole = role;
}

const QString &Worker::lastName() const
{
    return mLastName;
}

void Worker::setLastName(const QString &lastName)
{
    mLastName = lastName;
}

const QString &Worker::firstName() const
{
    return mFirstName;
}

void Worker::setFirstName(const QString &firstName)
{
    mFirstName = firstName;
}

const QString &Worker::middleName() const
{
    return mMiddleName;
}

void Worker::setMiddleName(const QString &middleName)
{
    mMiddleName = middleName;
}

const QString &Worker::birthday() const
{
    return mBirthday;
}

void Worker::setBirthday(const QString &birthday)
{
    mBirthday = birthday;
}

const QString &Worker::familiyStatus() const
{
    return mFamilyStatus;
}

void Worker::setFamilyStatus(const QString &familyStatus)
{
    mFamilyStatus = familyStatus;
}

const int &Worker::numberOfChildren() const
{
    return mNumberOfChildren;
}

void Worker::setNumberOfChildren(const int &numberOfChildren)
{
    mNumberOfChildren = numberOfChildren;
}

const int &Worker::serialNumber() const
{
    return mSerialNumber;
}

void Worker::setSerialNumber(const int &serialNumber)
{
    mSerialNumber = serialNumber;
}

const QString &Worker::education() const
{
    return mEducation;
}

void Worker::setEducation(const QString &education)
{
    mEducation = education;
}

const QString &Worker::profession() const
{
    return mProfession;
}

void Worker::setProfession(const QString &profession)
{
    mProfession = profession;
}


const int &Worker::departmentId() const
{
    return mDepartmentId;
}

void Worker::setDepartmentId(const int &departmentId)
{
    mDepartmentId = departmentId;
}
