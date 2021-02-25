#include "workers.h"

Workers::Workers(Departments *departments)
{
    this->departments = departments;
    // Читаем данные из файла
    beginInsertRows(QModelIndex(), 0, rowCount(QModelIndex()));

    QFile file("/Users/ponomarr85/test/Workers.bin");
    file.open(QIODevice::ReadOnly);

    QDataStream inputStream(&file);

    Worker temporaryWorker;

    while(!file.atEnd())
    {
        inputStream >> temporaryWorker;
        add(temporaryWorker);
    }

    file.close();

    endInsertRows();
}

Workers::~Workers()
{
    save();
}

void Workers::save()
{
    // Записываем данные в файл
    QFile file("/Users/ponomarr85/test/Workers.bin");
    file.open(QIODevice::WriteOnly);

    QDataStream outputStream(&file);

    for (int i = 0; i < rowCount(QModelIndex()); ++i)
    {
        outputStream << mWorkers[i];
    }
    file.close();
}

int Workers::columnCount(const QModelIndex &parent) const
{
    return 13;
}

int Workers::rowCount(const QModelIndex &parent) const
{
    return mWorkers.size();
}

QVariant Workers::headerData(int column, Qt::Orientation orientation, int role) const
{
    // Если требуется текст для отображения...
    if (role == Qt::DisplayRole)
    {
        // Если речь о заголовках столбцов...
        if (orientation == Qt::Horizontal)
        {
            switch(column)
            {
            case 0: return "Фамилия";
            case 1: return "Имя";
            case 2: return "Отчество";
            case 3: return "Дата рождения";
            case 4: return "Семейное положение";
            case 5: return "Количество детей";
            case 6: return "Серийный номер";
            case 7: return "Образование";
            case 8: return "Профессия";
            case 9: return "Департамент";
            case 10: return "Логин";
            case 11: return "Пароль";
            case 12: return "Роль";
            default: return QVariant();
            }
        }
        // Номер строки
        else if (orientation == Qt::Vertical)
        {
            return column + 1;
        }
    }
     // Игнорируем все остальные запросы, возвращая пустой QVariant
    return QVariant();
}

QVariant Workers::data(const QModelIndex &index, int role) const
{
    // Если требуется текст для отображения...
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        Worker worker = mWorkers[index.row()];
        // Извлекаем данные, на основе Если столбец первый, возвращаем заголовок заметки, находящейся в соответствующей строке таблицы
        switch (index.column())
        {
        case 0: return worker.lastName();
        case 1: return worker.firstName();
        case 2: return worker.middleName();
        case 3: return worker.birthday();
        case 4: return worker.familiyStatus();
        case 5: return worker.numberOfChildren();
        case 6: return worker.serialNumber();
        case 7: return worker.education();
        case 8: return worker.profession();
        case 9:
        {
            Department* department = departments->findById(worker.departmentId());
            if (department)
            {
                return department->name();
            }
            return "";
        }
        case 10: return worker.username();
        case 11: return worker.password();
        case 12: return worker.role();
        default: return QVariant();
        }
    }
    // Игнорируем все остальные запросы, возвращая пустой QVariant
    return QVariant();
}

bool Workers::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!checkIndex(index))
    {
        return false;
    }
    // Сохраняем данные в поля, в зависимости от индекса колонки
    Worker &worker = mWorkers[index.row()];
    switch (index.column())
    {
    case 0:
        worker.setLastName(value.toString());
        break;
    case 1:
        worker.setFirstName(value.toString());
        break;
    case 2:
        worker.setMiddleName(value.toString());
        break;
    case 3:
        worker.setBirthday(value.toString());
        break;
    case 4:
        worker.setFamilyStatus(value.toString());
        break;
    case 5:
        worker.setNumberOfChildren(value.toInt());
        break;
    case 7:
        worker.setEducation(value.toString());
        break;
    case 8:
        worker.setProfession(value.toString());
        break;
    case 9:
        worker.setDepartmentId(value.toInt());
        break;
    case 10:
        worker.setUsername(value.toString());
        break;
    case 11:
        worker.setPassword(value.toString());
        break;
    case 12:
        worker.setRole(value.toString());
        break;
    }
    return true;
}

Qt::ItemFlags Workers::flags(const QModelIndex &index) const
{
    if (index.column() == 6) // Не даём изменить серийный номер, т.к. он генерируется автоматически
    {
        return Qt::NoItemFlags;
    }
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

void Workers::add(Worker worker)
{
    QModelIndex index = QModelIndex();
    beginInsertRows(index, rowCount(index), rowCount(index));
    mWorkers.push_back(worker);
    endInsertRows();
}

void Workers::remove(int idx)
{
    beginRemoveRows(QModelIndex(), idx, idx);
    mWorkers.erase(std::next(mWorkers.begin(), idx));
    endRemoveRows();
}

Worker Workers::get(int i)
{
    return mWorkers[i];
}

Worker Workers::findByUsernameAndPassword(QString username, QString password)
{
    for (int i = 0; i < mWorkers.size(); ++i)
    {
        Worker worker = mWorkers[i];
        if (worker.username() == username && worker.password() == password)
        {
            return worker;
        }
    }
    Worker notFoundWorker = Worker();
    notFoundWorker.setSerialNumber(-1);
    return notFoundWorker;
}
