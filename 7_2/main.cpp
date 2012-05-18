#include <iostream>
//#include "indexlist.h"
//#include "indexlisttest.h"
#include "uniquelist.h"
#include "uniquelisttest.h"


int main()
{
    //IndexListTest a;
    //QTest::qExec(&a);
    UniqueListTest test;
    QTest::qExec(&test);


    return 0;
}

