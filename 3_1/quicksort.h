#ifndef QUICKSORT_H
#define QUICKSORT_H
#pragma once
#include "sort.h"

/**
  @class QuickSort
  сортировщик массива целочисленных элементов быстрым методом
  */

class QuickSort : public Sort
{
public:
    /**
      @brief метод для сортировки массива
      @param mas - собственно массив
      @param n - кол-во эл-тов в нём
      */
    void sorting (int mas[], int n);
protected:
    /**
      @brief метод для обмена двух значений местами
      @param a - первое из обменивающихся
      @param b - второе из обменивающихся
      */
    void swap(int &a, int &b);
private:
    /**
      @brief рекурсивная функция, сортирующая массив в указанных границах
      @param mas - собственно сортируемый массив
      @param l - левая граница сортировки
      @param r - правая граница сортировки
      */
    void qsorting (int mas[], int l, int r);
};

#endif // QUICKSORT_H
