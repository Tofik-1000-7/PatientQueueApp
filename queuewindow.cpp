#include "queuewindow.h"

QueueWindow::QueueWindow(QQueue<Patient> *queue, QWidget *parent)
    : QWidget(parent), queue(queue)
{
    setWindowTitle("Очередь пациентов");
    this->resize(300, 500);
    QVBoxLayout *layout = new QVBoxLayout(this);

    listWidget = new QListWidget(this);
    layout->addWidget(listWidget);

    // Изначально заполняем список
    updateQueueList();
}

void QueueWindow::updateQueueList()
{
    listWidget->clear();  // Очищаем текущий список
    for (const Patient &patient : *queue) {
        listWidget->addItem(QString::number(patient.getNumber()) + ". " + patient.getName());
    }
}
