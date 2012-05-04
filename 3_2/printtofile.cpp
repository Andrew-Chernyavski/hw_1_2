#include <iostream>
#include <fstream>
#include "printtofile.h"

void PrintToFile::print(int mas[][n])
{
    FILE *file;
    file = fopen ("output.txt", "w");
    int sz = (n - 1) / 2;
    int x = sz; int y = x;
    fprintf (file, "%d ", mas[x][y]);
    for (int i = sz; i > 0; i--)//и дуги спиралей
    {
        x--;
        fprintf (file, "%d ", mas[x][y]);
        int count = n - 2 * i;
        for (int j = 1; j <= count; j++)//горизонталь вправо
        {
            y++;
            fprintf (file, "%d ", mas[x][y]);
        }
        count++;
        for (int j = 1; j <= count; j++)//горизонталь вправо
        {
            x++;
            fprintf (file, "%d ", mas[x][y]);
        }
        for (int j = 1; j <= count; j++)//горизонталь вправо
        {
            y--;
            fprintf (file, "%d ", mas[x][y]);
        }
        for (int j = 1; j <= count; j++)//горизонталь вправо
        {
            x--;
            fprintf (file, "%d ", mas[x][y]);
        }
    }
    fclose (file);
}

