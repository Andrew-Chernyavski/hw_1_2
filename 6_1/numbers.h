#pragma once
#include <iostream>
#include "tree.h"

/**
  @class Operations
  хранение ячеек, содержимое которых - числа
  */

class Numbers : public Tree
{
public:
    Numbers(int n) {value = n;}

    /**
    @brief вычисление значения ячейки - тупо возвращается значение из value
    */
    int calculate() {return value;}

    /**
    @brief вычисление содержимого ячейки
    */
    void print() {std::cout << value << ", ";}
private:

    /**
    @param value - собственно значение числовой ячейки
    */
    int value;
};

