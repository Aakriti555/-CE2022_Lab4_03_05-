#include <iostream>
#include "LinkedBST.h"
using namespace std;
// LinkedList Constructor definition
LinkedBST::LinkedBST()
{
    root = NULL;
}
// isEmpty() definition
bool LinkedBST::isEmpty()
{
    // check if root is NULL
    return (root == NULL);
}
// add() definition
void LinkedBST::add(int key, int value)
{
    // check if tree is empty
    if (isEmpty())
    {
        root = new Node(key, value);
        return;
    }
    else
    {
        // call add() recursively
        add(key, value, root);
    }
}
void LinkedBST::add(int key, int value, Node *root)
{
    Node *temp = root;
    if (temp == NULL)
    {
        temp = new Node(key, value);
        return;
    }
    // if key is less than root key
    else if (key < temp->key)
    {
        // if left child is NULL
        if (temp->L == NULL)
        {
            temp->L = new Node(key, value);
            return;
        }

        else
        {
            // call add() recursively
            add(key, value, temp->L);
        }
    }
    // if key is greater than root key

    else if (key > temp->key)
    {
        // if right child is NULL
        if (temp->R == NULL)
        {
            temp->R = new Node(key, value);
            return;
        }
        else
        {
            // call add() recursively
            add(key, value, temp->R);
        }
    }
    else
    {
        cout << "Key already exists" << endl;
        return;
    }
}
// remove() definition
void LinkedBST::remove(int key)
{
    // check if tree is empty
    if (isEmpty())
    {
        cout << "Tree is empty" << endl;
    }
    else
    {
        // call remove() recursively
        remove(key, root);
    }
}

Node *LinkedBST::remove(int key, Node *root)
{

    Node *temp = root;
    // checks if root is NULL
    if (temp == NULL)
    {
        return temp;
    }
    // if key is less than root key
    else if (key < temp->key)
    {
        // call remove() recursively
        temp->L = remove(key, temp->L);
    }
    // if key is greater than root key
    else if (key > temp->key)
    {
        // call remove() recursively
        temp->R = remove(key, temp->R);
    }
    else if (key == temp->key)
    {
        // if root has no child
        cout << "Key found and deleted" << endl;
        if (temp->L == NULL && temp->R == NULL)
        {
            delete temp;
            temp = NULL;
        }
        // if root has only right child
        else if (temp->L == NULL)
        {
            Node *toReturn = temp->R;
            delete temp;
            return toReturn;
        }
        // if root has only left child
        else if (temp->R == NULL)
        {

            Node *toReturn = temp->L;
            delete temp;
            return toReturn;
        }
        else
        {
            // find the minimum value in right subtree
            Node *temp1 = temp->R;
            while (temp1->L != NULL)
            {
                temp1 = temp1->L;
            }
            temp->key = temp1->key;
            temp->value = temp1->value;
            temp->R = remove(temp1->key, temp->R);
        }
    }
    else
    {
        cout << "Key not found" << endl;
    }
    return temp;
}
// search() definition
bool LinkedBST::search(int key)
{
    // check if tree is empty
    if (isEmpty())
    {
        return false;
    }
    else
    {
        // call search() recursively
        return search(key, root);
    }
}
bool LinkedBST::search(int key, Node *root)
{
    // checks if the key is less than root key
    if (key < root->key)
    {
        // if left child is NULL
        if (root->L == NULL)
        {
            return false;
        }
        else
        {
            // call search() recursively
            return search(key, root->L);
        }
    }
    // checks if the key is greater than root key
    else if (key > root->key)
    {
        // if right child is NULL
        if (root->R == NULL)
        {
            return false;
        }
        else
        {
            // call search() recursively
            return search(key, root->R);
        }
    }
    else
    {
        return true;
    }
}
// print() definition
void LinkedBST::print(Node *root)
{
    if (root != NULL)
    {
        print(root->L);
        cout << root->key << " " << root->value << endl;
        print(root->R);
    }
}