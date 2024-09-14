/********************************************************************************
** Form generated from reading UI file 'uiprogresswidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIPROGRESSWIDGET_H
#define UI_UIPROGRESSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UiProgressWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QProgressBar *progressBar;
    QLabel *labelSpeed;
    QLabel *labelTime;

    void setupUi(QWidget *UiProgressWidget)
    {
        if (UiProgressWidget->objectName().isEmpty())
            UiProgressWidget->setObjectName("UiProgressWidget");
        UiProgressWidget->resize(418, 40);
        UiProgressWidget->setMinimumSize(QSize(0, 40));
        horizontalLayout = new QHBoxLayout(UiProgressWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        progressBar = new QProgressBar(UiProgressWidget);
        progressBar->setObjectName("progressBar");
        progressBar->setMaximumSize(QSize(16777215, 18));
        progressBar->setValue(0);
        progressBar->setTextVisible(true);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);

        horizontalLayout->addWidget(progressBar);

        labelSpeed = new QLabel(UiProgressWidget);
        labelSpeed->setObjectName("labelSpeed");

        horizontalLayout->addWidget(labelSpeed);

        labelTime = new QLabel(UiProgressWidget);
        labelTime->setObjectName("labelTime");

        horizontalLayout->addWidget(labelTime);


        retranslateUi(UiProgressWidget);

        QMetaObject::connectSlotsByName(UiProgressWidget);
    } // setupUi

    void retranslateUi(QWidget *UiProgressWidget)
    {
        UiProgressWidget->setWindowTitle(QCoreApplication::translate("UiProgressWidget", "Form", nullptr));
        progressBar->setFormat(QCoreApplication::translate("UiProgressWidget", "%p%", nullptr));
        labelSpeed->setText(QString());
        labelTime->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UiProgressWidget: public Ui_UiProgressWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIPROGRESSWIDGET_H
