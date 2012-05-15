#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "set.h"

class setTests : public QObject
{
    Q_OBJECT
public:
    explicit setTests(QObject *parent = 0): QObject(parent){}
    
private slots:

    void init()
    {
        tmp1 = new Set<int>;
        tmp2 = new Set<int>;
        tmp3 = new Set<int>;
    }

    void TestIsEmpty()
    {
        QVERIFY(tmp1->isEmpty());
    }

    void TestAdd()
    {
        tmp1->add(4);
        QVERIFY(!tmp1->isEmpty());
    }

    void TestFind()
    {
        tmp1->add(5);
        tmp1->add(6);
        tmp1->add(8);
        QVERIFY(tmp1->find(6) && !tmp1->find(1));
    }


    void TestDelete()
    {
        tmp1->add(4);
        tmp1->add(5);
        tmp1->del(4);
        QVERIFY(tmp1->find(5) && !tmp1->find(4));
    }

    void TestIntersect()
    {
        tmp3->add(1);
        tmp3->add(2);
        tmp2->add(2);
        tmp2->add(3);
        tmp1->intersect(tmp2, tmp3);
        QVERIFY(tmp1->find(2));
    }

    void TestUnit()
    {
        tmp2->add(1);
        tmp2->add(2);
        tmp3->add(3);
        tmp3->add(4);
        tmp1->unit(tmp2, tmp3);
        QVERIFY(tmp1->find(1) && tmp1->find(2) && tmp1->find(3) && tmp1->find(4));
    }

    void cleanup()
    {
        delete tmp1;
        delete tmp2;
        delete tmp3;
    }


private:
    Set<int> *tmp1;
    Set<int> *tmp2;
    Set<int> *tmp3;
};
