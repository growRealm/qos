#include <QStandardItemModel>
#include "uibucketslistwidget.h"
#include "src/config/common.h"
#include "ui_uibucketslistwidget.h"

#include <QJsonObject>

UiBucketsListWidget::UiBucketsListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UiBucketsListWidget)
{
    ui->setupUi(this);
    ui->listView->setModel(MG->mModels->modelBuckets());
    connect(MG->mSignal, &ManSignals::bucketsSuccess,
            this, &UiBucketsListWidget::onBucketsSuccess);

    connect(ui->lineEdit, &UiComboLine::itemSelected, this, &UiBucketsListWidget::showBucketObjects);
    connect(ui->lineEdit, &UiComboLine::textEdited, this, &UiBucketsListWidget::onTextEdited);
}

UiBucketsListWidget::~UiBucketsListWidget()
{
    delete ui;
}

void UiBucketsListWidget::onBucketsSuccess(const QList<MyBucket> &buckets)
{
    QStringList words;
    for(const auto& bucket: qAsConst(buckets)) {
        words.append(bucket.name);
    }
    ui->lineEdit->setWords(words);
}


void UiBucketsListWidget::on_listView_doubleClicked(const QModelIndex &index)
{
    showBucketObjects(index.data().toString());
}

void UiBucketsListWidget::showBucketObjects(const QString &bucketName)
{
    QJsonObject params;
    params["bucketName"] = bucketName;
    params["dir"] = "";
    MG->mGate->send(API::OBJECTS::LIST, params);
}

void UiBucketsListWidget::onTextEdited(const QString &text)
{
    QStandardItemModel *model = MG->mModels->modelBuckets();
    for (int i = 0; i < model->rowCount(); ++i) {
        bool hidden = !(model->index(i, 0).data().toString().contains(text));
        ui->listView->setRowHidden(i, hidden);
    }
}

