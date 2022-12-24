#include <iostream>
#include "LinkedBST.h"
using namespace std;
int main()
{
    cout << "Enter your choice" << endl;
    cout << "1. BST using Array" << endl;
    cout << "2. BST using Linked List" << endl;
    cout << "3. EXIT" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        // Array Implementation
        break;
    case 2:
    {
        // Linked List Implementation
        LinkedBST *bst = new LinkedBST();
        while (true)
        {
            cout << "Enter your choice" << endl;
            cout << "1. Add" << endl;
            cout << "2. Remove" << endl;
            cout << "3. Search" << endl;
            cout << "4. Is Empty" << endl;
            cout << "5. Print" << endl;
            cout << "6. EXIT" << endl;
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                int key, value;
                cout << "Enter the key and value" << endl;
                cin >> key >> value;
                bst->add(key, value);
                break;
            }
            case 2:
            {
                int key;
                cout << "Enter the key" << endl;
                cin >> key;
                bst->remove(key);
                break;
            }
            case 3:
            {
                int key;
                cout << "Enter the key" << endl;
                cin >> key;
                if (bst->search(key))
                {
                    cout << "Key found" << endl;
                }
                else
                {
                    cout << "Key not found" << endl;
                }
                break;
            }
            case 4:
            {
                if (bst->isEmpty())
                {
                    cout << "Tree is empty" << endl;
                }
                else
                {
                    cout << "Tree is not empty" << endl;
                }
                break;
            }
            case 5:
            {
                bst->print(bst->root);

                break;
            }
            case 6:
            {
                return 0;
            }
            default:
            {
                cout << "Invalid choice" << endl;
                break;
            }
            }
        }
        break;
    }
    default:
    {
        cout << "Invalid choice" << endl;
        break;
    }
    }
    return 0;
}