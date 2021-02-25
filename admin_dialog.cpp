#include "admin_dialog.h"
#include <auth_dialog.h>

AdminDialog::AdminDialog(bool isAdmin, QWidget *parent) : QDialog(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;

    departments = new Departments();
    workers = new Workers(departments);

    backButton = new QPushButton(tr("Выйти"));
    connect(backButton, &QPushButton::released, this, &AdminDialog::handleBackButton);
    mainLayout->addWidget(backButton);

    tabWidget = new QTabWidget;
    mainLayout->addWidget(tabWidget);

    workersTable = new WorkersTable(isAdmin, workers, departments, this);
    tabWidget->addTab(workersTable, "Работники");

    departmentsTable = new DepartmentsTable(isAdmin, departments);
    tabWidget->addTab(departmentsTable, "Подразделения");

    resize(1480, 1040); //Задаем размер окна
    setLayout(mainLayout);
    if (isAdmin)
    {
        setWindowTitle(tr("Окно администратора"));
    } else
    {
        setWindowTitle(tr("Окно диспетчера"));
    }
}

AdminDialog::~AdminDialog()
{
    departments->save();
    workers->save();
    delete tabWidget;
    delete backButton;
}

void AdminDialog::handleBackButton()
{
    departments->save();
    workers->save();
    hide();
    AuthDialog *authDialog = new AuthDialog(this);
    authDialog->show();
}
