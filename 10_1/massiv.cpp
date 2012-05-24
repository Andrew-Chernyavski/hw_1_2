#include "massiv.h"

Massiv::Massiv()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            mas[i][j] = 0;
    lastCross = true;
}

int Massiv::click(int a, int b)
{
    if (mas[a][b] == 0)
    {
        lastCross = !lastCross;
        if (lastCross)
        {
            mas[a][b] = 2;//ставить нолик
            return 2;
        }
        else
        {
            mas[a][b] = 1;//ставить крестик
            return 1;
        }
    }
    else
        return 0;
}
bool Massiv::victory(int a, int b)
{
    int com = mas[a][b];
    bool horiz = true;
    bool vertic = true;

    for (int i = 0; i < 3; i++)
        horiz = horiz && com == mas[i][b];
    for (int i = 0; i < 3; i++)
        vertic = vertic && com == mas[a][i];

    bool diag1 = true;
    bool diag2 = true;
    for (int i = 0; i < 3; i++)
    {
        diag1 = diag1 && com == mas[i][i];
        diag2 = diag2 && com == mas[2 - i][i];
    }
    return horiz || vertic ||diag1 || diag2;
}
