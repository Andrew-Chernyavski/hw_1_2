#ifndef INDEXLISTTEST_H
#define INDEXLISTTEST_H

#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "indexlist.h"

class IndexListTest : public QObject
{
    Q_OBJECT
public:
    explicit IndexListTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
     {
         tmp = new IndexList();
     }

    void cleanup()
     {
         delete tmp;
     }

    void testAdd()
    {
        tmp->add(14);
        QVERIFY (tmp->isValue(14));
    }

    void removeTest()
    {
        tmp->add(14);
        tmp->add(25);
        tmp->remove(25);
        QVERIFY (tmp->isValue(25) == false);
    }

    void testSize()
    {
        QVERIFY(tmp->size() == 0);
        tmp->add(14);
        tmp->add(25);
        QVERIFY (tmp->size() == 2);
    }


    void testIsValue()
      {
          QVERIFY(tmp->isValue(3) == false);
          tmp->add(3);
          tmp->add(14);
          QVERIFY(tmp->isValue(14) == true);
          tmp->remove(3);
          QVERIFY(tmp->isValue(3) == false);
      }

private:
  IndexList *tmp;
};

#endif // INDEXLISTTEST_H
