#ifndef QUEUEWINDOW_H
#define QUEUEWINDOW_H

#include <QWidget>
#include <QListWidget>
#include <QQueue>
#include <QVBoxLayout>
#include "patient.h"

class QueueWindow : public QWidget
{
    Q_OBJECT
public:
    explicit QueueWindow(QQueue<Patient> *queue, QWidget *parent = nullptr);

public slots:
    void updateQueueList();  // Слот для обновления очереди

private:
    QListWidget *listWidget;
    QQueue<Patient> *queue;
};

#endif // QUEUEWINDOW_H
