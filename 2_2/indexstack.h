#ifndef INDEXSTACK_H
#define INDEXSTACK_H
#pragma once
#include "stack.h"


class IndexStack : public Stack
{
public:
    IndexStack():next(0){}
    ~IndexStack();
    void push(int n);
    int pop();
    void print();
private:
    IndexStack *next;
    int value;
};

#endif // INDEXSTACK_H
