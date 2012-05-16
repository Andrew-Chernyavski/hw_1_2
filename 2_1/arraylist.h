#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "list.h"

class ArrayList : public List
{
public:
    ArrayList();
    ~ArrayList();
    void add(int value);
    void remove(int value);
    bool isValue(int value);
    int size();
    int getValue(int pos = 0);
private:
    int *mas;
    int length;
    int max;
    static const int upMax = 10;
    void newSize(int len);
};

#endif // ARRAYLIST_H
