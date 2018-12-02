#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    a.setWindowIcon(QIcon(":/resources/img/icon.ico"));
    w.showFullScreen();
    return a.exec();
}
