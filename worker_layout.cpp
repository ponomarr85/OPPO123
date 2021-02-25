#include "worker_layout.h"
#include "departments.h"

WorkerLayout::WorkerLayout(Worker worker, QWidget *parent) : QWidget(parent)
{
    QFormLayout *mainLayout = new QFormLayout;

    mainLayout->addRow(tr("Фамилия"), new QLabel(worker.lastName()));
    mainLayout->addRow(tr("Имя:"), new QLabel(worker.firstName()));
    mainLayout->addRow(tr("Отчество:"), new QLabel(worker.middleName()));
    mainLayout->addRow(tr("День рождения:"), new QLabel(worker.birthday()));
    mainLayout->addRow(tr("Семейное положение:"), new QLabel(worker.familiyStatus()));
    mainLayout->addRow(tr("Количество детей:"), new QLabel(QString::number(worker.numberOfChildren())));
    mainLayout->addRow(tr("Образование:"), new QLabel(worker.education()));
    mainLayout->addRow(tr("Профессия:"), new QLabel(worker.profession()));
    mainLayout->addRow(tr("Серийный номер:"), new QLabel(QString::number(worker.serialNumber())));
    Departments *departments = new Departments();
    Department *department = departments->findById(worker.departmentId());
    if (department)
    {
        mainLayout->addRow(tr("Подразделение:"), new QLabel(department->name()));
        mainLayout->addRow(tr("Руководитель:"), new QLabel(department->director()));
    }

    setLayout(mainLayout);
}

