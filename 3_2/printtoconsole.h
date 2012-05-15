#ifndef PRINTTOCONSOLE_H
#define PRINTTOCONSOLE_H
#include "printer.h"
#pragma once

/**
  @class PrintToConsole
  требуется для вывода двумерного массива по спирали на консоль
  */

class PrintToConsole : public Printer
{
public:
    /**
      @brief выводилка
      @param mas массив, которому предстоит раскрутиться по спирали
      @param n кол-во эл-тов в строке/столбце массива
      */
    void print (int mas[][n]);
};

#endif // PRINTTOCONSOLE_H
