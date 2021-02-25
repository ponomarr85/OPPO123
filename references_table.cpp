#include "references_table.h"
#include <QVBoxLayout>
#include <QDateTime>
#include <QLineEdit>

ReferencesTable::ReferencesTable(bool isEditable, int workerId, References *references, QWidget *parent) : QWidget(parent)
{
    this->references = references;
    this->workerId = workerId;

    QVBoxLayout *mainLayout = new QVBoxLayout;

    table = new QTableView;
    table->setModel(references);
    mainLayout->addWidget(table);
    for (int i = 0; i < references->rowCount(QModelIndex()); ++i)
    {
        Reference reference = references->get(i);
        if (reference.workerId() != workerId)
        {
            table->hideRow(i);
        }
    }

    addButton = new QPushButton(tr("Добавить справку"));
    connect(addButton, &QPushButton::released, this, &ReferencesTable::handleClickAddButton);
    if (isEditable == true)
    {
        mainLayout->addWidget(addButton);
    } else
    {
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }

    setLayout(mainLayout);
}

ReferencesTable::~ReferencesTable()
{
    delete table;
    delete addButton;
}

void ReferencesTable::handleClickAddButton()
{
    int maxNumber = 0;
    for (int i = 0;i < references->rowCount(QModelIndex()); i++) {
        Reference reference = references->get(i);
        if (reference.number() > maxNumber) {
            maxNumber = reference.number();
        }
    }
    Reference reference;
    reference.setNumber(maxNumber + 1);
    reference.setWorkerId(workerId);
    reference.setCreatedDate(QDateTime::currentDateTime().toString(("dd.MM.yyyy HH:mm:ss"))); // Записываем текущую дату и время
    references->add(reference);
}
