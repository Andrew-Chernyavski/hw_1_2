#include <iostream>
#include "bag.h"

Bag::Bag()
{
    left = NULL;
    right = NULL;
    value = 0;
    number = 0;
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

Bag::Iterator::Iterator(Bag *tmp1, Bag *head1)
{
    tmp = tmp1;
    head = head1;
    if (tmp1 != NULL)
        currentnumber = tmp->number;
    else
        currentnumber = 0;
}

void Bag::Iterator::iter(Bag *tmp, int value)
{
    if (tmp != NULL)
    {
        if (tmp->left == NULL && tmp->right == NULL)
            if (tmp->value > value && tmp->value < next)
            {
                next = tmp->value;
                rem = tmp;
            }
        else
        {
            iter(tmp->left, value);
            if (tmp->value > value && tmp->value < next)
            {
                next = tmp->value;
                rem = tmp;
            }
            iter(tmp->right, value);
        }

    }
}


void Bag::Iterator::sum()
{
    if(currentnumber > 1)
        currentnumber--;
    else
    {
        Bag *tmp = head->left;
        next = INT_MAX;
        rem = NULL;
        iter(tmp, tmp->value);
        if (rem == NULL)
            tmp = NULL;
        else
        {
            tmp = rem;
            currentnumber = tmp->number;
        }
    }


}


bool Bag::Iterator::equal(Iterator *tmp1)
{
    if (tmp != NULL && tmp1->returnBag() != NULL)
        if (tmp->value == tmp1->returnValue())
            return true;
        else
            return false;
    else if ((tmp == NULL) && (tmp1->returnBag() == NULL))
        return true;
    else
        return false;
}

Bag::Iterator Bag::goOn()
{
        Bag *tmp = head;
        while (tmp->left != NULL)
            tmp = tmp->left;
        if (tmp == head)
        {
            Iterator tmp2(NULL, head);
            return tmp2;
        }
        else
        {
            Iterator tmp2(tmp, head);
            return tmp2;
        }
}

Bag::Iterator Bag::laster()
{
    Iterator tmp(NULL, head);
    return tmp;
}
