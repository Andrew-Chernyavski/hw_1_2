#include <iostream>
#include "printtoconsole.h"
#include "printtofile.h"
#include "printertest.h"

using namespace std;

int main()
{
    printertest test;
    QTest::qExec(&test);

    /*int mas[n][n];
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            mas[x][y] = ((x+1)*(x+1)+(y+1)*(y+1)) % 10;
            std::cout << mas[x][y] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    Printer *p1 = new PrintToConsole;
    p1->print(mas);

    Printer *p2 = new PrintToFile;
    p2->print(mas);
    std::cout << "\n";

    delete p1;
    delete p2;

*/
    return 0;
}

