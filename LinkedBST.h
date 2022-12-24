#include <iostream>
#include "AbstractBST.h"
#ifndef LINKEDBST_h
#define LINKEDBST_h
class Node
{
public:
    int key;
    int value;
    Node *R;
    Node *L;
    Node()
    {
        key = 0;
        value = 0;
        R = NULL;
        L = NULL;
    }
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->R = NULL;
        this->L = NULL;
    }
};
class LinkedBST : public AbstractBST, public Node
{
    void add(int key, int value, Node *root);
    Node *remove(int key, Node *root);
    bool search(int key, Node *root);

public:
    Node *root;
    LinkedBST();
    ~LinkedBST();
    bool isEmpty();
    void add(int key, int value);
    void remove(int key);
    bool search(int key);
    void print(Node *root);
};
#endif