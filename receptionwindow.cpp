#include "receptionwindow.h"

ReceptionWindow::ReceptionWindow(QQueue<Patient> *queue, QWidget *parent)
    : QWidget(parent), queue(queue)
{
    setWindowTitle("Прием пациента");
    this->resize(300, 100);
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel("Прием пациента", this);
    QPushButton *receivePatientButton = new QPushButton("Принять пациента", this);
    statusLabel = new QLabel("Ожидает приема", this);

    layout->addWidget(label);
    layout->addWidget(receivePatientButton);
    layout->addWidget(statusLabel);

    connect(receivePatientButton, &QPushButton::clicked, this, &ReceptionWindow::receivePatient);

}

void ReceptionWindow::receivePatient()
{
    if (!queue->isEmpty()) {
        Patient patient = queue->dequeue();
        statusLabel->setText("Пациент " + patient.getName() + " принят на прием.");

        // Сигнализируем о том, что очередь обновилась
        emit queueUpdated();
    } else {
        statusLabel->setText("Очередь пуста.");
    }
}
