#include "comparator.h"

template<class T>
bool Comparator<T>::compare(T a, T b)
{
    bool c = (a > b);
    return c;
}
