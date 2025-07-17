#pragma once
#include <iostream>
using namespace std;

template <class T>
class Tree
{
public:
    struct Node
    {
        T item;
        Node *son;
        Node *brother;

        Node(T i, Node *s = nullptr, Node *b = nullptr)
        {
            item = i;
            son = s;
            brother = b;
        }
    };

    Node *root;
    Tree()
    {
        root = nullptr;
    }
    ~Tree()
    {
        DeleteSubtree(root);
    }

    int GetHeight()
    {
        return GetHeight(root);
    }

    int GetNodesOnLevel(int level)
    {
        return GetNodesOnLevel(root, level);
    }

    void Add(const T &elem)
    {
        Add(root, elem);
    }

private:
    void Add(Node *&node, const T &elem);
    void DeleteSubtree(Node *node);
    int GetHeight(Node *node);
    int GetNodesOnLevel(Node *node, int level);
};

template <class T>
void Tree<T>::DeleteSubtree(Node *node)
{
    if (node)
    {
        DeleteSubtree(node->son);
        DeleteSubtree(node->brother);
        delete node;
    }
}

template <class T>
int Tree<T>::GetHeight(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int max = 0;
    cout << "----------------\n";
    cout << node->son << " " << node->brother << "\n";
    for (Node *current = node->son; current; current = current->brother)
    {
        cout << "Current = " << current << "\n";
        int curHeight = GetHeight(current);
        cout << "max = " << max << "\n";
        if (curHeight > max)
        {
            max = curHeight;
        }
    }
    return max + 1;
}

template <class T>
int Tree<T>::GetNodesOnLevel(Node *node, int level)
{
    if (node == nullptr)
    {
        return 0;
    }
    if (level <= 0)
    {
        return 0;
    }
    return GetNodesOnLevel(node->son, level - 1) + (level == 1) + GetNodesOnLevel(node->brother, level);
}

template <class T>
void Tree<T>::Add(Node *&node, const T &item)
{
    if (node == nullptr)
    {
        node = new Node(item);
    }
    else if (item < node->item)
    {
        Add(node->son, item);
    }
    else
    {
        Add(node->brother, item);
    }
}