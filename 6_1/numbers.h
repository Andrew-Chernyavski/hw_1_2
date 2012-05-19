#pragma once
#include <iostream>
#include "tree.h"

class Numbers : public Tree
{
public:
    Numbers(int n) {value = n;}
    int calculate() {return value;}
    void print() {std::cout << value << ", ";}
private:
    int value;
};

