#include "mainwindow.h"
#include "wsainit.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    #ifdef _WIN32
    WSAInit wsa;
    #endif

    MainWindow w;
    w.show();

    return a.exec();
}
