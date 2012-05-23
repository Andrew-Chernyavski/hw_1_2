#pragma once
#include "basehash.h"

class SecondHash : public BaseHash
{
public:

    /**
    @brief второй способ вычисления хеша строки
    @param ch - первый элемент строки
    @param size - размер хеша
    */
    int hash(char *ch, int size);
};

