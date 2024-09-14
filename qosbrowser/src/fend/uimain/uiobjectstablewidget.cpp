#include <QStandardItemModel>
#include <QJsonObject>
#include <QFileDialog>
#include <QMessageBox>
#include <src/middle/signals/mansignals.h>
#include <src/fend/uidelegates/uitableitemdelegate.h>
#include "src/bend/gateway.h"
#include "src/bend/man/mancloud.h"
#include "uiobjectstablewidget.h"
#include "ui_uiobjectstablewidget.h"
#include "src/middle/manmodels.h"
#include "src/middle/manglobal.h"

UiObjectsTableWidget::UiObjectsTableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UiObjectsTableWidget)
{
    ui->setupUi(this);
    ui->btnBuckets->setProperty("style_button", "main");
    ui->tableView->setModel(MG->mModels->modelObjects());

    // 设置列宽度
    ui->tableView->setColumnWidth(0, 200);
    ui->tableView->setColumnWidth(1, 120);
    ui->tableView->horizontalHeader()->setStretchLastSection(true); //设置最后一列占满整个表

    // 隐藏垂直标题
    ui->tableView->verticalHeader()->setHidden(true);

    // 设置鼠标点击排序
    ui->tableView->setSortingEnabled(true);

    // 初始化翻页按钮
    ui->widgetPage->setMaxRowList(QList<int>() << 10 << 50 << 100);
    connect(ui->widgetPage, &UiPageWidget::pageNumChanged,
            this, &UiObjectsTableWidget::onPageNumChanged);

    connect(ui->widgetBread, &UiBreadWidget::pathChanged,
            this, &UiObjectsTableWidget::onPathChanged);
    connect(MG->mSignal, &ManSignals::objectsSuccess,
            this, &UiObjectsTableWidget::onObjectsSuccess);

    // 关联上传成功信号
    connect(MG->mSignal, &ManSignals::uploadSuccess, this, &UiObjectsTableWidget::onUploadSuccess);
    connect(MG->mSignal, &ManSignals::downloadSuccess, this, &UiObjectsTableWidget::onDownloadSuccess);

    ui->tableView->setItemDelegate(new UiTableItemDelegate(ui->tableView));
}

UiObjectsTableWidget::~UiObjectsTableWidget()
{
    delete ui;
}

void UiObjectsTableWidget::on_btnBuckets_clicked()
{
    MG->mGate->send(API::BUCKETS::LIST);
}


void UiObjectsTableWidget::on_tableView_doubleClicked(const QModelIndex &index)
{
    MyObject obj = index.data(Qt::UserRole).value<MyObject>();
    if (obj.isDir()) {
        QJsonObject params;
        params["bucketName"] = MG->mCloud->currentBucketName();
        params["dir"] = obj.key;
        MG->mGate->send(API::OBJECTS::LIST, params);
    }
}

void UiObjectsTableWidget::onObjectsSuccess(const QList<MyObject> &objects)
{
    QString path = MG->mCloud->currentBucketName() + "/" +MG->mCloud->currentDir();
    ui->widgetBread->setPath(path);
    ui->widgetPage->setTotalRow(objects.size());

    QStandardItemModel *model = MG->mModels->modelObjects();
    for (int i = 0; i < model->rowCount(); ++i) {
        ui->tableView->setRowHeight(i, 40);
    }
}

void UiObjectsTableWidget::onPathChanged(const QString &newPath)
{
    // newPath=file-1300416378/test/bll
    // 需要将newPath 转化为 test/bll/
    QString key = newPath+"/";
    key = key.mid(key.indexOf("/")+1);

    QJsonObject params;
    params["bucketName"] = MG->mCloud->currentBucketName();
    params["dir"] = key;
    MG->mGate->send(API::OBJECTS::LIST, params);
}

void UiObjectsTableWidget::onPageNumChanged(int start, int maxLen)
{
    QStandardItemModel *model = MG->mModels->modelObjects();
    for (int i = 0; i < model->rowCount(); i++) {
        bool hidden = (i < start || (i>=start+maxLen));
        ui->tableView->setRowHidden(i , hidden);
    }
}

void UiObjectsTableWidget::on_btnRefresh_clicked()
{
    onPathChanged(ui->widgetBread->currentPath());
}


void UiObjectsTableWidget::on_btnUpload_clicked()
{
    static QString lastDir = "./";
    // 1 获取本地文件
    QString filePath = QFileDialog::getOpenFileName(
        this, QString("上传文件"), lastDir
        );
    QFileInfo info(filePath);
    if (info.isFile() && info.exists()) {
        QString jobId = QUuid::createUuid().toString();

        filePath = filePath.replace("\\", "/");
        QJsonObject params;
        QString key = MG->mCloud->currentDir() + info.fileName();
        params["jobId"] = jobId;
        params["bucketName"] = MG->mCloud->currentBucketName();
        params["key"] = MG->mCloud->currentDir() + info.fileName();
        params["localPath"] = filePath;
        MG->mGate->send(API::OBJECTS::PUT, params);
        lastDir = info.dir().absolutePath();
        emit MG->mSignal->startUpload(jobId, key, filePath);
    }
}

void UiObjectsTableWidget::onUploadSuccess(const QString &jobId)
{
    on_btnRefresh_clicked();
    showMessage(
        QString("上传文件"),
        QString("上传文件成功"));
}

void UiObjectsTableWidget::onDownloadSuccess(const QString &jobId)
{
    showMessage(
        QString("下载文件"),
        QString("下载文件成功"));
}


void UiObjectsTableWidget::on_btnDownload_clicked()
{
    QModelIndex idx = ui->tableView->currentIndex();
    if (!idx.isValid()) {
        showMessage(
            QString("下载文件"),
            QString("请选择要下载的文件"));
        return;
    }

    MyObject obj = idx.data(Qt::UserRole).value<MyObject>();
    if (obj.isDir()) {
        showMessage(
            QString("下载文件"),
            QString("只能选择文件进行下载"));
        return;
    }

    QString name = idx.data().toString();
    static QString lastDir = "./";
    QString filePath = QFileDialog::getSaveFileName(this,
                                                    QString("下载文件"),
                                                    FileHelper::joinPath(lastDir, name)
                                                    );
    if (filePath.isEmpty()) {
        return;
    }

    QFileInfo info(filePath);
    QString jobId = QUuid::createUuid().toString();

    filePath = filePath.replace("\\", "/");
    QJsonObject params;
    QString key = MG->mCloud->currentDir() + name;
    params["jobId"] = jobId;
    params["bucketName"] = MG->mCloud->currentBucketName();
    params["key"] = key;
    params["localPath"] = filePath;
    MG->mGate->send(API::OBJECTS::GET, params);
    lastDir = info.dir().absolutePath();
    emit MG->mSignal->startDownload(jobId, key, filePath, obj.size);
}

void UiObjectsTableWidget::showMessage(const QString& title, const QString& info)
{
    QMessageBox box(
        QMessageBox::Information,
        title,
        info,
        QMessageBox::Ok
        );
    box.setButtonText(QMessageBox::Ok, QString("确定"));
    box.exec();
}

