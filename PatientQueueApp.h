#ifndef PATIENTQUEUEAPP_H
#define PATIENTQUEUEAPP_H

#include <QMainWindow>
#include <QQueue>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QStackedWidget>
#include <QMenuBar>

class PatientQueueApp : public QMainWindow {
    Q_OBJECT

public:
    explicit PatientQueueApp(QWidget* parent = nullptr);

private slots:
    void registerPatient();
    void takePatient();
    void showQueue();
    void switchToRegisterScreen();
    void switchToTakeScreen();
    void switchToQueueScreen();

private:
    QQueue<QString>* patientQueue;  // Очередь пациентов
    QLineEdit* nameInput;           // Поле для ввода имени пациента
    QListWidget* queueList;         // Виджет для отображения очереди
    int patientCount;               // Счётчик для уникальных номеров пациентов
    QStackedWidget* stackedWidget;  // Для переключения между экранами
};

#endif // PATIENTQUEUEAPP_H
