#ifndef RECEPTIONWINDOW_H
#define RECEPTIONWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QQueue>
#include <QVBoxLayout>
#include "patient.h"

class ReceptionWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ReceptionWindow(QQueue<Patient> *queue, QWidget *parent = nullptr);

signals:
    void queueUpdated();  // Сигнал для обновления очереди

private slots:
    void receivePatient();

private:
    QLabel *statusLabel;
    QQueue<Patient> *queue;
};

#endif // RECEPTIONWINDOW_H
