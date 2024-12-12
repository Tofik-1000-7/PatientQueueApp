#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w; // Создаем главное окно
    w.show(); // Показываем главное окно hello

    return a.exec();
}
