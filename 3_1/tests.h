#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include <iostream>
#include <fstream>
#include "bubblesort.h"
#include "quicksort.h"

#include <QObject>

class tests : public QObject
{
    Q_OBJECT
public:
    explicit tests(QObject *parent = 0);
    
private slots:

    void testOfSorters()
    {
        int n = 14;
        int a[n]; int b[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = (n - i);
            b[i] = a[i] * a[i];
        }
        Sort *s = new BubbleSort;
        s->sorting(a, n);
        Sort *q = new QuickSort;
        q->sorting(b,n);
        for (int i = 1; i < n; i++)
        {
            QVERIFY (a[i] >= a[i-1]);
            QVERIFY (b[i] >= b[i-1]);
        }
        delete s;
        delete q;
    }
    
};

