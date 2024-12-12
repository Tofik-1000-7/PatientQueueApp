#include "registrationwindow.h"

RegistrationWindow::RegistrationWindow(QQueue<Patient> *queue, QWidget *parent)
    : QWidget(parent), queue(queue), currentMaxId(0)
{
    setWindowTitle("Регистрация пациента");

    this->resize(300, 100);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel("Введите имя пациента", this);
    patientNameInput = new QLineEdit(this);
    QPushButton *addPatientButton = new QPushButton("Добавить пациента", this);

    layout->addWidget(label);
    layout->addWidget(patientNameInput);
    layout->addWidget(addPatientButton);

    connect(addPatientButton, &QPushButton::clicked, this, &RegistrationWindow::addPatient);
}

void RegistrationWindow::addPatient()
{
    QString name = patientNameInput->text();
    if (!name.isEmpty()) {
        // Если очередь пуста, сбрасываем ID в 0, иначе увеличиваем currentMaxId
        if (queue->isEmpty()) {
            currentMaxId = 0;  // Если очередь пуста, начинаем с ID = 0
        }

        currentMaxId++;  // Если не пуста, увеличиваем ID на 1

        // Создаем нового пациента с новым ID
        Patient newPatient(name, currentMaxId);
        queue->enqueue(newPatient);
        patientNameInput->clear();

        // Сигнализируем о том, что очередь обновилась
        emit queueUpdated();
    }
}
