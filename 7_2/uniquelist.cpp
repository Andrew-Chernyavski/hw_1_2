#include "indexlist.h"
#include "uniquelist.h"

void UniqueList::add(int value)
{
    if (isValue(value))
        throw WrongAdd();
    else
        IndexList::add(value);
}

void UniqueList::remove(int value)
{
    if (isValue(value))
        IndexList::remove(value);
    else
        throw WrongRemove();
}
