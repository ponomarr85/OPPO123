#include "references.h"

References::References()
{
    beginInsertRows(QModelIndex(), 0, rowCount(QModelIndex()));

    QFile file("/Users/ponomarr85/test/References.bin");
    file.open(QIODevice::ReadOnly);

    QDataStream inputStream(&file);

    Reference temporaryReference;

    while(!file.atEnd())
    {
        inputStream >> temporaryReference;
        add(temporaryReference);
    }
    file.close();
    endInsertRows();
}

References::~References()
{
    save();
}

void References::save()
{
    QFile file("/Users/ponomarr85/test/References.bin");
    file.open(QIODevice::WriteOnly);

    QDataStream outputStream(&file);

    for (int i = 0; i < mReferences.size(); ++i)
    {
        outputStream << mReferences[i];
    }
    file.close();
}

int References::columnCount(const QModelIndex &parent) const
{
    return 3;
}

int References::rowCount(const QModelIndex &parent) const
{
    return mReferences.size();
}

QVariant References::headerData(int column, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        // Если речь о заголовках столбцов...
        if (orientation == Qt::Horizontal)
        {
            switch(column)
            {
            case 0: return "Номер";
            case 1: return "Описание";
            case 2: return "Дата создания";
            default: return QVariant();
            }
        }
        if (orientation == Qt::Vertical)
        {
            // Возвращаем номер строки
            return column + 1;
        }
    }
     // Игнорируем все остальные запросы, возвращая пустой QVariant
    return QVariant();
}

QVariant References::data(const QModelIndex &index, int role) const
{
    // Если требуется текст для отображения...
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        Reference reference = mReferences[index.row()];
        switch (index.column())
        {
        case 0: return reference.number();
        case 1: return reference.description();
        case 2: return reference.createdDate();
        }
    }
    // Игнорируем все остальные запросы, возвращая пустой QVariant
    return QVariant();
}

bool References::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!checkIndex(index))
    {
        return false;
    }
    //save value from editor to member m_gridData
    Reference &reference = mReferences[index.row()];
    if (index.column() == 1)
    {
        reference.setDescription(value.toString());
    }
    return true;
}

Qt::ItemFlags References::flags(const QModelIndex &index) const
{
    switch (index.column())
    {
    // Нельзя изменить номер справки и дату создания
    case 0:
    case 2:
        return Qt::NoItemFlags;
    default:
        return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
    }
}

Reference References::get(int idx)
{
    return mReferences[idx];
}

QVector<Reference> References::findByWorkerId(int workerId)
{
    QVector<Reference> result;
    for (int i = 0; i < mReferences.size(); ++i)
    {
        Reference reference = mReferences[i];
        if (reference.workerId() == workerId)
        {
            result.push_back(reference);
        }
    }
    return result;
}

void References::add(Reference reference)
{
    QModelIndex index = QModelIndex();
    beginInsertRows(index, rowCount(index), rowCount(index));
    mReferences.push_back(reference);
    endInsertRows();
}
