#ifndef DEPARTMENTS_H
#define DEPARTMENTS_H

#include <department.h>

#include <QAbstractTableModel>
#include <QFile>

class Departments : public QAbstractTableModel
{
    Q_OBJECT;
public:
    Departments();
    ~Departments();

    void save();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    Department get(int idx);
    Department *findById(int id);
    void add(Department department);
    void remove(int idx);

private:
    QVector<Department> mDepartments;
};

#endif // DEPARTMENTS_H
