/********************************************************************************
** Form generated from reading UI file 'inicio.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIO_H
#define UI_INICIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Inicio
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *Jugar_Button;
    QPushButton *Cargar_Button;

    void setupUi(QWidget *Inicio)
    {
        if (Inicio->objectName().isEmpty())
            Inicio->setObjectName("Inicio");
        Inicio->resize(400, 300);
        gridLayout = new QGridLayout(Inicio);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(Inicio);
        label->setObjectName("label");
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        Jugar_Button = new QPushButton(Inicio);
        Jugar_Button->setObjectName("Jugar_Button");

        verticalLayout->addWidget(Jugar_Button);

        Cargar_Button = new QPushButton(Inicio);
        Cargar_Button->setObjectName("Cargar_Button");

        verticalLayout->addWidget(Cargar_Button);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);


        retranslateUi(Inicio);

        QMetaObject::connectSlotsByName(Inicio);
    } // setupUi

    void retranslateUi(QWidget *Inicio)
    {
        Inicio->setWindowTitle(QCoreApplication::translate("Inicio", "Form", nullptr));
        label->setText(QCoreApplication::translate("Inicio", "TP IGNACIO OLIVO", nullptr));
        Jugar_Button->setText(QCoreApplication::translate("Inicio", "JUGAR", nullptr));
        Cargar_Button->setText(QCoreApplication::translate("Inicio", "CARGAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Inicio: public Ui_Inicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIO_H
