#pragma once

class Bag
{
public:
    Bag();
    ~Bag();
    void add(int value);
    void remove(int value);
    bool isValue(int value);
    void print();
    void printdown(Bag *tmp);
private:
    Bag *left;
    Bag *right;
    int value;
    int number;
};
