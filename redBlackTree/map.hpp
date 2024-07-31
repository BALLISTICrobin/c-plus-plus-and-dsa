#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include "Red_BlackTree.hpp"
using namespace std;

class Map
{
    RedBlackTree rbt;

public:
    void insert(int key, string value)
    {
        rbt.insert(key, value);
        rbt.preorder();
        cout << endl;
    }

    void erase(int key)
    {
        if (rbt.deleteNode(key) == true)
        {
            rbt.preorder();
            cout << endl;
        }
        else
        {
            cout << key << " "
                 << "not found" << endl;
        }

    }

    void clear()
    {
        if (rbt.clear() == true)
        {
            cout << "successful" << endl;
        }
        else
        {
            cout << "unsuccessful" << endl;
        }
    }

    void find(int key)
    {
        if (rbt.find(key) == true)
        {
            cout << key << " "
                 << "found" << endl;
        }
        else
        {
            cout << key << " "
                 << "not found" << endl;
        }
    }

    void empty()
    {
        if (rbt.empty() == true)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    void size()
    {
        cout << rbt.size() << endl;
    }

    void iteration(){
        rbt.Inorder();
        cout<<endl;
    }
};

#endif