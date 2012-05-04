#ifndef SORT_H
#define SORT_H
#pragma once

/**
  @class Sort
  сортировщик массива
  */

class Sort
{
public:
    /**
      @brief метод для сортировки массива
      @param mas - собственно массив
      @param n - кол-во эл-тов в нём
      */
    virtual void sorting (int mas[], int n) = 0;
protected:
    /**
      @brief метод для обмена двух значений местами
      @param a - первое из обменивающихся
      @param b - второе из обменивающихся
      */
    void swap (int &a, int &b)
    {
        a+=b;
        b = a - b;
        a = a - b;
    }
};

#endif // SORT_H
