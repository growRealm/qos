/********************************************************************************
** Form generated from reading UI file 'uitransfer.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UITRANSFER_H
#define UI_UITRANSFER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "src/fend/uitransfer/uidownload.h"
#include "src/fend/uitransfer/uiupload.h"

QT_BEGIN_NAMESPACE

class Ui_UiTransfer
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    UiUpload *tabUpload;
    UiDownload *tabDownload;

    void setupUi(QWidget *UiTransfer)
    {
        if (UiTransfer->objectName().isEmpty())
            UiTransfer->setObjectName("UiTransfer");
        UiTransfer->resize(369, 301);
        horizontalLayout = new QHBoxLayout(UiTransfer);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(UiTransfer);
        tabWidget->setObjectName("tabWidget");
        tabUpload = new UiUpload();
        tabUpload->setObjectName("tabUpload");
        tabWidget->addTab(tabUpload, QString());
        tabDownload = new UiDownload();
        tabDownload->setObjectName("tabDownload");
        tabWidget->addTab(tabDownload, QString());

        horizontalLayout->addWidget(tabWidget);


        retranslateUi(UiTransfer);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(UiTransfer);
    } // setupUi

    void retranslateUi(QWidget *UiTransfer)
    {
        UiTransfer->setWindowTitle(QCoreApplication::translate("UiTransfer", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabUpload), QCoreApplication::translate("UiTransfer", "\344\270\212\344\274\240", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDownload), QCoreApplication::translate("UiTransfer", "\344\270\213\350\275\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UiTransfer: public Ui_UiTransfer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UITRANSFER_H
