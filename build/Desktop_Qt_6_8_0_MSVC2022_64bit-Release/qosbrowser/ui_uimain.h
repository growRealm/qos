/********************************************************************************
** Form generated from reading UI file 'uimain.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIMAIN_H
#define UI_UIMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "src/fend/uimain/uibucketslistwidget.h"
#include "src/fend/uimain/uibucketstablewidget.h"
#include "src/fend/uimain/uiobjectstablewidget.h"

QT_BEGIN_NAMESPACE

class Ui_UiMain
{
public:
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    UiBucketsListWidget *widgetBucketsList;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    UiBucketsTableWidget *pageBuckets;
    UiObjectsTableWidget *pageObjects;

    void setupUi(QWidget *UiMain)
    {
        if (UiMain->objectName().isEmpty())
            UiMain->setObjectName("UiMain");
        UiMain->resize(943, 571);
        UiMain->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(UiMain);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(UiMain);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(2);
        widgetBucketsList = new UiBucketsListWidget(splitter);
        widgetBucketsList->setObjectName("widgetBucketsList");
        splitter->addWidget(widgetBucketsList);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName("layoutWidget");
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 0, 0, 0);
        stackedWidget = new QStackedWidget(layoutWidget);
        stackedWidget->setObjectName("stackedWidget");
        pageBuckets = new UiBucketsTableWidget();
        pageBuckets->setObjectName("pageBuckets");
        stackedWidget->addWidget(pageBuckets);
        pageObjects = new UiObjectsTableWidget();
        pageObjects->setObjectName("pageObjects");
        stackedWidget->addWidget(pageObjects);

        verticalLayout->addWidget(stackedWidget);

        splitter->addWidget(layoutWidget);

        horizontalLayout->addWidget(splitter);


        retranslateUi(UiMain);

        QMetaObject::connectSlotsByName(UiMain);
    } // setupUi

    void retranslateUi(QWidget *UiMain)
    {
        UiMain->setWindowTitle(QCoreApplication::translate("UiMain", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UiMain: public Ui_UiMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIMAIN_H
