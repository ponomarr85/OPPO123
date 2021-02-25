#include "departments_table.h"
#include <QDebug>

DepartmentsTable::DepartmentsTable(bool isAdmin, Departments *departments, QWidget *parent) : QWidget(parent)
{
    this->departments = departments;
    QVBoxLayout *mainLayout = new QVBoxLayout;

    table = new QTableView;
    table->setModel(departments);
    mainLayout->addWidget(table);

    addButton = new QPushButton(tr("Добавить подразделение"));
    connect(addButton, &QPushButton::released, this, &DepartmentsTable::handleClickAddButton);

    removeButton = new QPushButton(tr("Удалить подразделение"));
    connect(removeButton, &QPushButton::released, this, &DepartmentsTable::handleClickRemoveButton);
    if (isAdmin == true)
    {
        mainLayout->addWidget(addButton);
        mainLayout->addWidget(removeButton);
    }

    setLayout(mainLayout);
}

DepartmentsTable::~DepartmentsTable()
{
    delete table;
    delete addButton;
    delete removeButton;
}

void DepartmentsTable::handleClickAddButton()
{
    int maxId = 0;
    for (int i = 0;i < departments->rowCount(QModelIndex()); i++) {
        Department department = departments->get(i);
        if (department.id() > maxId) {
            maxId = department.id();
        }
    }
    Department department;
    department.setId(maxId + 1);
    department.setName("ИВТ");
    department.setDirector("Макуха");
    departments->add(department);
}

void DepartmentsTable::handleClickRemoveButton()
{
    int ask = QMessageBox::question(this,
                                          QString("Предупреждение"),
                                          QString("Вы действительно хотите удалить  подразделение?"),
                                          QMessageBox::Yes | QMessageBox::No);
    if (ask == QMessageBox::Yes)
    {
        QModelIndexList selectedRows = table->selectionModel()->selectedRows();
        for (const auto &row : selectedRows)
        {
            departments->remove(row.row());
        }
    }
}
