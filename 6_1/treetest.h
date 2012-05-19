#pragma once
#include <QtCore/QObject>
#include <QtTest/QTest>
#include "operations.h"
#include "numbers.h"

class treeTest : public QObject
{
    Q_OBJECT
public:
    explicit treeTest(QObject *parent = 0):  QObject(parent) {}

private slots:

    void init()
    {
        tmp = new Operations;
    }

    void testCalculate()
    {
        char str[9] = {'(','*','4','(','+','1','2',')',')'}; // (*4(+12))
        tmp->getTree(str, 0);
        QVERIFY(tmp->calculate() == 12);
    }

    void clenup()
    {
        delete tmp;
    }
    
private:
    Operations *tmp;
};
