﻿#include "uidownload.h"
#include "src/config/common.h"
#include "ui_uidownload.h"
#include <src/fend/uicom/uiprogresswidget.h>
#include <src/fend/uidelegates/uitableitemdelegate.h>


UiDownload::UiDownload(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UiDownload)
{
    ui->setupUi(this);
    initHeader();
    connect(MG->mSignal, &ManSignals::startDownload, this, &UiDownload::onStartDownload);
    connect(MG->mSignal, &ManSignals::downloadProcess, this, &UiDownload::onDownloadProcess);
    connect(MG->mSignal, &ManSignals::downloadSuccess, this, &UiDownload::onDownloadSuccess);
    connect(MG->mSignal, &ManSignals::error, this, &UiDownload::onError);
    ui->tableWidget->setItemDelegate(new UiTableItemDelegate(ui->tableWidget));
}

UiDownload::~UiDownload()
{
    delete ui;
}

void UiDownload::onStartDownload(const QString& jobId, const QString& key, const QString& localPath, qulonglong total)
{
    ui->tableWidget->insertRow(0);
    ui->tableWidget->setRowHeight(0, 40);
    QTableWidgetItem* item = new QTableWidgetItem(key);
    item->setData(Qt::UserRole, jobId);
    ui->tableWidget->setItem(0, 0, item);
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(localPath));
    
    UiProgressWidget *bar = new UiProgressWidget();
    bar->setRange(0, total);
    ui->tableWidget->setCellWidget(0, 2, bar);
}

void UiDownload::onDownloadProcess(const QString &jobId, qulonglong transferedSize, qulonglong totalSize)
{
    UiProgressWidget* w = findTableWidgetItem(jobId);
    w->setValue(transferedSize);
}

void UiDownload::onDownloadSuccess(const QString &jobId)
{
    UiProgressWidget* w = findTableWidgetItem(jobId);
    w->setFinished(STR("下载成功"));
}

void UiDownload::onError(int api, const QString &msg, const QJsonValue &req)
{
    if (api != API::OBJECTS::GET)
        return;
    UiProgressWidget* w = findTableWidgetItem(req["jobId"].toString());
    w->setError(STR("下载失败"));
    w->setToolTip(msg);
}

UiProgressWidget* UiDownload::findTableWidgetItem(const QString &jobId)
{
    for (int i  = 0; i < ui->tableWidget->rowCount(); i++)
    {
        QTableWidgetItem* item = ui->tableWidget->item(i, 0);
        QString itemId = item->data(Qt::UserRole).toString();
        if (itemId == jobId)
        {
            return dynamic_cast<UiProgressWidget*>(ui->tableWidget->cellWidget(i, 2));
        }
    }
    return nullptr;
}

void UiDownload::initHeader()
{
    QStringList headers;
    headers << STR("云端路径")
            << STR("本地路径")
            << STR("下载状态");
    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(1);
}
