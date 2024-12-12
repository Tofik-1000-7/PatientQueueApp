#ifndef PATIENT_H
#define PATIENT_H

#include <QString>

class Patient
{
public:
    Patient(const QString &name, int number)
        : name(name), number(number) {}

    QString getName() const { return name; }
    int getNumber() const { return number; }

private:
    QString name;
    int number;
};

#endif // PATIENT_H
