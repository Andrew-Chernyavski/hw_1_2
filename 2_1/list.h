#ifndef LIST_H
#define LIST_H

class List
{
public:
    virtual ~List() {}
    virtual void add(int val) = 0;
    virtual void remove(int val) = 0;
    virtual bool isValue(int val) = 0;
    virtual int size() = 0;
    virtual int getValue(int pos = 0) = 0;
};

#endif // LIST_H
