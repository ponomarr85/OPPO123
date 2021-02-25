#include "reference.h"

Reference::Reference()
{
}

QDataStream &operator >>(QDataStream &inputStream, Reference &reference)
{
    inputStream >> reference.mNumber
            >> reference.mWorkerId
            >> reference.mDescription
            >> reference.mCreatedDate;
    return inputStream;
}

QDataStream &operator <<(QDataStream &outputStream, const Reference &reference)
{
    outputStream << reference.mNumber
                 << reference.mWorkerId
                 << reference.mDescription
                 << reference.mCreatedDate;

    return outputStream;
}

const int &Reference::number() const
{
    return mNumber;
}

void Reference::setNumber(const int &number)
{
    mNumber = number;
}

const int &Reference::workerId() const
{
    return mWorkerId;
}

void Reference::setWorkerId(const int &workerId)
{
    mWorkerId = workerId;
}

const QString &Reference::description() const
{
    return mDescription;
}

void Reference::setDescription(const QString &description)
{
    mDescription = description;
}

const QString &Reference::createdDate() const
{
    return mCreatedDate;
}

void Reference::setCreatedDate(const QString &createdDate)
{
    mCreatedDate = createdDate;
}
