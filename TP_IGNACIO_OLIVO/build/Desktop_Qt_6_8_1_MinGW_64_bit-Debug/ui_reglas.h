/********************************************************************************
** Form generated from reading UI file 'reglas.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGLAS_H
#define UI_REGLAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Reglas
{
public:
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_6;
    QGridLayout *gridLayout;
    QPushButton *DNI_Button;
    QPushButton *TICKET_Button;
    QPushButton *TRABAJO_Button;
    QPushButton *VISA_Button;

    void setupUi(QWidget *Reglas)
    {
        if (Reglas->objectName().isEmpty())
            Reglas->setObjectName("Reglas");
        Reglas->resize(417, 300);
        widget = new QWidget(Reglas);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(5, 11, 397, 252));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");

        verticalLayout->addWidget(label_7);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");

        verticalLayout->addWidget(label_6);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        DNI_Button = new QPushButton(widget);
        DNI_Button->setObjectName("DNI_Button");

        gridLayout->addWidget(DNI_Button, 0, 0, 1, 1);

        TICKET_Button = new QPushButton(widget);
        TICKET_Button->setObjectName("TICKET_Button");

        gridLayout->addWidget(TICKET_Button, 1, 0, 1, 1);

        TRABAJO_Button = new QPushButton(widget);
        TRABAJO_Button->setObjectName("TRABAJO_Button");

        gridLayout->addWidget(TRABAJO_Button, 2, 0, 1, 1);

        VISA_Button = new QPushButton(widget);
        VISA_Button->setObjectName("VISA_Button");

        gridLayout->addWidget(VISA_Button, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);


        retranslateUi(Reglas);

        QMetaObject::connectSlotsByName(Reglas);
    } // setupUi

    void retranslateUi(QWidget *Reglas)
    {
        Reglas->setWindowTitle(QCoreApplication::translate("Reglas", "Form", nullptr));
        label_7->setText(QCoreApplication::translate("Reglas", "REGLAS:", nullptr));
        label_2->setText(QCoreApplication::translate("Reglas", "- Si se cometen 3 fallos, PIERDES.", nullptr));
        label_3->setText(QCoreApplication::translate("Reglas", "- Si se completa toda la fila se pasa de nivel.", nullptr));
        label_5->setText(QCoreApplication::translate("Reglas", "- Si el tiempo finaliza, se sumaran las personas sobrantes al d\303\255a siguiente", nullptr));
        label_4->setText(QCoreApplication::translate("Reglas", "- Deben quedar menos de 5 personas para pasar de nivel", nullptr));
        label_6->setText(QCoreApplication::translate("Reglas", "- Existen 3 niveles de dificultad, al superar un nivel se aumenta la dificultad", nullptr));
        DNI_Button->setText(QCoreApplication::translate("Reglas", "DNI", nullptr));
        TICKET_Button->setText(QCoreApplication::translate("Reglas", "TICKET DE ENTRADA", nullptr));
        TRABAJO_Button->setText(QCoreApplication::translate("Reglas", "PERMISO DE TRABAJO", nullptr));
        VISA_Button->setText(QCoreApplication::translate("Reglas", "VISA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reglas: public Ui_Reglas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGLAS_H
