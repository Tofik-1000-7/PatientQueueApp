#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QQueue>
#include "patient.h"

class RegistrationWindow : public QWidget
{
    Q_OBJECT
public:
    explicit RegistrationWindow(QQueue<Patient> *queue, QWidget *parent = nullptr);

signals:
    void queueUpdated();  // Сигнал для обновления очереди

private slots:
    void addPatient();

private:
    QLineEdit *patientNameInput;
    QQueue<Patient> *queue;
    int currentMaxId;
};

#endif // REGISTRATIONWINDOW_H
