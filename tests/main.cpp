#include <testcos/tst_testcos.h>
#include <testfilehelper/tst_testfilehelper.h>
#include <testexceptions/tst_testexceptions.h>


int main(int argc, char *argv[])
{
    int status = 0;
//    {TestFileHelper tc; status |= QTest::qExec(&tc, argc, argv);}
//    {TestExceptions tc; status |= QTest::qExec(&tc, argc, argv);}
    {TestCos tc; status |= QTest::qExec(&tc, argc, argv);}
}
