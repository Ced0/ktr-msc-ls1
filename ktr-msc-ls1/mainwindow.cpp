#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->frame_library->hide();

    QHeaderView* header = ui->tableWidget_library->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;

    //Stops server threads
    stop = true;

    for(int i = 0; i < threads.size(); i++)
    {
        threads[i].join();
    }
}

//Create a user profile
void MainWindow::on_pushButton_createProfile_pressed()
{
    if(ui->lineEdit_name->text().isEmpty() || ui->lineEdit_createLogin->text().isEmpty() || ui->lineEdit_createPassword->text().isEmpty())
    {
        ui->label_createProfile->setText("Please fill mandatory fields");

        qDebug() << "Please fill mandatory fields";

    }else{

        ui->label_createProfile->setText("Profile Created");

        QString filename="UsersLogin.txt";
        QFile file( filename );

        if (file.open(QIODevice::ReadWrite | QIODevice::Append))
        {
            QTextStream stream( &file );

            stream << ui->lineEdit_name->text() << endl;
            stream << ui->lineEdit_companyName->text() << endl;
            stream << ui->lineEdit_email->text() << endl;
            stream << ui->lineEdit_phone->text() << endl;
            stream << ui->lineEdit_createLogin->text() << endl;
            stream << ui->lineEdit_createPassword->text() << endl;

            file.close();

            qDebug() << "Profile creer";

        }else{

            qDebug() << "Failed to open file";
        }
    }
}

//Tries to login
void MainWindow::on_pushButton_login_pressed()
{
    if(ui->lineEdit_password->text().isEmpty() || ui->lineEdit_login->text().isEmpty())
    {
        ui->label_login->setText("Please fill mandatory fields");

        qDebug() << "Please fill mandatory fields";

    }else{

        QString filename="UsersLogin.txt";
        QFile file( filename );

        if (file.open(QIODevice::ReadOnly))
        {
            QTextStream stream( &file );
            QStringList lines = stream.readAll().split("\n");

            int i = 0;
            bool loginFound = false;

            while(i+5 < lines.size() && loginFound == false)
            {
                i += 5;

                //Search for the login
                if(lines[i-1] == ui->lineEdit_login->text())
                {
                    //Check password
                    if(lines[i] == ui->lineEdit_password->text())
                    {
                        info = lines[i-5] + "\n" + lines[i-4]  + "\n" + lines[i-3] + "\n" + lines[i-2];

                        //Change interface, load the user file in the table, starts server
                        logIn();

                    }else{

                        ui->label_login->setText("Wrong password");

                        qDebug() << "Wrong password";
                    }

                    loginFound = true;
                }

                i++;
            }

            if(loginFound == false)
            {
                ui->label_login->setText("Login unknown");

                qDebug() << "Login unknown";
            }
        }
    }

}

void MainWindow::on_pushButton_logOut_pressed()
{
    stop = true;//Stops server threads

    ui->frame_library->hide();
    ui->frame_login->show();

    qDebug() << "Log out";
}

//Adds new info to the user file and in the table
void MainWindow::on_pushButton_add_pressed()
{
    if(ui->lineEdit_addEmail->text().isEmpty())
    {
        ui->label_login->setText("Please fill mandatory fields");

        qDebug() << "Please fill mandatory fields";

    }else{

        QString filename = ui->lineEdit_login->text() + ".txt";
        QFile file( filename );

        if (file.open(QIODevice::ReadWrite | QIODevice::Append))
        {
            QTextStream stream( &file );

            stream << ui->lineEdit_addName->text() << endl;
            stream << ui->lineEdit_addCompany->text() << endl;
            stream << ui->lineEdit_addEmail->text() << endl;
            stream << ui->lineEdit_addPhone->text() << endl;

            ui->tableWidget_library->setRowCount(ui->tableWidget_library->rowCount()+1);

            QTableWidgetItem *newItem = new QTableWidgetItem(ui->lineEdit_addName->text());
            ui->tableWidget_library->setItem(ui->tableWidget_library->rowCount()-1, 0, newItem);

            newItem = new QTableWidgetItem(ui->lineEdit_addCompany->text());
            ui->tableWidget_library->setItem(ui->tableWidget_library->rowCount()-1, 1, newItem);

            newItem = new QTableWidgetItem(ui->lineEdit_addEmail->text());
            ui->tableWidget_library->setItem(ui->tableWidget_library->rowCount()-1, 2, newItem);

            newItem = new QTableWidgetItem(ui->lineEdit_addPhone->text());
            ui->tableWidget_library->setItem(ui->tableWidget_library->rowCount()-1, 3, newItem);

            file.close();

            qDebug() << "Added";
        }
    }
}

