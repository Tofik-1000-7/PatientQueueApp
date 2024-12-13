#include "mainwindow.h"
#include <QApplication>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Меню");

    // Создаем кнопки
    QPushButton *registrationButton = new QPushButton("Регистрация пациента", this);
    QPushButton *receptionButton = new QPushButton("Прием пациента", this);
    QPushButton *queueButton = new QPushButton("Очередь пациентов", this);

    //Создаем окна
    registrationWindow = new RegistrationWindow(&patientQueue);
    receptionWindow = new ReceptionWindow(&patientQueue);
    queueWindow = new QueueWindow(&patientQueue);

    // Создаем layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(registrationButton);
    layout->addWidget(receptionButton);
    layout->addWidget(queueButton);

    setLayout(layout);

    // Подключаем кнопки к слотам
    connect(registrationButton, &QPushButton::clicked, this, &MainWindow::showRegistrationWindow);
    connect(receptionButton, &QPushButton::clicked, this, &MainWindow::showReceptionWindow);
    connect(queueButton, &QPushButton::clicked, this, &MainWindow::showQueueWindow);

    connect(registrationWindow, &RegistrationWindow::queueUpdated, queueWindow, &QueueWindow::updateQueueList);
    connect(receptionWindow, &ReceptionWindow::queueUpdated, queueWindow, &QueueWindow::updateQueueList);
}

MainWindow::~MainWindow(){
    delete registrationWindow;
    delete receptionWindow;
    delete queueWindow;
}

void MainWindow::showRegistrationWindow()
{
    registrationWindow->show();
}

void MainWindow::showReceptionWindow()
{
    receptionWindow->show();
}

void MainWindow::showQueueWindow()
{
    queueWindow->show();
}

void MainWindow::closeEvent(QCloseEvent *event){
    Q_UNUSED(event);
    QApplication::quit();
}
