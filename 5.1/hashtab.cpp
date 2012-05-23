#include "hashtab.h"
#include "firsthash.h"
#include <iostream>

HashTab::HashTab()
{
    size = 100;
    tab1 = new Node *[size];
    for (int i = 0; i < size; i++)
        tab1[i] = NULL;
    hashFunction = new FirstHash;
}

HashTab::~HashTab()
{
    for (int i = 0; i < size; i++)
    {
        while (tab1[i])
        {
            Node *tmp = tab1[i];
            tab1[i] = tab1[i]->next;
            delete tmp;
        }
    }
    delete[] tab1;
    delete hashFunction;
}

void HashTab::add(char *s)
{
    int h = hashFunction->hash(s, size);
    Node *tmp = new Node;
    strcpy(tmp->str, s);
    tmp->next = tab1[h];
    tab1[h] = tmp;
}

void HashTab::remove(char *s)
{
    int h = hashFunction->hash(s, size);
    if (!tab1[h])
        if (strcmp(tab1[h]->str, s) == 0)
        {
            Node *tmp = tab1[h];
            tab1[h] = tab1[h]->next;
            delete tmp;
        }
        else
        {
            Node *tmp = tab1[h];
            while (strcmp(tmp->next->str, s) != 0 && tmp->next != NULL)
            {
               tmp = tmp->next;
            }
            if (tmp->next != NULL)
            {
               Node *tmp2 = tmp->next;
               tmp->next = tmp2->next;
               delete tmp2;
            }
        }
}

void HashTab::changeHash(BaseHash *func)
{
    hashFunction = func;
    reboot();
}

void HashTab::reboot()
{
    tab2 = new Node *[size];
    for (int i = 0; i < size; i++)
        tab2[i] = NULL;

    Node **tmp;
    tmp = tab1;
    tab1 = tab2;
    tab2 = tmp;

    for (int i = 0; i < size; i++)
    {
        if (tab2[i])
        {
            while (tab2[i])
            {
                add(tab2[i]->str);
                Node *tmp = tab2[i];
                tab2[i] = tab2[i]->next;
                delete tmp;
            }
        }
    }
    delete[] tab2;
}

bool HashTab::isString(char *s)
{
    int h = hashFunction->hash(s, size);
    if (!tab1[h])
        return false;
    else
    {
        Node *tmp = tab1[h];
        while ((strcmp(tmp->str, s) != 0) && (tmp->next))
            tmp = tmp->next;
        if (strcmp(tmp->str, s) == 0)
            return true;
        else
            return false;
    }
}

int HashTab::sizeOfHash()
{
    return size;
}

void HashTab::showStatistics()
{
    double k = 0;
    conflictMax = 0;
    numberOfConflicts = 0;
    for (int i = 0; i < size; i++)
    {
        int tmp1 = 0;
        if (tab1[i] != NULL)
        {
            Node *tmp = tab1[i];
            k++;
            tmp1++;
            if (tmp->next != NULL)
                numberOfConflicts++;
            while(tmp->next != NULL)
            {
                tmp = tmp->next;
                k++;
                tmp1++;
            }
        }
        if (conflictMax < tmp1)
            conflictMax = tmp1;
    }
    loadFactor = k / size;

    std::cout << "size: " << size << "\n";
    std::cout << "load factor: " << loadFactor << "\n";
    std::cout << "number of conflicts: " << numberOfConflicts << "\n";
    std::cout << "max size of conflicts: " << conflictMax << "\n";

}
