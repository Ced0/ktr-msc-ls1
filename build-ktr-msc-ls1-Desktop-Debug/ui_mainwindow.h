/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame_login;
    QFrame *line;
    QPushButton *pushButton_createProfile;
    QLabel *label_2;
    QLineEdit *lineEdit_phone;
    QLabel *label_4;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_createProfile;
    QLabel *label_7;
    QLineEdit *lineEdit_email;
    QLabel *label_login;
    QLineEdit *lineEdit_companyName;
    QLabel *label_3;
    QLineEdit *lineEdit_createLogin;
    QPushButton *pushButton_login;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_createPassword;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_8;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_login;
    QFrame *frame_library;
    QLabel *label_user;
    QPushButton *pushButton_logOut;
    QLabel *label_User_2;
    QLabel *label_User_3;
    QLabel *label_User_4;
    QLabel *label_User_5;
    QLineEdit *lineEdit_addName;
    QLineEdit *lineEdit_addCompany;
    QLineEdit *lineEdit_addEmail;
    QLineEdit *lineEdit_addPhone;
    QPushButton *pushButton_add;
    QLabel *label_add;
    QPushButton *pushButton_exchange;
    QLineEdit *lineEdit_ip;
    QLineEdit *lineEdit_port;
    QLabel *label_add_2;
    QLabel *label_add_3;
    QTableWidget *tableWidget_library;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1019, 676);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        frame_login = new QFrame(centralwidget);
        frame_login->setObjectName(QStringLiteral("frame_login"));
        frame_login->setGeometry(QRect(10, 10, 781, 591));
        frame_login->setFrameShape(QFrame::StyledPanel);
        frame_login->setFrameShadow(QFrame::Raised);
        line = new QFrame(frame_login);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(40, 170, 661, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton_createProfile = new QPushButton(frame_login);
        pushButton_createProfile->setObjectName(QStringLiteral("pushButton_createProfile"));
        pushButton_createProfile->setGeometry(QRect(40, 360, 131, 41));
        QFont font;
        font.setPointSize(12);
        pushButton_createProfile->setFont(font);
        label_2 = new QLabel(frame_login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(210, 200, 111, 20));
        label_2->setFont(font);
        lineEdit_phone = new QLineEdit(frame_login);
        lineEdit_phone->setObjectName(QStringLiteral("lineEdit_phone"));
        lineEdit_phone->setGeometry(QRect(550, 230, 141, 20));
        label_4 = new QLabel(frame_login);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(550, 200, 111, 20));
        label_4->setFont(font);
        label_9 = new QLabel(frame_login);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(220, 20, 91, 20));
        label_9->setFont(font);
        label_6 = new QLabel(frame_login);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 260, 91, 20));
        label_6->setFont(font);
        label_createProfile = new QLabel(frame_login);
        label_createProfile->setObjectName(QStringLiteral("label_createProfile"));
        label_createProfile->setGeometry(QRect(40, 410, 401, 31));
        label_createProfile->setFont(font);
        label_7 = new QLabel(frame_login);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(210, 260, 91, 20));
        label_7->setFont(font);
        lineEdit_email = new QLineEdit(frame_login);
        lineEdit_email->setObjectName(QStringLiteral("lineEdit_email"));
        lineEdit_email->setGeometry(QRect(380, 230, 141, 20));
        label_login = new QLabel(frame_login);
        label_login->setObjectName(QStringLiteral("label_login"));
        label_login->setGeometry(QRect(40, 130, 401, 31));
        label_login->setFont(font);
        lineEdit_companyName = new QLineEdit(frame_login);
        lineEdit_companyName->setObjectName(QStringLiteral("lineEdit_companyName"));
        lineEdit_companyName->setGeometry(QRect(210, 230, 141, 20));
        label_3 = new QLabel(frame_login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(380, 200, 111, 20));
        label_3->setFont(font);
        lineEdit_createLogin = new QLineEdit(frame_login);
        lineEdit_createLogin->setObjectName(QStringLiteral("lineEdit_createLogin"));
        lineEdit_createLogin->setGeometry(QRect(40, 290, 141, 20));
        pushButton_login = new QPushButton(frame_login);
        pushButton_login->setObjectName(QStringLiteral("pushButton_login"));
        pushButton_login->setGeometry(QRect(40, 90, 91, 31));
        pushButton_login->setFont(font);
        lineEdit_name = new QLineEdit(frame_login);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(40, 230, 141, 20));
        lineEdit_createPassword = new QLineEdit(frame_login);
        lineEdit_createPassword->setObjectName(QStringLiteral("lineEdit_createPassword"));
        lineEdit_createPassword->setGeometry(QRect(210, 290, 141, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("MS UI Gothic"));
        lineEdit_createPassword->setFont(font1);
        lineEdit_createPassword->setEchoMode(QLineEdit::Password);
        label = new QLabel(frame_login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 200, 91, 20));
        label->setFont(font);
        label_5 = new QLabel(frame_login);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 330, 111, 21));
        QFont font2;
        font2.setPointSize(8);
        label_5->setFont(font2);
        label_8 = new QLabel(frame_login);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 20, 91, 20));
        label_8->setFont(font);
        lineEdit_password = new QLineEdit(frame_login);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(220, 50, 141, 20));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        lineEdit_login = new QLineEdit(frame_login);
        lineEdit_login->setObjectName(QStringLiteral("lineEdit_login"));
        lineEdit_login->setGeometry(QRect(40, 50, 141, 20));
        frame_library = new QFrame(centralwidget);
        frame_library->setObjectName(QStringLiteral("frame_library"));
        frame_library->setGeometry(QRect(10, 10, 981, 601));
        frame_library->setFrameShape(QFrame::StyledPanel);
        frame_library->setFrameShadow(QFrame::Raised);
        label_user = new QLabel(frame_library);
        label_user->setObjectName(QStringLiteral("label_user"));
        label_user->setGeometry(QRect(20, 20, 201, 31));
        label_user->setFont(font);
        pushButton_logOut = new QPushButton(frame_library);
        pushButton_logOut->setObjectName(QStringLiteral("pushButton_logOut"));
        pushButton_logOut->setGeometry(QRect(844, 532, 121, 41));
        pushButton_logOut->setFont(font);
        label_User_2 = new QLabel(frame_library);
        label_User_2->setObjectName(QStringLiteral("label_User_2"));
        label_User_2->setGeometry(QRect(20, 70, 61, 31));
        label_User_2->setFont(font);
        label_User_3 = new QLabel(frame_library);
        label_User_3->setObjectName(QStringLiteral("label_User_3"));
        label_User_3->setGeometry(QRect(250, 70, 201, 31));
        label_User_3->setFont(font);
        label_User_4 = new QLabel(frame_library);
        label_User_4->setObjectName(QStringLiteral("label_User_4"));
        label_User_4->setGeometry(QRect(480, 70, 201, 31));
        label_User_4->setFont(font);
        label_User_5 = new QLabel(frame_library);
        label_User_5->setObjectName(QStringLiteral("label_User_5"));
        label_User_5->setGeometry(QRect(710, 70, 201, 31));
        label_User_5->setFont(font);
        lineEdit_addName = new QLineEdit(frame_library);
        lineEdit_addName->setObjectName(QStringLiteral("lineEdit_addName"));
        lineEdit_addName->setGeometry(QRect(20, 100, 201, 20));
        lineEdit_addCompany = new QLineEdit(frame_library);
        lineEdit_addCompany->setObjectName(QStringLiteral("lineEdit_addCompany"));
        lineEdit_addCompany->setGeometry(QRect(250, 100, 201, 20));
        lineEdit_addEmail = new QLineEdit(frame_library);
        lineEdit_addEmail->setObjectName(QStringLiteral("lineEdit_addEmail"));
        lineEdit_addEmail->setGeometry(QRect(480, 100, 201, 20));
        lineEdit_addPhone = new QLineEdit(frame_library);
        lineEdit_addPhone->setObjectName(QStringLiteral("lineEdit_addPhone"));
        lineEdit_addPhone->setGeometry(QRect(710, 100, 201, 20));
        pushButton_add = new QPushButton(frame_library);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));
        pushButton_add->setGeometry(QRect(20, 140, 91, 31));
        pushButton_add->setFont(font);
        label_add = new QLabel(frame_library);
        label_add->setObjectName(QStringLiteral("label_add"));
        label_add->setGeometry(QRect(20, 180, 441, 31));
        label_add->setFont(font2);
        pushButton_exchange = new QPushButton(frame_library);
        pushButton_exchange->setObjectName(QStringLiteral("pushButton_exchange"));
        pushButton_exchange->setGeometry(QRect(490, 540, 141, 31));
        pushButton_exchange->setFont(font);
        lineEdit_ip = new QLineEdit(frame_library);
        lineEdit_ip->setObjectName(QStringLiteral("lineEdit_ip"));
        lineEdit_ip->setGeometry(QRect(40, 540, 201, 20));
        lineEdit_port = new QLineEdit(frame_library);
        lineEdit_port->setObjectName(QStringLiteral("lineEdit_port"));
        lineEdit_port->setGeometry(QRect(270, 540, 201, 20));
        label_add_2 = new QLabel(frame_library);
        label_add_2->setObjectName(QStringLiteral("label_add_2"));
        label_add_2->setGeometry(QRect(40, 570, 591, 21));
        label_add_2->setFont(font2);
        label_add_3 = new QLabel(frame_library);
        label_add_3->setObjectName(QStringLiteral("label_add_3"));
        label_add_3->setGeometry(QRect(130, 140, 441, 31));
        label_add_3->setFont(font2);
        tableWidget_library = new QTableWidget(frame_library);
        if (tableWidget_library->columnCount() < 4)
            tableWidget_library->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_library->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_library->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_library->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_library->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget_library->setObjectName(QStringLiteral("tableWidget_library"));
        tableWidget_library->setGeometry(QRect(20, 230, 941, 291));
        tableWidget_library->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_library->setAlternatingRowColors(true);
        tableWidget_library->setRowCount(0);
        tableWidget_library->setColumnCount(4);
        tableWidget_library->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_library->verticalHeader()->setCascadingSectionResizes(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1019, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_createProfile->setText(QApplication::translate("MainWindow", "Create profile", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Company name", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Phone number", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Password", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Login*", nullptr));
        label_createProfile->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "Password*", nullptr));
        label_login->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Email", nullptr));
        pushButton_login->setText(QApplication::translate("MainWindow", "Login", nullptr));
        label->setText(QApplication::translate("MainWindow", "Name*", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "*Mandatory fields", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Login", nullptr));
        label_user->setText(QApplication::translate("MainWindow", "User:", nullptr));
        pushButton_logOut->setText(QApplication::translate("MainWindow", "Log out", nullptr));
        label_User_2->setText(QApplication::translate("MainWindow", "Name", nullptr));
        label_User_3->setText(QApplication::translate("MainWindow", "Company name", nullptr));
        label_User_4->setText(QApplication::translate("MainWindow", "Email*", nullptr));
        label_User_5->setText(QApplication::translate("MainWindow", "Phone number", nullptr));
        pushButton_add->setText(QApplication::translate("MainWindow", "Add", nullptr));
        label_add->setText(QString());
        pushButton_exchange->setText(QApplication::translate("MainWindow", "Exchange card", nullptr));
        lineEdit_ip->setText(QApplication::translate("MainWindow", "127.0.0.1", nullptr));
        lineEdit_port->setText(QApplication::translate("MainWindow", "1234", nullptr));
        label_add_2->setText(QString());
        label_add_3->setText(QApplication::translate("MainWindow", "*Mandatory field", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_library->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_library->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Company name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_library->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_library->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Phone number", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
