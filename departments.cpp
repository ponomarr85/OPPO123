#include "departments.h"

Departments::Departments()
{
    beginInsertRows(QModelIndex(), 0, rowCount(QModelIndex()));

    QFile file("/Users/ponomarr85/test/Departments.bin");
    file.open(QIODevice::ReadOnly);

    QDataStream inputStream(&file);

    Department temporaryDepartment;

    while(!file.atEnd())
    {
        inputStream >> temporaryDepartment;
        add(temporaryDepartment);
    }
    file.close();
    endInsertRows();
}

Departments::~Departments()
{
    save();
}

void Departments::save()
{
    QFile file("/Users/ponomarr85/test/Departments.bin");
    file.open(QIODevice::WriteOnly);

    QDataStream outputStream(&file);

    for (int i = 0; i < rowCount(QModelIndex()); ++i)
    {
        outputStream << mDepartments[i];
    }
    file.close();
}

int Departments::columnCount(const QModelIndex &parent) const
{
    return 3;
}

int Departments::rowCount(const QModelIndex &parent) const
{
    return mDepartments.size();
}

QVariant Departments::headerData(int column, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        // Если речь о заголовках столбцов...
        if (orientation == Qt::Horizontal)
        {
            switch(column)
            {
            case 0: return "Номер";
            case 1: return "Название";
            case 2: return "Руководитель";
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

QVariant Departments::data(const QModelIndex &index, int role) const
{
    // Если требуется текст для отображения...
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        Department department = mDepartments[index.row()];
        switch (index.column())
        {
        case 0: return department.id();
        case 1: return department.name();
        case 2: return department.director();
        default: return QVariant();
        }
    }
    // Игнорируем все остальные запросы, возвращая пустой QVariant
    return QVariant();
}

bool Departments::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!checkIndex(index))
    {
        return false;
    }
    //save value from editor to member m_gridData
    Department &department = mDepartments[index.row()];
    if (index.column() == 1)
    {
        department.setName(value.toString());
    } else if (index.column() == 2)
    {
        department.setDirector(value.toString());
    }
    return true;
}

Qt::ItemFlags Departments::flags(const QModelIndex &index) const
{
    if (index.column() == 0)
    {
        return Qt::NoItemFlags;
    }
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

Department Departments::get(int idx)
{
    return mDepartments[idx];
}

Department *Departments::findById(int id)
{
    for (int i = 0; i < mDepartments.size(); ++i)
    {
        Department department = mDepartments[i];
        if (department.id() == id)
        {
            Department *result = new Department;
            result->setId(department.id());
            result->setName(department.name());
            result->setDirector(department.director());
            return result;
        }
    }
    return NULL;
}

void Departments::add(Department department)
{
    QModelIndex index = QModelIndex();
    beginInsertRows(index, rowCount(index), rowCount(index));
    mDepartments.push_back(department);
    endInsertRows();
}

void Departments::remove(int idx)
{
    beginRemoveRows(QModelIndex(), idx, idx);
    mDepartments.erase(std::next(mDepartments.begin(), idx));
    endRemoveRows();
}
