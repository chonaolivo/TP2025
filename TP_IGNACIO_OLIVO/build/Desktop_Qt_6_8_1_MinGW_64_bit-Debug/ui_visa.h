/********************************************************************************
** Form generated from reading UI file 'visa.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISA_H
#define UI_VISA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_visa
{
public:
    QGridLayout *gridLayout;
    QPlainTextEdit *VISA_QPlainTextEdit;

    void setupUi(QWidget *visa)
    {
        if (visa->objectName().isEmpty())
            visa->setObjectName("visa");
        visa->resize(400, 300);
        gridLayout = new QGridLayout(visa);
        gridLayout->setObjectName("gridLayout");
        VISA_QPlainTextEdit = new QPlainTextEdit(visa);
        VISA_QPlainTextEdit->setObjectName("VISA_QPlainTextEdit");

        gridLayout->addWidget(VISA_QPlainTextEdit, 0, 0, 1, 1);


        retranslateUi(visa);

        QMetaObject::connectSlotsByName(visa);
    } // setupUi

    void retranslateUi(QWidget *visa)
    {
        visa->setWindowTitle(QCoreApplication::translate("visa", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class visa: public Ui_visa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISA_H
