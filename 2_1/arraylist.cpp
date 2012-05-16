#include "arraylist.h"

ArrayList::ArrayList() : length(0)
{
    max = upMax;
    mas = new int[max];
}

ArrayList::~ArrayList()
{
    delete[] mas;
}

void ArrayList::newSize(int l)
{
    if (l > max)
    {
        delete[] mas;
        while (l > max)
            max += upMax;
        mas = new int[max];
    }
    length = l;
}

void ArrayList::add(int value)
{
    newSize(++length);
    mas[length - 1] = value;
}

void ArrayList::remove(int value)
{
    int j = 0;
    for (int i = 0; i < length; i++)
    {
        if (mas[i] != value)
            mas[j++] = mas[i];
    }
    length = j;
}

bool ArrayList::isValue(int value)
{
    for (int i = 0; i < length; i++)
    {
        if (mas[i] == value)
            return true;
    }
    return false;
}

int ArrayList::size()
{
    return length;
}

int ArrayList::getValue(int i)
{
    return mas[i];
}
