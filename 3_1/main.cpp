#include <iostream>
#include <fstream>
#include "bubblesort.h"
#include "quicksort.h"

const int n = 14;

void print (int a[])
{
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << "\n";
}

int main()
{
    int a[n]; int b[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = (n - i);
        b[i] = a[i];
    }
    std::cout << "initial array: ";
    print (a);
    std::cout << "\nafter bubblesort: ";
    Sort *s = new BubbleSort;
    s->sorting (a, n);
    print(a);
    std::cout << "\n";
    std::cout << "initial array: ";
    print (b);
    std::cout << "\nafter quicksort: ";
    Sort *q = new QuickSort;
    q->sorting(b,n);
    print(b);
    delete b;
    delete s;
    return 0;
}

