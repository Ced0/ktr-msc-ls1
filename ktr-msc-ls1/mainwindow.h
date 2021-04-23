#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "client.h"

#include <QObject>
#include <fstream>
#include <vector>
#include <thread>

#ifdef __linux__
    #include <unistd.h>
    #include <sys/socket.h>
    #include <sys/types.h>
    #include <sys/un.h>
    #include <arpa/inet.h>
    #include <errno.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <netinet/ip.h>
    #include <sys/ioctl.h>
    #include <netinet/tcp.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
       #include <sys/socket.h>

    #define SOCKET int
    #define SOCKADDR_IN sockaddr_in
    #define INVALID_SOCKET -1
    #define WSAGetLastError() errno
    #define closesocket(s) close(s)

#elif _WIN32
    #include <windows.h>
    #include <winsock2.h>
    #include <ws2tcpip.h>
#endif

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void logIn();

    void listenerThread(unsigned short port);

    void clientThread(SOCKET current_client);

    void add(QString filename, QStringList lines);


private slots:
    void on_pushButton_createProfile_pressed();

    void on_pushButton_login_pressed();

    void on_pushButton_logOut_pressed();

    void on_pushButton_add_pressed();

    void on_pushButton_exchange_pressed();

private:
    Ui::MainWindow *ui;

    std::vector<unsigned long long> adresse;
    vector<std::thread> threads;

    bool stop = false;

    QString info;
};
#endif // MAINWINDOW_H
