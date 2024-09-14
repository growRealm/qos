/********************************************************************************
** Form generated from reading UI file 'uibreadwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIBREADWIDGET_H
#define UI_UIBREADWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UiBreadWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QListView *listView;

    void setupUi(QWidget *UiBreadWidget)
    {
        if (UiBreadWidget->objectName().isEmpty())
            UiBreadWidget->setObjectName("UiBreadWidget");
        UiBreadWidget->resize(657, 50);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UiBreadWidget->sizePolicy().hasHeightForWidth());
        UiBreadWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(UiBreadWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listView = new QListView(UiBreadWidget);
        listView->setObjectName("listView");
        listView->setMaximumSize(QSize(16777215, 50));
        listView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setSelectionMode(QAbstractItemView::SingleSelection);
        listView->setMovement(QListView::Static);
        listView->setFlow(QListView::LeftToRight);
        listView->setProperty("isWrapping", QVariant(false));
        listView->setResizeMode(QListView::Adjust);

        horizontalLayout->addWidget(listView);


        retranslateUi(UiBreadWidget);

        QMetaObject::connectSlotsByName(UiBreadWidget);
    } // setupUi

    void retranslateUi(QWidget *UiBreadWidget)
    {
        UiBreadWidget->setWindowTitle(QCoreApplication::translate("UiBreadWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UiBreadWidget: public Ui_UiBreadWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIBREADWIDGET_H
