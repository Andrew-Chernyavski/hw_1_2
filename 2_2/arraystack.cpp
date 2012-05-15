#include "stack.h"
#include "arraystack.h"
#include <iostream>

void ArrayStack::push(int n)
{
    value[++size] = n;
}

int ArrayStack::pop()
{
    return value[size--];
}

void ArrayStack::print()
{
    for(int i = size; i > 0; i--)
    {
        std::cout << value[i] << " ";
    }
    std::cout << "\n";
}
