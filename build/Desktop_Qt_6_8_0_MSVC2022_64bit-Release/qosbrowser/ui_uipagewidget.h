/********************************************************************************
** Form generated from reading UI file 'uipagewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIPAGEWIDGET_H
#define UI_UIPAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "src/fend/uicom/uicomboline.h"
#include "src/fend/uicom/uipushbutton.h"

QT_BEGIN_NAMESPACE

class Ui_UiPageWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *labelTotalCount;
    QLabel *label;
    UiComboLine *lineMaxRows;
    QLabel *label_2;
    UiPushButton *btnPre;
    UiComboLine *lineCurrentPage;
    QLabel *labelPageCount;
    UiPushButton *btnNext;

    void setupUi(QWidget *UiPageWidget)
    {
        if (UiPageWidget->objectName().isEmpty())
            UiPageWidget->setObjectName("UiPageWidget");
        UiPageWidget->resize(506, 23);
        UiPageWidget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(UiPageWidget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        labelTotalCount = new QLabel(UiPageWidget);
        labelTotalCount->setObjectName("labelTotalCount");
        labelTotalCount->setMinimumSize(QSize(10, 0));

        horizontalLayout->addWidget(labelTotalCount);

        label = new QLabel(UiPageWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineMaxRows = new UiComboLine(UiPageWidget);
        lineMaxRows->setObjectName("lineMaxRows");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineMaxRows->sizePolicy().hasHeightForWidth());
        lineMaxRows->setSizePolicy(sizePolicy);
        lineMaxRows->setMaximumSize(QSize(36, 16777215));

        horizontalLayout->addWidget(lineMaxRows);

        label_2 = new QLabel(UiPageWidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        btnPre = new UiPushButton(UiPageWidget);
        btnPre->setObjectName("btnPre");
        btnPre->setMaximumSize(QSize(25, 16777215));

        horizontalLayout->addWidget(btnPre);

        lineCurrentPage = new UiComboLine(UiPageWidget);
        lineCurrentPage->setObjectName("lineCurrentPage");
        sizePolicy.setHeightForWidth(lineCurrentPage->sizePolicy().hasHeightForWidth());
        lineCurrentPage->setSizePolicy(sizePolicy);
        lineCurrentPage->setMaximumSize(QSize(32, 16777215));

        horizontalLayout->addWidget(lineCurrentPage);

        labelPageCount = new QLabel(UiPageWidget);
        labelPageCount->setObjectName("labelPageCount");
        labelPageCount->setMinimumSize(QSize(10, 0));

        horizontalLayout->addWidget(labelPageCount);

        btnNext = new UiPushButton(UiPageWidget);
        btnNext->setObjectName("btnNext");
        btnNext->setMaximumSize(QSize(25, 16777215));

        horizontalLayout->addWidget(btnNext);


        retranslateUi(UiPageWidget);

        QMetaObject::connectSlotsByName(UiPageWidget);
    } // setupUi

    void retranslateUi(QWidget *UiPageWidget)
    {
        UiPageWidget->setWindowTitle(QCoreApplication::translate("UiPageWidget", "Form", nullptr));
        labelTotalCount->setText(QString());
        label->setText(QCoreApplication::translate("UiPageWidget", "\346\257\217\351\241\265\346\230\276\347\244\272", nullptr));
        label_2->setText(QCoreApplication::translate("UiPageWidget", "\350\241\214 ", nullptr));
#if QT_CONFIG(tooltip)
        btnPre->setToolTip(QCoreApplication::translate("UiPageWidget", "\344\270\212\344\270\200\351\241\265", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPre->setText(QCoreApplication::translate("UiPageWidget", "<", nullptr));
        labelPageCount->setText(QString());
#if QT_CONFIG(tooltip)
        btnNext->setToolTip(QCoreApplication::translate("UiPageWidget", "\344\270\213\344\270\200\351\241\265", nullptr));
#endif // QT_CONFIG(tooltip)
        btnNext->setText(QCoreApplication::translate("UiPageWidget", ">", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UiPageWidget: public Ui_UiPageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIPAGEWIDGET_H
