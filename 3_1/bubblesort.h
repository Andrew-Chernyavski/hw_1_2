#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#pragma once
#include "sort.h"

/**
  @class BubbleSort
  сортировщик массива целочисленных элементов методом "пузырька"
  */

class BubbleSort : public Sort
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
};

#endif // BUBBLESORT_H
