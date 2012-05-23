#include <QObject>
#include <QtCore/QtCore>
#include <QtTest/QtTest>

#include "firsthash.h"
#include "secondhash.h"
#include "hashtab.h"

class HashTest : public QObject
{
    Q_OBJECT
public:
    explicit HashTest(QObject *parent = 0): QObject(parent){}

private slots:

    void init()
    {
        f1 = new FirstHash;
        f2 = new SecondHash;
        t = new HashTab;
    }

    void cleanup()
    {
        delete f1;
        delete f2;
        delete t;
    }

    void testAdd()
    {
        char s[100] = "testing";
        t->add(s);
        QVERIFY(t->isString(s));
    }

    void testRemove()
    {
        char s[100] = "testing";
        t->add(s);
        t->remove(s);
        QVERIFY(t->isString(s));
    }


    
private:
BaseHash *f1;
BaseHash *f2;
HashTab *t;
};
