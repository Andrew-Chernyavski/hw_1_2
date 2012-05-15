#include "stack.h"
#include "indexstack.h"
#include "indexstacktest.h"
#include "arraystack.h"
#include "arraystacktest.h"
#include <iostream>


int main()
{
    IndexStackTest a;
    QTest::qExec (&a);
    ArrayStackTest b;
    QTest::qExec (&b);

    /*
    Stack *st1 = new ArrayStack();
    Stack *st2 = new IndexStack();
    int n = 23;
    std::cout << n << "\n";
    st1->push(n);
    st2->push(n);
    int m = st1->pop();
    std::cout << m << "\n";
    int k = st2->pop();
    std::cout << k << "\n";
    delete st1;
    delete st2;
    return 0;
        */
    std::cout << "the end\n";
}

