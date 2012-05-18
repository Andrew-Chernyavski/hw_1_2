#pragma once
#include "comparator.h"

template <typename T>
class Set
{
public:
    Set() : value(0), next(NULL), head(NULL), tmpGlobal(NULL) {}
    ~Set();
    void add(T);
    void sorting();
private:
    T value;
    Set *next;
    Set *head;
    Set *end;
    Set *tmpGlobal;
};

template <typename T>
Set<T>::~Set()
{
    while (head != NULL)
    {
        Set *tmp = head;
        head = head->next;
        delete tmp;
    }
}

template <typename T>
void Set<T>::add(T x)
{
    Set *tmp = new Set;
    tmp->next = NULL;
    tmp->value = x;
    if (head == NULL)
    {
        head = tmp;
        tmpGlobal = head;
    }
    else
        end->next = tmp;
    end = tmp;
}

template <typename T>
void Set<T>::sorting()
{
    Set *tmp1 = this;
    Set *tmp2 = this->next;
    while (tmp1)
    {
        while (tmp2)
        {
            Comparator <T> *c = new Comparator <T>;
            bool f = c->compare(tmp1->value, tmp2->value);
            if (f)
                swap (tmp1->value, tmp2->value);
            tmp2 = tmp2->next;
        }
        tmp1 = tmp1->next;
    }
}

template <typename T>
void swap (T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}
