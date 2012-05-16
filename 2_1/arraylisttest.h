#ifndef ARRAYLISTTEST_H
#define ARRAYLISTTEST_H

#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "arraylist.h"

class ArrayListTest : public QObject
{
    Q_OBJECT
public:
    explicit ArrayListTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
     {
         tmp = new ArrayList();
     }

     void cleanup()
     {
         delete tmp;
     }

     void testAdd()
     {
         tmp->add(14);
         QVERIFY(tmp->isValue(14));
     }
     void testRemove()
     {
         tmp->add(3);
         tmp->add(14);
         tmp->remove(14);
         QVERIFY(tmp->isValue(14) == false);
     }
     void testIsValue()
     {
         QVERIFY(tmp->isValue(14) == false);
         tmp->add(14);
         QVERIFY(tmp->isValue(14) == true);
         tmp->remove(14);
         QVERIFY(tmp->isValue(14) == false);
     }

     void testSize()
     {
         tmp->add(3);
         tmp->add(14);
         QVERIFY(tmp->size() == 2);
     }
    
private:
    ArrayList *tmp;
};

#endif // ARRAYLISTTEST_H
