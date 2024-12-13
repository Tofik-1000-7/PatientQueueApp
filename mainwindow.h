#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "registrationwindow.h"
#include "receptionwindow.h"
#include "queuewindow.h"
#include <QQueue>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;  // Обработка события закрытия окна

private slots:
    void showRegistrationWindow();
    void showReceptionWindow();
    void showQueueWindow();

private:
    QQueue<Patient> patientQueue;
    RegistrationWindow *registrationWindow;
    ReceptionWindow *receptionWindow;
    QueueWindow *queueWindow;
};

#endif // MAINWINDOW_H
