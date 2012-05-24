#pragma once
#include <QtCore/QObject>
#include <QtTest/QTest>
#include "vector.h"

class VectorTest : public QObject
{
    Q_OBJECT
public:
    explicit VectorTest(QObject *parent = 0): QObject(parent) {}
    
private slots:

    void init()
    {
        tmp = new Vector<int, 2>;
    }

    void testAlgAdd()
    {
        Vector<int, 2> a;
        Vector<int, 2> b;
        a.vect[0] = 3;
        a.vect[1] = 14;
        b.vect[0] = 15;
        b.vect[1] = 92;
        tmp->algebrAdd(&a,&b,'+');
        QVERIFY(tmp->vect[0] = 18);
        QVERIFY(tmp->vect[1] = 106);
        tmp->algebrAdd(&a,&b,'-');
        QVERIFY(tmp->vect[0] = -11);
        QVERIFY(tmp->vect[1] = -78);
    }

    void testScalarProd()
    {
        Vector<int, 2> a;
        Vector<int, 2> b;
        a.vect[0] = 3;
        a.vect[1] = 14;
        b.vect[0] = 15;
        b.vect[1] = 92;
        QVERIFY (tmp->scalarProd(&a,&b) == 1333);
    }

    void cleanup()
    {
        delete tmp;
    }

private:
    Vector<int, 2> *tmp;
    
};

