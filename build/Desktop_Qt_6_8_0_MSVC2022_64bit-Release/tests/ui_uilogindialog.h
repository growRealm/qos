/********************************************************************************
** Form generated from reading UI file 'uilogindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UILOGINDIALOG_H
#define UI_UILOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "src/fend/uicom/uicomboline.h"
#include "src/fend/uicom/uipushbutton.h"

QT_BEGIN_NAMESPACE

class Ui_UiLoginDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelLoginName;
    UiComboLine *lineLoginName;
    QSpacerItem *verticalSpacer;
    QLabel *labelSecretId;
    QLineEdit *lineSecretId;
    QSpacerItem *verticalSpacer_3;
    QLabel *labelSecretKey;
    QLineEdit *lineSecretKey;
    QSpacerItem *verticalSpacer_4;
    QLabel *labelRemark;
    QLineEdit *lineRemark;
    QCheckBox *checkSaveSection;
    UiPushButton *btnLogin;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QWidget *UiLoginDialog)
    {
        if (UiLoginDialog->objectName().isEmpty())
            UiLoginDialog->setObjectName("UiLoginDialog");
        UiLoginDialog->resize(375, 429);
        UiLoginDialog->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(UiLoginDialog);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(30, -1, 30, 20);
        labelLoginName = new QLabel(UiLoginDialog);
        labelLoginName->setObjectName("labelLoginName");

        verticalLayout->addWidget(labelLoginName);

        lineLoginName = new UiComboLine(UiLoginDialog);
        lineLoginName->setObjectName("lineLoginName");

        verticalLayout->addWidget(lineLoginName);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        labelSecretId = new QLabel(UiLoginDialog);
        labelSecretId->setObjectName("labelSecretId");

        verticalLayout->addWidget(labelSecretId);

        lineSecretId = new QLineEdit(UiLoginDialog);
        lineSecretId->setObjectName("lineSecretId");
        lineSecretId->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(lineSecretId);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        labelSecretKey = new QLabel(UiLoginDialog);
        labelSecretKey->setObjectName("labelSecretKey");

        verticalLayout->addWidget(labelSecretKey);

        lineSecretKey = new QLineEdit(UiLoginDialog);
        lineSecretKey->setObjectName("lineSecretKey");
        lineSecretKey->setMinimumSize(QSize(0, 0));
        lineSecretKey->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineSecretKey);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        labelRemark = new QLabel(UiLoginDialog);
        labelRemark->setObjectName("labelRemark");

        verticalLayout->addWidget(labelRemark);

        lineRemark = new QLineEdit(UiLoginDialog);
        lineRemark->setObjectName("lineRemark");
        lineRemark->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(lineRemark);

        checkSaveSection = new QCheckBox(UiLoginDialog);
        checkSaveSection->setObjectName("checkSaveSection");

        verticalLayout->addWidget(checkSaveSection);

        btnLogin = new UiPushButton(UiLoginDialog);
        btnLogin->setObjectName("btnLogin");
        btnLogin->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(btnLogin);

        verticalSpacer_6 = new QSpacerItem(20, 22, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

#if QT_CONFIG(shortcut)
        labelSecretId->setBuddy(lineSecretId);
        labelSecretKey->setBuddy(lineSecretKey);
#endif // QT_CONFIG(shortcut)

        retranslateUi(UiLoginDialog);

        QMetaObject::connectSlotsByName(UiLoginDialog);
    } // setupUi

    void retranslateUi(QWidget *UiLoginDialog)
    {
        UiLoginDialog->setWindowTitle(QCoreApplication::translate("UiLoginDialog", "\347\231\273\345\275\225", nullptr));
        labelLoginName->setText(QCoreApplication::translate("UiLoginDialog", "\347\231\273\345\275\225\345\220\215", nullptr));
        labelSecretId->setText(QCoreApplication::translate("UiLoginDialog", "Sectet&Id", nullptr));
        labelSecretKey->setText(QCoreApplication::translate("UiLoginDialog", "Sectet&Key", nullptr));
        labelRemark->setText(QCoreApplication::translate("UiLoginDialog", "\345\244\207\346\263\250", nullptr));
        checkSaveSection->setText(QCoreApplication::translate("UiLoginDialog", "\350\256\260\344\275\217\344\274\232\350\257\235", nullptr));
        btnLogin->setText(QCoreApplication::translate("UiLoginDialog", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UiLoginDialog: public Ui_UiLoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UILOGINDIALOG_H
