#pragma once
#include "tree.h"

class Operations : public Tree
{
public:
    Operations():operation('\0'){}
    int calculate();
    void print();
    void getTree(char a[], int i);

private:
    char operation;

};
