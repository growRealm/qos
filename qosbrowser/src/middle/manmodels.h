#ifndef MANMODELS_H
#define MANMODELS_H

#include <QObject>
#include <QStandardItemModel>
#include "src/middle/models/cloudmodels.h"

class ManModels : public QObject
{
    Q_OBJECT
public:
    explicit ManModels(QObject *parent = nullptr);

    QStandardItemModel *modelBuckets() const;

    QStandardItemModel *modelObjects() const;

signals:

private slots:
    void setBuckets(const QList<MyBucket>& buckets);
    void setObjects(const QList<MyObject>& objects);

private:
    void initBucketsTable();
    void initObjectsTable();

private:
    QStandardItemModel* m_modelBuckets = nullptr; // 存储桶表格模型
    QStandardItemModel* m_modelObjects = nullptr;  //对象表格模型
};

#endif // MANMODELS_H
