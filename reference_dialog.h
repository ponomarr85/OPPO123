#ifndef REFERENCEDIALOG_H
#define REFERENCEDIALOG_H

#include <references.h>
#include <references_table.h>

#include <QDialog>
#include <QWidget>
#include <QPushButton>

class ReferenceDialog : public QDialog
{
    Q_OBJECT
public:
    ReferenceDialog(int workerId, References *references, QWidget *parent = nullptr);
    ~ReferenceDialog();

private slots:
    void handleClickCloseButton();

private:
    QPushButton *closeButton;
    ReferencesTable *table;
};

#endif // REFERENCEDIALOG_H
