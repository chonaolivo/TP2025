/********************************************************************************
** Form generated from reading UI file 'trabajo.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRABAJO_H
#define UI_TRABAJO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_trabajo
{
public:
    QGridLayout *gridLayout;
    QPlainTextEdit *TRABAJO_QPlainTextEdit;

    void setupUi(QWidget *trabajo)
    {
        if (trabajo->objectName().isEmpty())
            trabajo->setObjectName("trabajo");
        trabajo->resize(400, 300);
        gridLayout = new QGridLayout(trabajo);
        gridLayout->setObjectName("gridLayout");
        TRABAJO_QPlainTextEdit = new QPlainTextEdit(trabajo);
        TRABAJO_QPlainTextEdit->setObjectName("TRABAJO_QPlainTextEdit");

        gridLayout->addWidget(TRABAJO_QPlainTextEdit, 0, 0, 1, 1);


        retranslateUi(trabajo);

        QMetaObject::connectSlotsByName(trabajo);
    } // setupUi

    void retranslateUi(QWidget *trabajo)
    {
        trabajo->setWindowTitle(QCoreApplication::translate("trabajo", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class trabajo: public Ui_trabajo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRABAJO_H
