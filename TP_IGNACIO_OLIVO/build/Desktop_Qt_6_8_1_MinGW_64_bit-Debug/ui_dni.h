/********************************************************************************
** Form generated from reading UI file 'dni.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DNI_H
#define UI_DNI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DNI
{
public:
    QGridLayout *gridLayout;
    QPlainTextEdit *DNI_QPlainTextEdit;

    void setupUi(QWidget *DNI)
    {
        if (DNI->objectName().isEmpty())
            DNI->setObjectName("DNI");
        DNI->resize(400, 300);
        gridLayout = new QGridLayout(DNI);
        gridLayout->setObjectName("gridLayout");
        DNI_QPlainTextEdit = new QPlainTextEdit(DNI);
        DNI_QPlainTextEdit->setObjectName("DNI_QPlainTextEdit");

        gridLayout->addWidget(DNI_QPlainTextEdit, 0, 0, 1, 1);


        retranslateUi(DNI);

        QMetaObject::connectSlotsByName(DNI);
    } // setupUi

    void retranslateUi(QWidget *DNI)
    {
        DNI->setWindowTitle(QCoreApplication::translate("DNI", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DNI: public Ui_DNI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DNI_H
