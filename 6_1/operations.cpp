#include "operations.h"
#include <iostream>
#include "numbers.h"

int Operations::calculate()
 {
     int a = left->calculate();
     int b = right->calculate();
     //int return 0;

     switch (operation)
     {
     case '+':
         return a + b;
     case '-':
         return a - b;
     case '*':
         return a * b;
     case '/':
         return a / b;
     }

 }
  void Operations::print()
  {
      std::cout << "( " << operation << " ";
      left->print();
      right->print();
      std::cout << ") ";
  }

  void Operations::getTree(char s[], int i)
  {
      i++;
      operation = s[i];
      i++;
      Operations *tmp;
      if (s[i] == '(')
      {
          tmp = new Operations();
          tmp->getTree(s, i);
          left = tmp;
          i++;
      }
      else
      {
          int num = s[i] - '0';
          left = new Numbers(num);
      }
      i++;

      if (s[i] == '(')
      {
          tmp = new Operations();
          tmp->getTree(s, i);
          right = tmp;
          i++;
      }
      else
      {
          int num = s[i] - '0';
          right = new Numbers(num);
      }
      i++;
  }
