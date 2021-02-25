#ifndef ADMIN_DIALOG_H
#define ADMIN_DIALOG_H

#include <workers_table.h>
#include <workers.h>
#include <departments_table.h>
#include <departments.h>

#include <QDialog>
#include <QTabWidget>
#include <QPushButton>

class AdminDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AdminDialog(bool isAdmin, QWidget *parent = nullptr);
    ~AdminDialog();

private slots:
    void handleBackButton();

private:
    QTabWidget *tabWidget;
    QPushButton *backButton;
    WorkersTable *workersTable;
    DepartmentsTable *departmentsTable;
    Departments *departments;
    Workers *workers;

};

#endif // ADMIN_DIALOG_H
