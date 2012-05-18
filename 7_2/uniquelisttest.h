#pragma once

#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "UniqueList.h"
#include <QObject>

class UniqueListTest : public QObject
{
    Q_OBJECT
public:
    explicit UniqueListTest(QObject *parent = 0):QObject(parent){}

private slots:

    void init()
    {
        tmp = new UniqueList;
    }

    void testAdd()
    {
        tmp->add(14);
        QVERIFY (tmp->isValue(14));
    }

    void testWrongAdd()
    {
        bool catched = false;
        tmp->add(14);
        try
        {
            tmp->add(14);
        }
        catch (UniqueList::WrongAdd)
        {
            catched = true;
        }
        QVERIFY(catched);
    }

    void testRemove()
    {
        tmp->add(3);
        tmp->remove(3);
        QVERIFY (!tmp->isValue(3));
    }

    void testWrongRemove()
    {
        bool catched = false;
        try
        {
            tmp->remove(14);
        }
        catch (UniqueList::WrongRemove)
        {
            catched = true;
        }
        QVERIFY(catched);
    }

    void cleanup()
    {
        delete tmp;
    }

private:
    UniqueList *tmp;
    
};
