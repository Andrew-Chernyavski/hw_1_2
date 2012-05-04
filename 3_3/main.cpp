#include <iostream>
#include "sort.h"

using namespace std;

int main()
{
    int mas[n][n];
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                mas[y][x] = ((x + 1) * (x + 1) + (y + 1) * (y + 1)) % 10;
                std::cout << mas[y][x] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";

        Sort *a = new Sort;
        a->sorting(mas);

            for (int x = 0; x < n; x++)
            {
                for (int y = 0; y < n; y++)
                    std::cout << mas[y][x] << " ";
                std::cout << "\n";
            }
            std::cout << "\n";


    return 0;
}

