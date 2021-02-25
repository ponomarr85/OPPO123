#include "reference_dialog.h"
#include <QVBoxLayout>

ReferenceDialog::ReferenceDialog(int workerId, References *references, QWidget *parent) : QDialog(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;

    closeButton = new QPushButton("Закрыть");
    connect(closeButton, &QPushButton::released, this, &ReferenceDialog::handleClickCloseButton);
    mainLayout->addWidget(closeButton);

    table = new ReferencesTable(true, workerId, references, this);
    mainLayout->addWidget(table);

    resize(800, 640);
    setLayout(mainLayout);
    setWindowTitle("Окно справок");
}

ReferenceDialog::~ReferenceDialog()
{
    delete table;
    delete closeButton;
}

void ReferenceDialog::handleClickCloseButton()
{
    accept();
}
