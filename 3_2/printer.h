#ifndef PRINTER_H
#define PRINTER_H
#pragma once
const int n = 5;

/**
  @class Printer
  Базовый класс интерфейса для обхода двумерного массива по спирали с последуюзим выводом на экран/в файл
  */

class Printer
{
public:
    /**
      @brief выводилка
      @param mas массив, которому предстоит раскрутиться по спирали
      @param n кол-во эл-тов в строке/столбце массива
      */
    virtual void print (int mas[][n]) = 0;
};

#endif // PRINTER_H
