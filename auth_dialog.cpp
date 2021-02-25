#include "auth_dialog.h"

AuthDialog::AuthDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthDialog)
{
    ui->setupUi(this);
    ui->usernameField->setText("admin"); // Можно стереть
    ui->passwordField->setText("admin");
    setWindowTitle("Авторизация");
}

AuthDialog::~AuthDialog()
{
    delete ui;
}

void AuthDialog::on_auth_btn_clicked()
{
    QString username = ui->usernameField->text();
    QString password = ui->passwordField->text();
    if (username == "admin" && password == "admin")
    {
        AdminDialog *adminDialog = new AdminDialog(true, this);
        adminDialog->show();
        hide();
    } else
    {
        Departments *departments = new Departments();
        Workers *workers = new Workers(departments);
        Worker worker = workers->findByUsernameAndPassword(username, password);
        if (worker.serialNumber() == -1)
        {
            QMessageBox::warning(this, QString(tr("Ошибка")),
                                         QString(tr("Введён неверный логин или пароль")),
                                         QMessageBox::Ok);
        } else
        {
            if (worker.role() == "Администратор")
            {
                AdminDialog *adminDialog = new AdminDialog(true, this);
                adminDialog->show();
                hide();
            } else if (worker.role() == "Диспетчер")
            {
                AdminDialog *adminDialog = new AdminDialog(false, this);
                adminDialog->show();
                hide();
            } else if (worker.role() == "Работник")
            {
                WorkerDialog *workerDialog = new WorkerDialog(worker, this);
                workerDialog->show();
                hide();
            } else
            {
                QMessageBox::warning(this, QString(tr("Ошибка")),
                                             QString(tr("Пользователь содержит неверную роль")),
                                             QMessageBox::Ok);
            }
        }
    }
}
