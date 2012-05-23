#include <iostream>
#include "basehash.h"
#include "firsthash.h"
#include "hashtab.h"
#include "secondhash.h"
#include "hashtest.h"

using namespace std;

int main()
{
    HashTest test;
    QTest::qExec(&test);

    /*HashTab *t = new HashTab;
    BaseHash *f1 = new FirstHash;
    BaseHash *f2 = new SecondHash;
    int com = -1;
    char s[100];
    std::cout << "0 - Exit\n";
    std::cout << "1 - Add string\n";
    std::cout << "2 - Del string\n";
    std::cout << "3 - Search string\n";
    std::cout << "4 - Show stats\n";
    std::cout << "5 - Select hash-function\n";

    while(com != 0)
        {
            std::cout << "input next command\n";
            std::cin >> com;

            switch (com)
            {
            case 1:
            {
                std::cout << "Input the string: ";
                fgets(s, 200, stdin);
                t->add(s);
                std::cout << "\n";
                break;
            }
            case 2:
            {
                std::cout << "Input the string: ";
                fgets(s, 200, stdin);
                t->remove(s);
                std::cout << "\n";
                break;
            }
            case 3:
            {
                std::cout << "Input the string: ";
                fgets(s, 200, stdin);
                if(t->isString(s))
                    std::cout << "Line is in the table";
                else
                    std::cout << "No line in the table";
                std::cout << "\n";
                break;
            }
            case 4:
            {
                t->showStatistics();
            }
            case 5:
            {
                std::cout << "Choose the hash-function (1 or 2): ";
                int c = -1;
                cin >> c;
                if (c == 1)
                    t->changeHash(f1);
                else if (c == 2)
                    t->changeHash(f2);
            }
            }
    }

        delete t;*/
        return 0;

}

