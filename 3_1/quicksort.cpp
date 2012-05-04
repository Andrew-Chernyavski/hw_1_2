#include <fstream>
#include <iostream>
#include "sort.h"
#include "quicksort.h"

void QuickSort::sorting(int mas[], int n)
{
    {
        QuickSort::qsorting (mas, 0, n-1);
    }
}

void QuickSort::qsorting(int mas[], int l, int r)
{
    if(l < r)
        {
            int point = mas[l];
            int i = l;
            int j = r;
            while(i < j)
            {
                while(mas[i] <= point && i < r)
                    i++;
                while(mas[j] >= point && j > l)
                    j--;
                if(i < j)
                {
                    Sort::swap (mas[i], mas[j]);
                }
            }
            int temp = mas[l];
            mas[l] = mas[j];
            mas[j] = temp;
            qsorting(mas, l, j - 1);
            qsorting(mas, j + 1, r);
        }
}
