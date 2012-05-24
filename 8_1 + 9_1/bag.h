#pragma once
#include "limits.h"
#include <iostream>

/**
  @class Bag
  хранение данных в виде дерева с учётом возможности повторения значений
  */

class Bag
{
public:
    Bag();
    ~Bag() {delete left; delete right;}

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
          @brief вывод дерева
          */
    void print() {Bag *tmp = this; printdown(tmp); std::cout << "\n";}

    /**
          @brief рекурсивный способ обхода дерева
          @param tmp - вершина дерева
          */
    void printdown(Bag *tmp);

    class Iterator
        {
        public:
            Iterator() {tmp = NULL; head = NULL; currentnumber = 0;}
            Iterator(Bag *tmp, Bag *head1);
            int returnValue() { if (tmp != NULL) return tmp->value; else return INT_MIN;}
            int returnnumber() { if (tmp != NULL) return tmp->number; else return INT_MIN;}
            Bag* returnBag(){return tmp;}
            void sum();
            bool equal(Iterator *tmp);
        private:
            Bag *tmp;
            Bag *head;
            int currentnumber;
            void iter(Bag *tmp, int value);
            int next;
            Bag* rem;
        };
    Iterator goOn();
    Iterator laster();

private:
    Bag *left;
    Bag *right;
    int value;
    int number;
    Bag *head;
};
