#ifndef DAOCLOUDSCOS_H
#define DAOCLOUDSCOS_H
#include "daoclouds.h"

namespace qcloud_cos {
class CosConfig;
class CosResult;
class GetBucketResp;
}

class DaoCloudsCos: public DaoClouds
{
public:
    DaoCloudsCos();
    ~DaoCloudsCos();

    virtual QList<MyBucket> buckets();
    virtual QList<MyBucket> login(const QString& secretId, const QString& secretKey);

    virtual bool isBucketExists(const QString& bucketName);
    virtual QString getBucketLocation(const QString& bucketName) ;

    virtual void putBucket(const QString& bucketName, const QString& location);
    virtual void deleteBucket(const QString& bucketName);

    QList<MyObject> getObjects(const QString &bucketName, const QString &dir);
    bool isObjectExists(const QString &bucketName, const QString &key);

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
    QList<MyObject> getDirList(qcloud_cos::GetBucketResp &resp, const QString &dir);
    QList<MyObject> getFileList(qcloud_cos::GetBucketResp &resp, const QString &dir);
    void throwError(const QString &code, qcloud_cos::CosResult &result);
    MyBucket getBucketByName(const QString& bucketName);

private:
    qcloud_cos::CosConfig* m_config = nullptr;
};

#endif // DAOCLOUDSCOS_H
