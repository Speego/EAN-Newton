#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication aPP(argc, argv);
    MainWindow window;
    window.show();
    return aPP.exec();
}
