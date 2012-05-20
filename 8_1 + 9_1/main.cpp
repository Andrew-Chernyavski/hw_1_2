#include <iostream>
#include "bag.h"
#include "bagtest.h"

using namespace std;

int main()
{
    Bag *a = new Bag;
    for (int i = 0; i < 4; i++)
    {
        a->add(3);
        a->add(-5);
    }
    for (int i = 0; i < 10; i++)
    {
        a->add(5);
        a->add(14);
        a->add(21);
    }
    a->add(2);
    a->add(7);
    a->add(14);
    a->add(-5);
    a->print();
    delete a;

    bagTest test;
    QTest::qExec(&test);
}

