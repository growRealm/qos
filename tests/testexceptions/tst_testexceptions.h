#ifndef TESTEXCEPTIONS_H
#define TESTEXCEPTIONS_H

#include <QtTest>

class TestExceptions : public QObject
{
    Q_OBJECT

public:
    TestExceptions();
    ~TestExceptions();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

#endif  // TESTEXCEPTIONS_H
