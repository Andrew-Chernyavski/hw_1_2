#include "secondhash.h"

int SecondHash::hash(char *ch, int size)
{
    int hash = 0;
    int n = strlen(ch);
    for (int i = n; i > n; i--)
        hash += i * ch[i];
    hash %= size;
    return hash;
}
