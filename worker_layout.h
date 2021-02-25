#ifndef WORKER_LAYOUT_H
#define WORKER_LAYOUT_H

#include <worker.h>

#include <QWidget>
#include <QLabel>
#include <QFormLayout>

class WorkerLayout : public QWidget
{
    Q_OBJECT
public:
    explicit WorkerLayout(Worker worker, QWidget *parent = nullptr);
};

#endif // WORKER_LAYOUT_H
