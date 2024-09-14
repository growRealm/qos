/********************************************************************************
** Form generated from reading UI file 'uicreatebucketdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UICREATEBUCKETDIALOG_H
#define UI_UICREATEBUCKETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "src/fend/uicom/uipushbutton.h"

QT_BEGIN_NAMESPACE

class Ui_UiCreateBucketDialog
{
public:
    QFormLayout *formLayout;
    QLabel *labelName;
    QLineEdit *lineName;
    QLabel *labelLocation;
    QLineEdit *lineLocation;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    UiPushButton *btnOk;
    UiPushButton *btnCancel;

    void setupUi(QWidget *UiCreateBucketDialog)
    {
        if (UiCreateBucketDialog->objectName().isEmpty())
            UiCreateBucketDialog->setObjectName("UiCreateBucketDialog");
        UiCreateBucketDialog->resize(306, 79);
        formLayout = new QFormLayout(UiCreateBucketDialog);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelName = new QLabel(UiCreateBucketDialog);
        labelName->setObjectName("labelName");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelName);

        lineName = new QLineEdit(UiCreateBucketDialog);
        lineName->setObjectName("lineName");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineName);

        labelLocation = new QLabel(UiCreateBucketDialog);
        labelLocation->setObjectName("labelLocation");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelLocation);

        lineLocation = new QLineEdit(UiCreateBucketDialog);
        lineLocation->setObjectName("lineLocation");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineLocation);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new UiPushButton(UiCreateBucketDialog);
        btnOk->setObjectName("btnOk");

        horizontalLayout->addWidget(btnOk);

        btnCancel = new UiPushButton(UiCreateBucketDialog);
        btnCancel->setObjectName("btnCancel");

        horizontalLayout->addWidget(btnCancel);


        formLayout->setLayout(2, QFormLayout::SpanningRole, horizontalLayout);


        retranslateUi(UiCreateBucketDialog);

        QMetaObject::connectSlotsByName(UiCreateBucketDialog);
    } // setupUi

    void retranslateUi(QWidget *UiCreateBucketDialog)
    {
        UiCreateBucketDialog->setWindowTitle(QCoreApplication::translate("UiCreateBucketDialog", "Form", nullptr));
        labelName->setText(QCoreApplication::translate("UiCreateBucketDialog", "\346\241\266\345\220\215\347\247\260\357\274\232", nullptr));
        lineName->setPlaceholderText(QCoreApplication::translate("UiCreateBucketDialog", "\345\220\215\347\247\260-appid", nullptr));
        labelLocation->setText(QCoreApplication::translate("UiCreateBucketDialog", "\346\241\266\344\275\215\347\275\256\357\274\232", nullptr));
        lineLocation->setPlaceholderText(QCoreApplication::translate("UiCreateBucketDialog", "ap-shanghai", nullptr));
        btnOk->setText(QCoreApplication::translate("UiCreateBucketDialog", "\347\241\256\345\256\232", nullptr));
        btnCancel->setText(QCoreApplication::translate("UiCreateBucketDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UiCreateBucketDialog: public Ui_UiCreateBucketDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UICREATEBUCKETDIALOG_H
