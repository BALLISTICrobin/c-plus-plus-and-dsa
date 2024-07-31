#include "queue.h"

template <typename T>
class Stack
{
    Queue<T> q1;
    Queue<T> q2;

public:
    void push(T item)
    {
        q1.enqueue(item);
    }

    T pop()
    {

        while (q1.length() != 1)
        {
            T z = q1.dequeue();
            q2.enqueue(z);
        }
        T topvalue = q1.dequeue();
        Queue<T> temp;
        temp = q1;
        q1 = q2;
        q2 = temp;
        return topvalue;
    }

    int length()
    {
        return q1.length();
    }

    T Top()
    {

        T z = q1.end();
        return z;
    }

    bool isEmpty()
    {
        return q1.isEmpty();
    }

    void clear()
    {
        q1.Clear();
    }

    void display()
    {
        q1.display();
    }
};