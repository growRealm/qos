#ifndef DAOCLOUDSMOCK_H
#define DAOCLOUDSMOCK_H

#include "daoclouds.h"
#include <QJsonValue>

class DaoCloudsMock: public DaoClouds
{
public:
    DaoCloudsMock(const QString& path);

    virtual QList<MyBucket> buckets();
    virtual QList<MyBucket> login(const QString& secretId, const QString& secretKey);

    virtual bool isBucketExists(const QString& bucketName);
    virtual QString getBucketLocation(const QString& bucketName);

    virtual void putBucket(const QString& bucketName, const QString& location);
    virtual void deleteBucket(const QString& bucketName);
    virtual QList<MyObject> getObjects(const QString &bucketName, const QString &dir);

    virtual void putObject(
        const QString &bucketName,
        const QString& key,
        const QString &localPath,
        const TransProgressCallback& callback);

    virtual void getObject(
        const QString& bucketName,
        const QString& key,
        const QString&localPath,
        const TransProgressCallback& callback);

private:
    QJsonValue m_mock;
};

#endif // DAOCLOUDSMOCK_H
