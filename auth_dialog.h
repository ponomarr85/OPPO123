#ifndef AUTH_DIALOG_H
#define AUTH_DIALOG_H

#include <QDialog>
#include <QMessageBox>

#include <worker_dialog.h>
#include <worker.h>
#include <workers.h>
#include <admin_dialog.h>
#include "ui_auth.h"

namespace Ui {
class AuthDialog;
}

class AuthDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AuthDialog(QWidget *parent = nullptr);
    ~AuthDialog();

private slots:
    void on_auth_btn_clicked();

private:
    Ui::AuthDialog *ui;
    WorkerDialog *workerView;
};

#endif // AUTH_DIALOG_H
