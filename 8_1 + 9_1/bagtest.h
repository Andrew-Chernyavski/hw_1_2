#pragma once
#include <QObject>
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "bag.h"

class bagTest : public QObject
{
    Q_OBJECT
public:
    explicit bagTest(QObject *parent = 0) {}

private slots:

    void init()
    {
        tmp = new Bag;
    }

    void cleanup()
    {
        delete tmp;
    }

    void testAdd()
    {
        tmp->add(4);
        QVERIFY(tmp->isValue(4));
    }

    void testRemove()
    {
        tmp->add(14);
        tmp->add(3);
        tmp->remove(3);
        QVERIFY(!tmp->isValue(3));
    }

private:
    Bag *tmp;
};
