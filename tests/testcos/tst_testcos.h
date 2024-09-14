#ifndef TESTCOS_H
#define TESTCOS_H

#include <QtTest>

#include <src/bend/dao/clouds/daocloudscos.h>

// add necessary includes here

class TestCos : public QObject
{
    Q_OBJECT

public:
    TestCos();
    ~TestCos();

private slots:
    // 调用所有测试用例之前，会先调用一次该函数
    void initTestCase();
    // 调用所有测试用例之后，会先调用一次该函数
    void cleanupTestCase();
    void test_buckets();
    void test_isBucketExists();
    void test_getBucketLocation();
    void test_putBucket();
    void test_deleteBucket();
    void test_getObjects();
    void test_getObjects2_data();
    void test_getObjects2();
    void test_getObjectError();
    void test_putObject();
    void test_getObject();

private:
    DaoCloudsCos m_cos;
    QString m_secretId = "";  //替换成自己的id
    QString m_secretKey = "";    // 替换成自己的key
    QString m_bucketName = "";  // 替换成自己的测试桶名称

    QString m_uploadLocalPath = "./upload.txt";
    QString m_downloadLocalPath = "./download.txt";
    QString m_updownKey = "test/bll/newupload.txt";
};


#endif  // TESTCOS_H

