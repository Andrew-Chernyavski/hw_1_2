#ifndef INDEXSTACKTEST_H
#define INDEXSTACKTEST_H

#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "indexstack.h"

class IndexStackTest : public QObject
{
    Q_OBJECT
public:
    explicit IndexStackTest(QObject *parent = 0): QObject(parent) {}
    
private slots:

    void init()
    {
        tmp = new IndexStack();
    }

    void cleanup()
    {
        delete tmp;
    }

    void testPopAndPush()
    {
        tmp->push(3);
        tmp->push(14);
        QVERIFY(tmp->pop() == 14);
        QVERIFY(tmp->pop() == 3);
    }

private:
    IndexStack *tmp;
    
};

#endif // INDEXSTACKTEST_H
