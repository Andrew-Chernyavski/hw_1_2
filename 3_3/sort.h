#ifndef SORT_H
#define SORT_H
#pragma once

const int n = 5;

/**
  @class Sort
  —ортировщик строк двумерного массива (матрицы) по их первым элементам
  */

class Sort
{
public:
    /**
      @brief собственно сортировка строк этого массива по первым элементам
      @param mas сортируемый массив
      @param n длина строки (столбца) сортируемого массива
      */
    void sorting (int mas[n][n]);
private:
    /**
      @brief метод, мен€ющий местами две строки матрицы, т.е. два массива
      @param a[] перва€ из обменивающихс€ строк
      @param b[] втора€ из обменивающихс€ строк
      */
    void swap (int a[], int b[]);
};

#endif // SORT_H
