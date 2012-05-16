#include "indexlist.h"
#include <stdio.h>

IndexList::IndexList() : next(0), value(0)
{
}

IndexList::~IndexList()
{
    delete next;
}

void IndexList::add(int value)
{
    IndexList *tmp = this;

    while (tmp->next)
        tmp = tmp->next;

    IndexList *tmp1 = new IndexList();
    tmp1->value = value;
    tmp1->next = 0;
    tmp->next = tmp1;
}

void IndexList::remove(int value)
{
    IndexList *next = next;
    IndexList *prev = this;
    while(next)
    {
        if (next->value == value)
        {
            prev->next = next->next;
            next->next = 0;
            delete next;
            next = prev;
        }
        prev = next;
        next = next->next;
    }

}

bool IndexList::isValue(int value)
{
    IndexList *tmp = next;
    while (tmp)
    {
        if (tmp->value == value)
            return true;
        tmp = tmp->next;
    }
    return false;
}

int IndexList::size()
{
    int size = 0;
    IndexList *tmp = next;
    while (tmp)
    {
        size++;
        tmp = tmp->next;
    }
    return size;
}

int IndexList::getValue(int i)
{
    int j = 0;
    IndexList *tmp = this;
    while (tmp && j < i)
    {
        j++;
        tmp = tmp->next;
    }
    if (tmp)
        return tmp->value;
    else
        return -1;
}
