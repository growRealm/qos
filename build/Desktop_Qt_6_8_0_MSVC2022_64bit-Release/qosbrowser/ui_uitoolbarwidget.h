/********************************************************************************
** Form generated from reading UI file 'uitoolbarwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UITOOLBARWIDGET_H
#define UI_UITOOLBARWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UiToolBarWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCreateBucket;
    QPushButton *btnRefresh;
    QPushButton *btnUpload;
    QPushButton *btnDownload;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnTrans;
    QPushButton *btnQuit;

    void setupUi(QWidget *UiToolBarWidget)
    {
        if (UiToolBarWidget->objectName().isEmpty())
            UiToolBarWidget->setObjectName("UiToolBarWidget");
        UiToolBarWidget->resize(526, 23);
        horizontalLayout = new QHBoxLayout(UiToolBarWidget);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnCreateBucket = new QPushButton(UiToolBarWidget);
        btnCreateBucket->setObjectName("btnCreateBucket");
        btnCreateBucket->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(btnCreateBucket);

        btnRefresh = new QPushButton(UiToolBarWidget);
        btnRefresh->setObjectName("btnRefresh");
        btnRefresh->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(btnRefresh);

        btnUpload = new QPushButton(UiToolBarWidget);
        btnUpload->setObjectName("btnUpload");
        btnUpload->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(btnUpload);

        btnDownload = new QPushButton(UiToolBarWidget);
        btnDownload->setObjectName("btnDownload");
        btnDownload->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(btnDownload);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnTrans = new QPushButton(UiToolBarWidget);
        btnTrans->setObjectName("btnTrans");
        btnTrans->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(btnTrans);

        btnQuit = new QPushButton(UiToolBarWidget);
        btnQuit->setObjectName("btnQuit");
        btnQuit->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(btnQuit);


        retranslateUi(UiToolBarWidget);

        QMetaObject::connectSlotsByName(UiToolBarWidget);
    } // setupUi

    void retranslateUi(QWidget *UiToolBarWidget)
    {
        UiToolBarWidget->setWindowTitle(QCoreApplication::translate("UiToolBarWidget", "Form", nullptr));
        btnCreateBucket->setText(QCoreApplication::translate("UiToolBarWidget", "\345\210\233\345\273\272\346\241\266", nullptr));
        btnRefresh->setText(QCoreApplication::translate("UiToolBarWidget", "\345\210\267\346\226\260", nullptr));
        btnUpload->setText(QCoreApplication::translate("UiToolBarWidget", "\344\270\212\344\274\240", nullptr));
        btnDownload->setText(QCoreApplication::translate("UiToolBarWidget", "\344\270\213\350\275\275", nullptr));
        btnTrans->setText(QCoreApplication::translate("UiToolBarWidget", "\344\274\240\350\276\223\345\210\227\350\241\250", nullptr));
        btnQuit->setText(QCoreApplication::translate("UiToolBarWidget", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UiToolBarWidget: public Ui_UiToolBarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UITOOLBARWIDGET_H
