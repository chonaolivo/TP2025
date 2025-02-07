/********************************************************************************
** Form generated from reading UI file 'ticket_de_entrada.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICKET_DE_ENTRADA_H
#define UI_TICKET_DE_ENTRADA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ticket_de_entrada
{
public:
    QGridLayout *gridLayout;
    QPlainTextEdit *TICKET_QPlainTextEdit;

    void setupUi(QWidget *ticket_de_entrada)
    {
        if (ticket_de_entrada->objectName().isEmpty())
            ticket_de_entrada->setObjectName("ticket_de_entrada");
        ticket_de_entrada->resize(400, 300);
        gridLayout = new QGridLayout(ticket_de_entrada);
        gridLayout->setObjectName("gridLayout");
        TICKET_QPlainTextEdit = new QPlainTextEdit(ticket_de_entrada);
        TICKET_QPlainTextEdit->setObjectName("TICKET_QPlainTextEdit");

        gridLayout->addWidget(TICKET_QPlainTextEdit, 0, 0, 1, 1);


        retranslateUi(ticket_de_entrada);

        QMetaObject::connectSlotsByName(ticket_de_entrada);
    } // setupUi

    void retranslateUi(QWidget *ticket_de_entrada)
    {
        ticket_de_entrada->setWindowTitle(QCoreApplication::translate("ticket_de_entrada", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ticket_de_entrada: public Ui_ticket_de_entrada {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKET_DE_ENTRADA_H
