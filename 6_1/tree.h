#pragma once

/**
  @class Tree
  интерфейс формы хранения данных - дерева
  */

class Tree
{
public:
    Tree():left(0), right(0) {}
    virtual ~Tree() {delete left; delete right;}
    /**
    @brief рекурсивный метод для вычисления значения ячейки
    */
    virtual int calculate() = 0;
    /**
    @brief метод для обхода дерева
    */
    virtual void print() = 0;
protected:
    Tree *left;
    Tree *right;
};
