#include <iostream>
#include "printtoconsole.h"

void PrintToConsole::print(int mas[][n])
{
    int sz = (n - 1) / 2;
    int x = sz; int y = x;
    std::cout << mas[x][y] << " ";
    for (int i = sz; i > 0; i--)
    {
        x--;
        std::cout << mas[x][y] << " ";
        int count = n - 2 * i;
        for (int j = 1; j <= count; j++)
        {
            y++;
            std::cout << mas[x][y] << " ";
        }
        count++;
        for (int j = 1; j <= count; j++)
        {
            x++;
            std::cout << mas[x][y] << " ";
        }
        for (int j = 1; j <= count; j++)
        {
            y--;
            std::cout << mas[x][y] << " ";
        }
        for (int j = 1; j <= count; j++)
        {
            x--;
            std::cout << mas[x][y] << " ";
        }
    }
}

