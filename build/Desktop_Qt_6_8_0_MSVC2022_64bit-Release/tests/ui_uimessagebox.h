/********************************************************************************
** Form generated from reading UI file 'uimessagebox.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIMESSAGEBOX_H
#define UI_UIMESSAGEBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UiMessageBox
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *UiMessageBox)
    {
        if (UiMessageBox->objectName().isEmpty())
            UiMessageBox->setObjectName("UiMessageBox");
        UiMessageBox->resize(361, 205);
        verticalLayout = new QVBoxLayout(UiMessageBox);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(UiMessageBox);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);

        retranslateUi(UiMessageBox);

        QMetaObject::connectSlotsByName(UiMessageBox);
    } // setupUi

    void retranslateUi(QWidget *UiMessageBox)
    {
        UiMessageBox->setWindowTitle(QCoreApplication::translate("UiMessageBox", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UiMessageBox: public Ui_UiMessageBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIMESSAGEBOX_H
