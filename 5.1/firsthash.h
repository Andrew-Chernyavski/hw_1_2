#pragma once
#include "basehash.h"

class FirstHash : public BaseHash
{
public:

    /**
    @brief первый способ вычисления хеша строки
    @param ch - первый элемент строки
    @param size - размер хеша
    */
    int hash(char *ch, int size);
};
