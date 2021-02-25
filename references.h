#ifndef REFERENCES_H
#define REFERENCES_H


#include <QAbstractTableModel>
#include <QFile>

class References : public QAbstractTableModel
{
public:

    void save();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
};

#endif // REFERENCES_H
