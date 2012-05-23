#include "firsthash.h"

int FirstHash::hash(char *ch, int size)
{
    int hash = 0;
    int n = strlen(ch);
    for (int i = 0; i < n; i++)
        hash += i * ch[i];
    hash %= size;
    return hash;
}
