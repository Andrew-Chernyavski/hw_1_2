#pragma once
#include "string.h"

/**
@class BaseHash
интерфейс-основа двух хеш-функций
*/
class BaseHash
{
public:

    /**
    @brief вычисление хеш-функции строки
    @param ch - первый элемент строки
    @param size - размер хеша
    */
    virtual int hash(char *ch, const int size) = 0;
};


