#include "PatientQueueApp.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QMenuBar>
#include <QAction>
#include <QPushButton>
#include <QStackedWidget>
#include <QHBoxLayout>

PatientQueueApp::PatientQueueApp(QWidget* parent)
    : QMainWindow(parent), patientCount(1) {

    // Инициализация очереди
    patientQueue = new QQueue<QString>();

    // Создаем основное окно и меню
    QMenuBar* menuBar = new QMenuBar(this);
    QMenu* menu = new QMenu("Меню", this);
    QAction* registerAction = new QAction("Регистрация", this);
    QAction* takeAction = new QAction("Прием", this);
    QAction* queueAction = new QAction("Очередь", this);

    menu->addAction(registerAction);
    menu->addAction(takeAction);
    menu->addAction(queueAction);
    menuBar->addMenu(menu);

    setMenuBar(menuBar);  // Устанавливаем меню в QMainWindow

    // Создаем экраны
    QWidget* registerScreen = new QWidget(this);
    QWidget* takeScreen = new QWidget(this);
    QWidget* queueScreen = new QWidget(this);

    // Экран регистрации
    QVBoxLayout* registerLayout = new QVBoxLayout();
    nameInput = new QLineEdit(this);
    registerLayout->addWidget(new QLabel("Введите имя пациента:"));
    registerLayout->addWidget(nameInput);
    QPushButton* registerButton = new QPushButton("Добавить пациента", this);
    registerLayout->addWidget(registerButton);
    registerScreen->setLayout(registerLayout);
    connect(registerButton, &QPushButton::clicked, this, &PatientQueueApp::registerPatient);

    // Экран приема
    QVBoxLayout* takeLayout = new QVBoxLayout();
    QPushButton* takeButton = new QPushButton("Прием пациента", this);
    takeLayout->addWidget(takeButton);
    takeScreen->setLayout(takeLayout);
    connect(takeButton, &QPushButton::clicked, this, &PatientQueueApp::takePatient);

    // Экран очереди
    QVBoxLayout* queueLayout = new QVBoxLayout();
    queueList = new QListWidget(this);
    queueLayout->addWidget(queueList);
    queueScreen->setLayout(queueLayout);

    // Стек для экранов
    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(registerScreen);
    stackedWidget->addWidget(takeScreen);
    stackedWidget->addWidget(queueScreen);

    // Создаем компоновку для основного окна
    setCentralWidget(stackedWidget);

    // Подключаем действия меню к слотам
    connect(registerAction, &QAction::triggered, this, &PatientQueueApp::switchToRegisterScreen);
    connect(takeAction, &QAction::triggered, this, &PatientQueueApp::switchToTakeScreen);
    connect(queueAction, &QAction::triggered, this, &PatientQueueApp::switchToQueueScreen);
}

void PatientQueueApp::registerPatient() {
    // Получаем имя пациента
    QString name = nameInput->text();
    if (!name.isEmpty()) {
        // Добавляем пациента в очередь с уникальным номером
        QString patient = QString::number(patientCount++) + ". " + name;
        patientQueue->enqueue(patient);
        nameInput->clear();
        showQueue();
    }
}

void PatientQueueApp::takePatient() {
    if (!patientQueue->isEmpty()) {
        // Извлекаем пациента из очереди
        patientQueue->dequeue();
        showQueue();
    }
}

void PatientQueueApp::showQueue() {
    // Очищаем список и добавляем текущих пациентов
    queueList->clear();
    for (const QString& patient : patientQueue->toList()) {
        queueList->addItem(patient);
    }
}

void PatientQueueApp::switchToRegisterScreen() {
    stackedWidget->setCurrentIndex(0); // Переключаем на экран регистрации
}

void PatientQueueApp::switchToTakeScreen() {
    stackedWidget->setCurrentIndex(1); // Переключаем на экран приема
}

void PatientQueueApp::switchToQueueScreen() {
    stackedWidget->setCurrentIndex(2); // Переключаем на экран очереди
}
