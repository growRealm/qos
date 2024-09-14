#include "uitoolbarwidget.h"
#include "src/config/common.h"
#include "ui_uitoolbarwidget.h"

#include <QFileDialog>
#include <QSignalMapper>
#include <QJsonObject>
#include <QInputDialog>

UiToolBarWidget::UiToolBarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UiToolBarWidget)
{
    ui->setupUi(this);
}

UiToolBarWidget::~UiToolBarWidget()
{
    delete ui;
}

void UiToolBarWidget::on_btnQuit_clicked()
{
    emit MG->mSignal->unLogin();
}

