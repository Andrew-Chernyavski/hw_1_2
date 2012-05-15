#pragma once
#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "printtofile.h"
#include "strings.h"

class printertest : public QObject
{
    Q_OBJECT
public:
    explicit printertest(QObject *parent = 0):QObject(parent){}

private slots:

    void init()
    {
        a = new PrintToFile();
    }

    void cleanup()
    {
        delete a;
    }

    void testPrinting()
    {
        int mas[3][3];
        for (int i = 0; i < 3; i++)     //0 1 2
            for (int j = 0; j < 3; j++) //1 2 3
                mas[i][j] = i+j;        //2 3 4
        a->print(mas);
        char str1[18] = {'2',' ','1',' ','2',' ','3',' ','4',' ','3',' ','2',' ','1',' ','0',' '};

        FILE *file = fopen ("output.txt", "r");
        char str2[18];
        fgets (str2, 18, file);
        str2[17] = ' ';
        bool a = true;
        for (int i = 0; i < 18; i++)
            if (str1[i] != str2[i])
                a = false;
        QVERIFY(a);
        fclose(file);
    }
    
private:
    Printer *a;
};
