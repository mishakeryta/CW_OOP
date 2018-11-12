#include "MainWindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    setlocale(LC_CTYPE, "ukr");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
