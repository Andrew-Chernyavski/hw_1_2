#include <iostream>
#include "vector.h"
#include "vectortest.h"

using namespace std;

int main()
{

    VectorTest test;
    QTest::qExec(&test);
    return 0;
}

