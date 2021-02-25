#ifndef DEPARTMENTSTABLE_H
#define DEPARTMENTSTABLE_H

#include <departments.h>

#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QItemDelegate>
#include <QMessageBox>
#include <QLineEdit>
#include <QComboBox>

class DepartmentsTable: public QWidget
{
    Q_OBJECT
public:
    explicit DepartmentsTable(bool isAdmin, Departments *departments, QWidget *parent = nullptr);
    ~DepartmentsTable();

private slots:
    void handleClickAddButton();
    void handleClickRemoveButton();

private:
    QTableView *table;
    QPushButton *addButton;
    QPushButton *removeButton;
    Departments* departments;
};

#endif // DEPARTMENTSTABLE_H
