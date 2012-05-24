#pragma once

/**
  @class Vector
  хранение многомерного множества с данными шаблонного типа
  */
template <typename T, int SIZE>
class Vector
{
public:
    Vector() {for (int i = 0; i < SIZE; i++) vect[i] = 0;}

    /**
    @brief конструктор копирования
    @param T -  тип добавляемого элемента
    @param SIZE - размерность
    @param a - "оригигинал"
    */
    Vector(Vector<T, SIZE> const &vector)
    {
        for (int i = 0; i < SIZE; i++)
            vect[i] = vector.vect[i];
    }

    /**
    @brief алгебраическое сложение векторов
    @param T -  тип добавляемого элемента
    @param SIZE - размерность
    @param vector1 - первое слагаемое
    @param vector2 - второе слагаемое
    @param c - знак действия
    */
    void algebrAdd(Vector<T, SIZE> *vector1, Vector<T, SIZE> *vector2, char c)
    {
        switch (c)
        {
        case '+':
            for (int i = 0; i < SIZE; i++)
                vect[i] = vector1->vect[i] + vector2->vect[i];
            break;
        case '-':
            for (int i = 0; i < SIZE; i++)
                vect[i] = vector1->vect[i] - vector2->vect[i];
            break;
        }
    }

    /**
      @brief скаляное произведение
      @param vector1 - первый вектор
      @param vector2 - второй вектор
      */
    T scalarProd(Vector<T, SIZE> *vector1, Vector<T, SIZE> *vector2)
    {
        T result = 0;
        for (int i = 0; i < SIZE; i++)
            result += vector1->vect[i] * vector2->vect[i];
        return result;
    }

    /**
      @brief нулеой вектор?
      */
    bool zeroVector()
    {
        for (int i = 0; i < SIZE; i++)
            if (vect[i] != 0)
                return false;
        return true;
    }

    T vect[SIZE];
};
