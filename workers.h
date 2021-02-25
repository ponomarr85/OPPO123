#ifndef WORKERS_H
#define WORKERS_H

#include <worker.h>
#include <departments.h>

#include <QAbstractTableModel>
#include <QFile>

class Workers : public QAbstractTableModel
{
    Q_OBJECT;
public:
    Workers(Departments* departments);
    ~Workers();
    void save();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void add(Worker worker);
    void remove(int idx);
    Worker get(int i);
    Worker findByUsernameAndPassword(QString username, QString password);

private:
    Departments *departments;
    QVector<Worker> mWorkers;
};

#endif // WORKERS_H