//Change interface, load the user file in the table, starts server
void MainWindow::logIn()
{
    ui->label_login->setText("Login Successful");

    qDebug() << "Login Successful";

    ui->frame_library->show();
    ui->frame_login->hide();

    ui->label_user->setText("User: " + ui->lineEdit_login->text());

    ui->tableWidget_library->setRowCount(1);

    QString filename=ui->lineEdit_login->text() + ".txt";
    QFile file( filename );

    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream( &file );
        QStringList lines = stream.readAll().split("\n");

        int i = 0;
        int cpt = 0;

        while(lines.size() > (i*4+cpt))
        {
            QTableWidgetItem *newItem = new QTableWidgetItem(lines[i*4+cpt]);
            ui->tableWidget_library->setItem(i, cpt, newItem);

            cpt++;

            if(cpt == 5)
            {
                i++;
                cpt = 0;

                if(lines.size() > (i*4+cpt+1))
                    ui->tableWidget_library->setRowCount(ui->tableWidget_library->rowCount()+1);
            }
        }

        file.close();

        stop = false;
        threads.push_back(std::thread(&MainWindow::listenerThread, this, 1234));

    }else{
        qDebug() << "Failed to open file";
    }
}

//Listens to connecting socket
void MainWindow::listenerThread(unsigned short port)
{
    SOCKET socket_ecoute;//identifiant de la socket d'ecoute du cote serveur
    SOCKADDR_IN information_sur_la_source;
    //pour le thread

    //ouverture de la socket
    socket_ecoute = socket(AF_INET,SOCK_STREAM,0);

    if(socket_ecoute == INVALID_SOCKET) qDebug() << "desole, peux pas creer la socket du a l'erreur : " << WSAGetLastError() << endl;
    else qDebug() << "socket : OK" << endl;

    int tempo = 1;
    int erreur = setsockopt(socket_ecoute, IPPROTO_TCP,TCP_NODELAY,(char*)&tempo, sizeof(tempo));

    if(erreur != 0) qDebug() << "\n desole peux pas configurer cette option du a l'erreur : " << erreur << "->" << WSAGetLastError() <<endl;
    else qDebug() << "setsockopt(): OK" << endl;

    information_sur_la_source.sin_family = AF_INET;
    information_sur_la_source.sin_addr.s_addr = INADDR_ANY;//ecoute sur toutes les IP locales
    information_sur_la_source.sin_port =htons(port);//ecoute sur le port 1234
    erreur = bind(socket_ecoute, (struct sockaddr*)&information_sur_la_source, sizeof(information_sur_la_source));

    if(erreur != 0)
    {
        qDebug() << "\nDeolse, je ne peux pas ecouter sur ce port : " << erreur << WSAGetLastError() << endl;
        exit(1);
    }else{
        qDebug() << "bind(): OK" << endl;
    }


    unsigned long nonBlock = 1;

    #ifdef __linux__
    if(fcntl(socket_ecoute, F_SETFL,O_NONBLOCK))
    {
        qDebug() << "fcntl() failed with error : " << WSAGetLastError() << endl;
    }else{
        qDebug() << "fcntl()  success !" << endl;
    }
    #elif _WIN32
    if(ioctlsocket(socket_ecoute, FIONBIO, &nonBlock))
    {
        qDebug() << "ioctlsocket() failed with error : " << WSAGetLastError() << endl;
    }else{
        qDebug() << "ioctlsocket()  success !" << endl;
    }
    #endif


    //ecoute sur le socket d'ecoute
    do{
        erreur = listen (socket_ecoute, 10);
    }while(erreur != 0);

    qDebug()  << "listen(): OK" << endl;
    SOCKET socket_travail;//identifiant de la nouvelle socket client...cote serveur
//acceptation de la demande d'ouverture de session
    qDebug() << "\nAttente de la reception de damande d'ouverture de nouvelle session TCP(SYN):\n";


    tempo = sizeof(information_sur_la_source);//passer par une variable afin d'utiliser un pointeur

    while(stop == false)
    {
        socket_travail = accept(socket_ecoute,(struct sockaddr*)&information_sur_la_source, (socklen_t*)&tempo);
        if(socket_travail == INVALID_SOCKET){
            //qDebug() << "\nDesole, je peux pas accepter la session TCP du a l'erreur : " << WSAGetLastError() << endl;
        }else{
            qDebug() << "accpet() : OK" << endl;
            threads.push_back(std::thread(&MainWindow::clientThread, this, socket_travail));
        }
    }

    shutdown(socket_ecoute, 2);
    closesocket(socket_ecoute);

}

