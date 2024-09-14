#include "tst_testcos.h"

#include <src/config/exceptions.h>

#include <src/helper/filehelper.h>

TestCos::TestCos()
{

}

TestCos::~TestCos()
{

}

void TestCos::initTestCase()
{
    m_cos.login(m_secretId, m_secretKey);
    FileHelper::writeFlie(QStringList() << "abc" << "def", m_uploadLocalPath);
}

void TestCos::cleanupTestCase()
{
    QFile::remove(m_uploadLocalPath);
    QFile::remove(m_downloadLocalPath);
}

void TestCos::test_buckets()
{
    QList<MyBucket> bs = m_cos.buckets();
    QVERIFY(bs.size() > 0); // QVERIFY 进行bool表达式的判断，如果为真 ，则表示通过，否则表示失败

//    QCOMPARE(bs.size(), 3);  // QCOMPARE 进行恒等的比较
}

void TestCos::test_isBucketExists()
{
    bool exists = m_cos.isBucketExists(m_bucketName);
    QVERIFY(exists);
}

void TestCos::test_getBucketLocation()
{
    QString location = m_cos.getBucketLocation(m_bucketName);
    QCOMPARE(location, "ap-shanghai");
}

void TestCos::test_putBucket()
{
    // 存储桶，必须包含appid
    QSKIP("SKIP test_putBucket");
    QString name = "test-1300416378";
    m_cos.putBucket(name, "ap-shanghai");
    bool exists = m_cos.isBucketExists(name);
    QVERIFY(exists);
}

void TestCos::test_deleteBucket()
{
    QSKIP("SKIP test_deleteBucket");
    QString name = "test-1300416378";
    m_cos.deleteBucket(name);
    bool notexists = !m_cos.isBucketExists(name);
    QVERIFY(notexists);
}

void TestCos::test_getObjects()
{
    QSKIP("test_getObjects");
    QList<MyObject> objList =
        m_cos.getObjects(m_bucketName, "");
    QCOMPARE(objList.size(), 7);

    objList = m_cos.getObjects(m_bucketName, "test/");
    QCOMPARE(objList.size(), 11);

    objList = m_cos.getObjects(m_bucketName, "test/bll/");
    QCOMPARE(objList.size(), 4);
}

void TestCos::test_getObjects2_data()
{
    // 数据驱动：第一阶段，准备测试数据，函数名称需要 _data 结尾
    QTest::addColumn<QString>("dir");
    QTest::addColumn<int>("expected");

    QTest::newRow("root") << "" << 7;
    QTest::newRow("subdir") << "test/" << 11;
    QTest::newRow("leaf") << "test/bll/" << 4;
}

void TestCos::test_getObjects2()
{
    // 数据驱动：第二阶段，从数据表读取数据，并执行比较
    QFETCH(QString, dir);
    QFETCH(int, expected);

    QList<MyObject> objList =
        m_cos.getObjects(m_bucketName, dir);
    QCOMPARE(objList.size(), expected);
}

void TestCos::test_getObjectError()
{
    // QVERIFY_EXCEPTION_THROWN 捕获预期异常
    QVERIFY_EXCEPTION_THROWN(
        m_cos.getObjects("file", ""),
        BaseException
        );
}

void TestCos::test_putObject()
{
    m_cos.putObject(m_bucketName, m_updownKey, m_uploadLocalPath, nullptr);
    QVERIFY(m_cos.isObjectExists(m_bucketName, m_updownKey));
}

void TestCos::test_getObject()
{
    m_cos.getObject(m_bucketName, m_updownKey, m_downloadLocalPath, nullptr);
    QVERIFY(QFile::exists(m_downloadLocalPath));
}

