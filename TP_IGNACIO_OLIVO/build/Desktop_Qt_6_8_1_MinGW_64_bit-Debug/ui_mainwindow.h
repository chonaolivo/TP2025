/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *Papeles;
    QPushButton *Info_button;
    QLabel *Tiempo_Label;
    QListWidget *Planilla_Control;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Aprobado_Button;
    QPushButton *Denegado_Button;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Guardar_Button;
    QPushButton *Cargar_Button;
    QPushButton *Jugar_Button;
    QLabel *label;
    QLabel *nivel_label;
    QLabel *label_2;
    QLabel *fecha_label;
    QLabel *label_3;
    QLabel *personasR_Label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Papeles = new QListWidget(centralwidget);
        Papeles->setObjectName("Papeles");
        Papeles->setGeometry(QRect(10, 10, 301, 241));
        Info_button = new QPushButton(centralwidget);
        Info_button->setObjectName("Info_button");
        Info_button->setGeometry(QRect(280, 260, 31, 24));
        QFont font;
        font.setPointSize(12);
        Info_button->setFont(font);
        Tiempo_Label = new QLabel(centralwidget);
        Tiempo_Label->setObjectName("Tiempo_Label");
        Tiempo_Label->setGeometry(QRect(10, 260, 101, 16));
        Planilla_Control = new QListWidget(centralwidget);
        Planilla_Control->setObjectName("Planilla_Control");
        Planilla_Control->setGeometry(QRect(321, 11, 431, 361));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(319, 401, 431, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Aprobado_Button = new QPushButton(layoutWidget);
        Aprobado_Button->setObjectName("Aprobado_Button");

        horizontalLayout->addWidget(Aprobado_Button);

        Denegado_Button = new QPushButton(layoutWidget);
        Denegado_Button->setObjectName("Denegado_Button");

        horizontalLayout->addWidget(Denegado_Button);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(12, 400, 254, 26));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Guardar_Button = new QPushButton(layoutWidget1);
        Guardar_Button->setObjectName("Guardar_Button");

        horizontalLayout_2->addWidget(Guardar_Button);

        Cargar_Button = new QPushButton(layoutWidget1);
        Cargar_Button->setObjectName("Cargar_Button");

        horizontalLayout_2->addWidget(Cargar_Button);

        Jugar_Button = new QPushButton(layoutWidget1);
        Jugar_Button->setObjectName("Jugar_Button");

        horizontalLayout_2->addWidget(Jugar_Button);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 290, 49, 16));
        nivel_label = new QLabel(centralwidget);
        nivel_label->setObjectName("nivel_label");
        nivel_label->setGeometry(QRect(50, 290, 49, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 320, 49, 16));
        fecha_label = new QLabel(centralwidget);
        fecha_label->setObjectName("fecha_label");
        fecha_label->setGeometry(QRect(50, 320, 61, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 350, 111, 16));
        personasR_Label = new QLabel(centralwidget);
        personasR_Label->setObjectName("personasR_Label");
        personasR_Label->setGeometry(QRect(120, 350, 49, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Info_button->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        Tiempo_Label->setText(QCoreApplication::translate("MainWindow", "Tiempo:", nullptr));
        Aprobado_Button->setText(QCoreApplication::translate("MainWindow", "APROBADO", nullptr));
        Denegado_Button->setText(QCoreApplication::translate("MainWindow", "DENEGADO", nullptr));
        Guardar_Button->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        Cargar_Button->setText(QCoreApplication::translate("MainWindow", "Cargar", nullptr));
        Jugar_Button->setText(QCoreApplication::translate("MainWindow", "Jugar", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Nivel:", nullptr));
        nivel_label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Fecha:", nullptr));
        fecha_label->setText(QCoreApplication::translate("MainWindow", "06/07/2023", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Personas Restantes:", nullptr));
        personasR_Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
