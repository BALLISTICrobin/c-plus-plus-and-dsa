#include "linkedlist.h"

template <typename T>
class Queue
{
    Linkedlist<T> L;

public:
    void enqueue(T item)
    {
        L.append(item);
    }
    T dequeue()
    {
        
            L.moveToStart();
            T z =  L.remove();
            return z;
        
    }
    int length()
    {
        return L.length();
    }

    T Front()
    {
        L.moveToStart();
        T z= L.getValue();
        return z;
    }

    T end()
    {
        L.moveToEnd();
        T z= L.getValue();
        return z;
    }
    bool isEmpty()
    {
        if (L.length() == 0)
        {
            return true;
        }
        else
            return false;
    }
    void Clear()
    {
        L.clear();
    }
    void display()
    {
        L.display();
    }
};
