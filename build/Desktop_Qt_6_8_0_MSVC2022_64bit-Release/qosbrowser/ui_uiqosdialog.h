/********************************************************************************
** Form generated from reading UI file 'uiqosdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIQOSDIALOG_H
#define UI_UIQOSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UiQosDialog
{
public:

    void setupUi(QWidget *UiQosDialog)
    {
        if (UiQosDialog->objectName().isEmpty())
            UiQosDialog->setObjectName("UiQosDialog");
        UiQosDialog->resize(45, 17);

        retranslateUi(UiQosDialog);

        QMetaObject::connectSlotsByName(UiQosDialog);
    } // setupUi

    void retranslateUi(QWidget *UiQosDialog)
    {
        UiQosDialog->setWindowTitle(QCoreApplication::translate("UiQosDialog", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UiQosDialog: public Ui_UiQosDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIQOSDIALOG_H
