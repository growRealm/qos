#include "manmodels.h"
#include "src/middle/manglobal.h"
#include "src/middle/signals/mansignals.h"

#include <src/helper/bytehelper.h>

ManModels::ManModels(QObject *parent)
    : QObject{parent}
{
    m_modelBuckets = new QStandardItemModel(this);
    m_modelObjects = new QStandardItemModel(this);
    initBucketsTable();
    initObjectsTable();
    connect(MG->mSignal, &ManSignals::bucketsSuccess, this, &ManModels::setBuckets);
    connect(MG->mSignal, &ManSignals::objectsSuccess, this, &ManModels::setObjects);
}

void ManModels::setBuckets(const QList<MyBucket>& buckets)
{
    m_modelBuckets->setRowCount(buckets.size());
    for (int i = 0; i < buckets.size(); ++i) {
        const MyBucket& bucket = buckets[i];
        QModelIndex index0 = m_modelBuckets->index(i, 0);
        m_modelBuckets->setData(index0, bucket.name);
        m_modelBuckets->setData(index0, QString("存储桶名称：%1").arg(bucket.name), Qt::ToolTipRole);
        m_modelBuckets->setData(index0, QIcon(GLOBAL::PATH::BUCKET), Qt::DecorationRole);

        QModelIndex index1 = m_modelBuckets->index(i, 1);
        m_modelBuckets->setData(index1, bucket.location);
        QModelIndex index2 = m_modelBuckets->index(i, 2);
        m_modelBuckets->setData(index2, bucket.createDate);
    }
    // 按时间降序排序
    m_modelBuckets->sort(2, Qt::DescendingOrder);
}

void ManModels::setObjects(const QList<MyObject> &objects)
{
    m_modelObjects->setRowCount(objects.size());
    for (int i = 0; i < objects.size(); ++i) {
        const MyObject& obj = objects[i];
        // 名称
        QModelIndex index0 = m_modelObjects->index(i, 0);
        m_modelObjects->setData(index0, obj.name);
        QVariant var;
        var.setValue(obj);
        m_modelObjects->setData(index0, var, Qt::UserRole);
        if (obj.isDir()){
            m_modelObjects->setData(index0, QIcon(GLOBAL::PATH::DIR), Qt::DecorationRole);
        }
        else {
            m_modelObjects->setData(index0, QIcon(GLOBAL::PATH::FILE), Qt::DecorationRole);
        }

        // 大小
        QModelIndex index1 = m_modelObjects->index(i, 1);
        QString sizeStr = ByteHelper::toBeautifulStr(obj.size);
        m_modelObjects->setData(index1, sizeStr);
        // 修改时间
       QModelIndex index2 = m_modelObjects->index(i, 2);
        m_modelObjects->setData(index2, obj.lastmodified);
    }
}

void ManModels::initBucketsTable()
{
    // 设置标题内容
    QStringList labels;
    labels << QString("桶名称")
           << QString("地区")
           << QString("创建时间");
    m_modelBuckets->setColumnCount(labels.size());
    m_modelBuckets->setHorizontalHeaderLabels(labels);
}

void ManModels::initObjectsTable()
{
    // 设置标题内容
    QStringList labels;
    labels << QString("对象名称")
           << QString("大小")
           << QString("更新时间");
    m_modelObjects->setColumnCount(labels.size());
    m_modelObjects->setHorizontalHeaderLabels(labels);
}

QStandardItemModel *ManModels::modelObjects() const
{
    return m_modelObjects;
}

QStandardItemModel *ManModels::modelBuckets() const
{
    return m_modelBuckets;
}
