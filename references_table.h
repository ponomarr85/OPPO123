#ifndef REFERENCES_TABLE_H
#define REFERENCES_TABLE_H

#include <references.h>

#include <QWidget>
#include <QPushButton>
#include <QTableView>
#include <QItemDelegate>

class ReferencesTable : public QWidget
{
    Q_OBJECT
public:
    explicit ReferencesTable(bool isEditable, int workerId, References *references, QWidget *parent = nullptr);
    ~ReferencesTable();

private slots:
    void handleClickAddButton();

private:
    QTableView *table;
    QPushButton *addButton;
    References *references;
    int workerId;
};


#endif // REFERENCES_TABLE_H
