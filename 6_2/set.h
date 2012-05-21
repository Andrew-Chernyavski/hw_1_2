#pragma once

/**
  @class Set
  хранение множества с данными шаблонного типа
  */

template <typename T>
class Set
{
public:
    Set() : value(0), next(NULL), head(NULL), tmpGlobal(NULL) {}
    ~Set();

    /**
    @brief для добавления эл-та в множество
    @param T добавляемый элемент (тип)
    */
    void add(T);

    /**
    @brief для удаления эл-та из множества
    @param T удаляемый элемент (тип)
    */
    void del(T);

    /**
    @brief является ли множество пустым
    */
    bool isEmpty();

    /**
    @brief для поиска элемента в множестве
    @param T разыскиваемый элемент (тип)
    */
    bool find(T);

    /**
    @brief для пересечение множеств
    @param a одно из пересекаемых множеств
    @param b одно из пересекаемых множеств
    */
    void intersect(Set<T> *a, Set<T> *b);

    /**
    @brief для объединение множеств
    @param a одно из объединяемых множеств
    @param b одно из объединяемых множеств
    */
    void unit(Set<T> *a, Set<T> *b);
private:
    bool goToNext();
    T getValue();
    T value;
    Set *next;
    Set *head;
    Set *end;
    Set *tmpGlobal;
};

template <typename T>
Set<T>::~Set()
{
    while (head != NULL)
    {
        Set *tmp = head;
        head = head->next;
        delete tmp;
    }
}

template <typename T>
bool Set<T>::isEmpty()
{
    return head == NULL;
}

template <typename T>
void Set<T>::add(T x)
{
    Set *tmp = new Set;
    tmp->next = NULL;
    tmp->value = x;
    if (head == NULL)
    {
        head = tmp;
        tmpGlobal = head;
    }
    else
        end->next = tmp;
    end = tmp;
}

template <typename T>
void Set<T>::del(T x)
{
    Set *tmp = head;
    if(tmp->value == x)
    {
        if (tmpGlobal == head)
        {
            head = tmp->next;
            tmpGlobal = head;
        }
        else
            head = tmp->next;
        delete tmp;
    }

    while(tmp->next != NULL)
    {
        if (tmp->next->value == x)
        {
            if (tmpGlobal == tmp->next)
                tmpGlobal = head;
            Set *tmp2 = tmp->next;
            tmp = tmp2->next;
            delete tmp2;
        }
        tmp = tmp->next;
    }
}

template <typename T>
bool Set<T>::find(T x)
{
    Set *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value == x)
            return true;
        tmp = tmp->next;
    }
    return false;
}

template <typename T>
void Set<T>::intersect(Set<T> *a, Set<T> *b)
{
    while (a->goToNext())
        if (b->find(a->getValue()))
            add(a->getValue());
}

template <typename T>
void Set<T>::unit(Set<T> *a, Set<T> *b)
{
    while (a->goToNext());
        add(a->getValue());
    while (b->goToNext());
        if(!find(b->getValue()))
            add(b->getValue());
}

template <typename T>
bool Set<T>::goToNext()
{
    if (tmpGlobal->next == NULL)
    {
        tmpGlobal = head;
        return false;
    }
    else
    {
        tmpGlobal = tmpGlobal->next;
        return true;
    }
}

template <typename T>
T Set<T>::getValue()
{
    return tmpGlobal->value;
}
