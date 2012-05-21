#pragma once
#include "tree.h"

/**
  @class Operations
  хранение ячеек, содержимое которых - операции (выражения)
  */

class Operations : public Tree
{
public:
    Operations():operation('\0'){}
    /**
    @brief рекурсивный метод для вычисления значения ячейки
    */
    int calculate();
    /**
    @brief рекурсивный метод для обхода дерева
    */
    void print();
    /**
    @brief рекурсивный метод для преобразования строки входных данных в дерево
    @param a - входная строка
    @param n - указатель на элемент строки (необходим для рекурсии)
    */
    void getTree(char a[], int i);

private:
    char operation;

};
