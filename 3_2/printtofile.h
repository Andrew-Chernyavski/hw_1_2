#ifndef PRINTTOFILE_H
#define PRINTTOFILE_H
#include "printer.h"
#pragma once

/**
  @class PrintToFile
  требуется для вывода двумерного массива по спирали в output.txt
  */

class PrintToFile : public Printer
{
public:
    /**
      @brief выводилка
      @param mas массив, которому предстоит раскрутиться по спирали
      @param n кол-во эл-тов в строке/столбце массива
      */
    void print (int mas[][n]);
};

#endif // PRINTTOFILE_H