//Recieves and sends infos
void MainWindow::clientThread(SOCKET current_client)
{
    char buf[120] = {0};
    //buffer pour les données a envoyer
    char sendData[120] = {0};
    int res;

    //Reçois les infos du client
    memset(buf, 0, 120);
    res = recv(current_client, buf, sizeof(buf), 0);//reception de la commanded'un client

    QStringList lines = QString(buf).split("\n");

    QString filename = ui->lineEdit_login->text() + ".txt";

    add(filename, lines);


    //Envoie de nos information
    strcpy(sendData, info.toStdString().c_str());
    send(current_client, sendData, sizeof(sendData), 0);

    shutdown(current_client, 2);
    closesocket(current_client);
}

//Adds new info to the user file and in the table
void MainWindow::add(QString filename, QStringList lines)
{
    QFile file( filename );

    if (file.open(QIODevice::ReadWrite | QIODevice::Append))
    {
        QTextStream stream( &file );

        stream << lines[0] << endl;
        stream << lines[1] << endl;
        stream << lines[2] << endl;
        stream << lines[3] << endl;

        ui->tableWidget_library->setRowCount(ui->tableWidget_library->rowCount()+1);

        QTableWidgetItem *newItem = new QTableWidgetItem(lines[0]);
        ui->tableWidget_library->setItem(ui->tableWidget_library->rowCount()-1, 0, newItem);

        newItem = new QTableWidgetItem(lines[1]);
        ui->tableWidget_library->setItem(ui->tableWidget_library->rowCount()-1, 1, newItem);

        newItem = new QTableWidgetItem(lines[2]);
        ui->tableWidget_library->setItem(ui->tableWidget_library->rowCount()-1, 2, newItem);

        newItem = new QTableWidgetItem(lines[3]);
        ui->tableWidget_library->setItem(ui->tableWidget_library->rowCount()-1, 3, newItem);

        file.close();

        qDebug() << "Added";
    }
}

//Create a client and exchange the infos
void MainWindow::on_pushButton_exchange_pressed()
{
    Client client(ui->lineEdit_ip->text().toStdString().c_str(),
                  ui->lineEdit_port->text().toUShort());

    char buff[120];


    strcpy(buff, info.toStdString().c_str());
    client.envoie(buff, info.size());

    memset(buff, 0, 120);
    client.reception(buff, 120);

    QStringList lines = QString(buff).split("\n");

    QString filename = ui->lineEdit_login->text() + ".txt";

    add(filename, lines);
}
