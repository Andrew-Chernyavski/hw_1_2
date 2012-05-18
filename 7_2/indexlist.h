#ifndef INDEXLIST_H
#define INDEXLIST_H

#include "list.h"

class IndexList : public List
{
public:
    IndexList();
    ~IndexList();
    void add(int value);
    void remove(int value);
    bool isValue(int value);
    int size();
    int getValue(int pos = 0);
private:
    IndexList *next;
    int value;
};

#endif // INDEXLIST_H
