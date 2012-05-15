#include "indexstack.h"
#include "stack.h"
#include <iostream>

void IndexStack::push(int num)
{
    IndexStack *tmp = new IndexStack;
    tmp->value = num;
    tmp->next = next;
    next = tmp;
}

void IndexStack::print()
{
    if (!next)
        std::cout << "stack is empty\n";
    else
    {
        IndexStack *point = this;
        while (point->next)
        {
            point = point->next;
            std::cout << point->value << " ";
        }
        std::cout << "\n";
    }
}

int IndexStack::pop()
{
    if (!next)
    {
        std::cout << "stack is empty\n";
        return 0;
    }
    IndexStack *tmp = next->next;
    int num = next->value;
    delete next;
    next = tmp;
    return num;
}

IndexStack::~IndexStack()
{
    if ((next) && (next->value == 0))
        delete next;
}
