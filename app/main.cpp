#include "MainWindow.hpp"
#include <QApplication>
#include <exception>
#include <QDebug>

int main(int argc, char *argv[])
{
    int status;

    try {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        status = a.exec();
    } catch (std::exception &e) {
        qDebug() << e.what();
    }

    return status;
}
