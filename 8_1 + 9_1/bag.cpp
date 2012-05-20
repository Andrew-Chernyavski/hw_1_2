#include <iostream>
#include "bag.h"

Bag::Bag()
{
    left = NULL;
    right = NULL;
    value = 0;
    number = 0;
}

Bag::~Bag()
{
    delete left;
    delete right;
}

void Bag::add(int value)
{
    bool flag = true;
    Bag *tmp = this;
    while (flag)
    {
        if (tmp->value == value)
        {
            tmp->number++;
            flag = false;
        }
        else
        {
            if (tmp->value < value)
            {
                if (tmp->left != NULL)
                    tmp = tmp->left;
                else
                {
                    Bag *node = new Bag;
                    tmp->left = node;
                    node->value = value;
                    node->number = 1;
                    node->left = NULL;
                    node->right = NULL;
                    flag = false;
                }
            }
            else
            {
                if (tmp->right != NULL)
                    tmp = tmp->right;
                else
                {
                    Bag *node = new Bag;
                    tmp->right = node;
                    node->value = value;
                    node->number = 1;
                    node->left = NULL;
                    node->right = NULL;
                    flag = false;
                }
            }
        }
    }
}

bool Bag::isValue(int value)
{
    Bag *tmp = this;
    do
    {
        if ((tmp->value == value) && (tmp->number > 0))
            return true;
        else
        {
            if (tmp->value < value)
            {
                if (tmp->left)
                    tmp = tmp->left;
                else
                    return false;
            }
            else
            {
                if (tmp->right)
                    tmp = tmp->right;
                else
                    return false;
            }
        }
    }
    while (tmp->value != value);
    if (tmp->number == 0)
        return false;
}

void Bag::remove(int value)
{
    if (isValue(value))
    {
        Bag *tmp = this;
        Bag *pred = this;
        bool left = false;
        while (tmp->value != value)
        {
            if (tmp->value < value)
            {
                pred = tmp;
                tmp = tmp->left;
                left = true;
            }
            else
            {
                pred = tmp;
                tmp = tmp->right;
                left = false;
            }
        }
        tmp->number--;
    }
}

void Bag::print()
{
    Bag *tmp = this;
    printdown(tmp);
    std::cout << "\n";
}

void Bag::printdown(Bag *tmp)
{
    if (tmp->right)
        if (tmp->right->right)
            printdown (tmp->right);
        else
            if (tmp->right->number > 0)
            {
                std::cout << tmp->right->value << ", " << tmp->right->number << " time(s)\n";
            }
    if (tmp->number > 0)
        std::cout << tmp->value << ", " << tmp->number << " time(s)\n";
    if (tmp->left)
        if (tmp->left->left)
            printdown(tmp->left);
        else
            if (tmp->left->number)
            {
                std::cout << tmp->left->value << ", " << tmp->left->number << " time(s)\n";
            }
}
