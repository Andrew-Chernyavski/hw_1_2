#include <QObject>
#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "sort.h"

class sortTest : public QObject
{
    Q_OBJECT
public:
    explicit sortTest(QObject *parent = 0):QObject(parent){}
    
private slots:

    void init()
    {
        a = new Sort;
    }

    void cleanup()
    {
        delete a;
    }

    void testSorting()
    {
        int mas[n][n];
        for (int x = 0; x < n; x++)
            for (int y = 0; y < n; y++)
                mas[y][x] = ((x + 1) * (x + 1) + (y + 1) * (y + 1)) % 10;
        a = new Sort;
        a->sorting(mas);
        for (int i = 1; i < n; i++)
            QVERIFY (mas[i][0] >= mas[i-1][0]);
    }
    
private:
    Sort *a;
};
