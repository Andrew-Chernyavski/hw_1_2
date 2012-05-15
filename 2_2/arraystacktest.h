#ifndef ARRAYSTACKTEST_H
#define ARRAYSTACKTEST_H

#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "arraystack.h"

class ArrayStackTest : public QObject
{
    Q_OBJECT
public:
    explicit ArrayStackTest(QObject *parent = 0): QObject(parent) {}

private slots:
    void init()
    {
        tmp = new ArrayStack();
    }

    void cleanup()
    {
        delete tmp;
    }

    void testPopAndPush()
    {
        tmp->push(3);
        //tmp->push(14);
       //QVERIFY(tmp->pop() == 14);
        int n = tmp->pop();
        QVERIFY((n) == 3);
      }

private:
    ArrayStack *tmp;

};

#endif // ARRAYSTACKTEST_H
