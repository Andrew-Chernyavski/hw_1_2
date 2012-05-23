#pragma once
#include "firsthash.h"
#include "secondhash.h"
#include "hashtab.h"

class HashTab
{
public:
    HashTab();
    ~HashTab();

    /**
    @brief добавление строки в хеш
    @param s - входная строка (первый эл-т)
    */
    void add(char *s);

    /**
    @brief удаление строки из хеша
    @param s - входная строка (первый эл-т)
    */
    void remove(char *s);

    /**
    @brief смена хеша с перестройкой таблицы
    @param func - сменяемая ф-ция
    */
    void changeHash(BaseHash *func);

    /**
    @brief перестройка таблицы
    */
    void reboot();

    /**
    @brief наличие строки в хеше
    @param s - входная строка (первый эл-т)
    */
    bool isString(char *s);

    /**
    @brief количество ячеек в хеше
    */
    int sizeOfHash();


    /**
    @brief вывод статистики
    */
    void showStatistics();

    /**
    @brief load factor таблицы
    */
    float loadFactor;

    /**
    @brief число конфликтов
    */
    int numberOfConflicts;

    /**
    @brief максимальная длина списка в конфликтных ячейках
    */
    int conflictMax;



private:
    //элемент списка значений
    struct Node
    {
        char str[50];
        Node *next;
    };
    //размер таблицы
    int size;

    Node **tab1;
    Node **tab2;
    BaseHash *hashFunction;
};

