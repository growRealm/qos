#ifndef MANCLOUD_H
#define MANCLOUD_H


#include <QObject>

#include <src/middle/models/cloudmodels.h>


class ManCloud : public QObject
{
    Q_OBJECT
public:
    explicit ManCloud(QObject *parent = nullptr);
    ~ManCloud();

    void login(QString secretId, QString secretKey);

    // 桶操作接口
    void getBuckets();
    void putBucket(const QString& bucketName, const QString& location);
    void deleteBucket(const QString& bucketName);

    // 对象操作接口
    void getObjects(const QString& bucketName, const QString& dir="");
    void getObject(
        const QString& jobId,
        const QString& bucketName,
        const QString& key,
        const QString&localPath);
    void putObject(
        const QString& jobId,
        const QString &bucketName,
        const QString& key,
        const QString &localPath);
    QString currentBucketName() const;

    QString currentDir() const;

private:
    void bucketsAlready(const QList<MyBucket> &buckets);

private:
    QString m_currentBucketName; // 记录当前对象所在存储桶名称
    QString m_currentDir;  // 记录当前对象所在的父目录
};

#endif // MANCLOUD_H
