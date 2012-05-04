#include "bubblesort.h"

void BubbleSort::sorting(int mas[], int n)
{
    bool t = true;
    while (t)
    {
        t = false;
        for (int i = 0; i < (n-1); i++)
            if (mas[i] > mas[i+1])
            {
                t = true;
                Sort::swap (mas[i], mas[i+1]);
            }
    }
}
