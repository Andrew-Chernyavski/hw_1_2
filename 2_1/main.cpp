#include <iostream>
#include "indexlist.h"
#include "indexlisttest.h"
#include "arraylist.h"
#include "arraylisttest.h"



int main()
{
    IndexListTest a;
    QTest::qExec(&a);
    ArrayListTest b;
    QTest::qExec(&b);
    /*
    List *a = new IndexList;
    a->add(14);
    int b = a->size();
    std::cout << b;
    a->remove(14);
    delete a;

    List *c = new ArrayList;
    c->add(14);
    c->add(15);
    int d = c->size(); //12
    std::cout << d;
    c->remove(14);
    delete c;*/

    return 0;
}

