#pragma once

#include <iostream>
#include <ctype.h>

using namespace std;

template <class T>
class Tree
{
    T item;
    Tree<T> *son;
    Tree<T> *brother;

public:
    Tree(const T &item, Tree<T> *son = NULL, Tree<T> *brother = NULL);
    ~Tree();
    int GetHeight();
};

template <class T>
Tree<T>::Tree(const T &item, Tree<T> *son, Tree<T> *brother)
{
    Tree<T>::item = item;
    Tree<T>::son = son;
    Tree<T>::brother = brother;
    cout << "Created Tree # " << item << " -> " << this << "\n";
}

template <class T>
Tree<T>::~Tree()
{
    if (son)
    {
        delete son;
    }
    if (brother)
    {
        delete brother;
    }
    cout << "Deleted Tree # " << item << " -> " << this << "\n";
}

template <class T>
int Tree<T>::GetHeight()
{
    int max = 0;
    for (Tree<T> *current = son; current; current = current->brother)
    {
        int curHeight = current->GetHeight();
        if (curHeight > max)
        {
            max = curHeight;
        }
    }
    return max + 1;
}