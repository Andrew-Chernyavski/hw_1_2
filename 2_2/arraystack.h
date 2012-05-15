#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#pragma once
#include "stack.h"

class ArrayStack : public Stack
{
public:
    ArrayStack():size(0){}
    ~ArrayStack(){}
    void push(int n);
    int pop();
    void print();
private:
    static const int lim = 1000;
    int value[lim];
    int size;

};

#endif // ARRAYSTACK_H
