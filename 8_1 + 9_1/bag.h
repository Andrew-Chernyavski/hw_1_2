#pragma once

/**
  @class Bag
  хранение данных в виде дерева с учётом возможности повторения значений
  */

class Bag
{
public:
    Bag();
    ~Bag();

    /**
          @brief добавление значения
          @param value - добавляемое значение
          */
    void add(int value);

    /**
          @brief удаление значения
          @param value - удаляемое зачение
          */
    void remove(int value);

    /**
          @brief проверка значения на принадлежность
          @param value - проверяемое значение
          */
    bool isValue(int value);

    /**
          @brief обход дерева
          */
    void print();

    /**
          @brief рекурсивный способ обхода дерева
          @param tmp - вершина дерева
          */
    void printdown(Bag *tmp);
private:
    Bag *left;
    Bag *right;
    int value;
    int number;
};
