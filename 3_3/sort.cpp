#include "sort.h"

void Sort::sorting(int mas[n][n])
{
    bool t = true;
        while (t)
        {
            t = false;
            for (int i = 0; i < (n-1); i++)
                if (mas[i][0] > mas[i+1][0])
                {
                    t = true;
                    Sort::swap (mas[i], mas[i+1]);
                }
        }
}

void Sort::swap (int a[], int b[])
{
    int c[n];
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i];
        a[i] = b[i];
        b[i] = c[i];
    }
}
