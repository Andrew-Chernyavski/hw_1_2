#pragma once
#include "indexlist.h"

class UniqueList : public IndexList
{
public:
    void add(int value);
    void remove(int value);
    class WrongAdd {};
    class WrongRemove {};
};
