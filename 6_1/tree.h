#pragma once

class Tree
{
public:
    Tree():left(0), right(0) {}
    virtual ~Tree() {delete left; delete right;}
    virtual int calculate() = 0;
    virtual void print() = 0;
protected:
    Tree *left;
    Tree *right;
};
