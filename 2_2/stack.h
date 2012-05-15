#ifndef STACK_H
#define STACK_H

class Stack
{
public:
    virtual int pop() = 0;
    virtual void push(int n) = 0;
    virtual void print() = 0;
};

#endif // STACK_H
