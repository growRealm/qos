/********************************************************************************
** Form generated from reading UI file 'uibucketstablewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIBUCKETSTABLEWIDGET_H
#define UI_UIBUCKETSTABLEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "src/fend/uicom/uipagewidget.h"
#include "src/fend/uicom/uipushbutton.h"

QT_BEGIN_NAMESPACE

class Ui_UiBucketsTableWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widgetTools;
    QHBoxLayout *horizontalLayout;
    UiPushButton *btnCreateBucket;
    UiPushButton *btnRefresh;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    UiPageWidget *widgetPage;

    void setupUi(QWidget *UiBucketsTableWidget)
    {
        if (UiBucketsTableWidget->objectName().isEmpty())
            UiBucketsTableWidget->setObjectName("UiBucketsTableWidget");
        UiBucketsTableWidget->resize(645, 483);
        verticalLayout = new QVBoxLayout(UiBucketsTableWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widgetTools = new QWidget(UiBucketsTableWidget);
        widgetTools->setObjectName("widgetTools");
        horizontalLayout = new QHBoxLayout(widgetTools);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnCreateBucket = new UiPushButton(widgetTools);
        btnCreateBucket->setObjectName("btnCreateBucket");

        horizontalLayout->addWidget(btnCreateBucket);

        btnRefresh = new UiPushButton(widgetTools);
        btnRefresh->setObjectName("btnRefresh");

        horizontalLayout->addWidget(btnRefresh);

        horizontalSpacer = new QSpacerItem(480, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widgetTools);

        tableView = new QTableView(UiBucketsTableWidget);
        tableView->setObjectName("tableView");
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setShowGrid(false);

        verticalLayout->addWidget(tableView);

        widgetPage = new UiPageWidget(UiBucketsTableWidget);
        widgetPage->setObjectName("widgetPage");

        verticalLayout->addWidget(widgetPage);


        retranslateUi(UiBucketsTableWidget);

        QMetaObject::connectSlotsByName(UiBucketsTableWidget);
    } // setupUi

    void retranslateUi(QWidget *UiBucketsTableWidget)
    {
        UiBucketsTableWidget->setWindowTitle(QCoreApplication::translate("UiBucketsTableWidget", "Form", nullptr));
        btnCreateBucket->setText(QCoreApplication::translate("UiBucketsTableWidget", "\345\210\233\345\273\272\346\241\266", nullptr));
        btnRefresh->setText(QCoreApplication::translate("UiBucketsTableWidget", "\345\210\267\346\226\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UiBucketsTableWidget: public Ui_UiBucketsTableWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIBUCKETSTABLEWIDGET_H
