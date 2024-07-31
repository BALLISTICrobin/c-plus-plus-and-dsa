#include "arraylist.h"

template <typename T>
class Queue
{
    int front, rear;
    Arraylist<T> a;

public:
    Queue()
    {

        front = -1;
        rear = -1;
    }
    void enqueue(T item)
    {
        if (front == 0 && rear == a.mem_size - 1 || rear == (front - 1) % (a.mem_size - 1))
        {
            // cout << "the queue is full" << endl;
            int size = a.mem_size;
            T *ar = new T[size];
            for (int i = 0; i < size && !isEmpty(); i++)
            {
                ar[i] = dequeue();
                // cout<<ar[i]<<"-";
            }
            a.reInitialize();
            front = 0;
            rear = size;
            int i;
            for (i = 0; i < size; i++)
            {
                a.moveToPos(i);
                a.append(ar[i]);
                // cout<<a.getValue()<<":";
            }
            a.moveToPos(i);
            a.append(item);
            // cout<<a.getValue()<<":";
            delete []ar;
        }
        else if (rear == -1)
        {
            front = 0;
            rear = 0;
            a.moveToPos(rear);
            a.append(item);
        }
        else if (rear == a.mem_size - 1 && front != 0)
        {
            rear = 0;
            a.moveToPos(rear);
            a.append(item);
        }
        else
        {
            rear++;
            a.moveToPos(rear);
            a.append(item);
        }
    }

    T dequeue()
    {
        a.moveToPos(front);
        T z = a.remove();

        if (front == rear)
        {

            front = rear = -1;
        }
        else if (front == a.mem_size - 1)
        {

            front = 0;
        }
        else
        {

            front++;
        }
        return z;
    }

    int length()
    {
        return a.length();
    }

    T Front()
    {
        a.moveToPos(front);
        T z = a.getValue();
        return z;
    }

    T end()
    {
        a.moveToPos(rear);
        T z = a.getValue();
        return z;
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
            return false;
    }
    void Clear()
    {
        a.clear();
        front = -1;
        rear = -1;
    }
    void display()
    {
        // cout<<length()<<"_";
        int index = front;
        cout << "<";
        for (int i = 0; i < length() - 1; i++)
        {
            // cout<<index<<":";
            a.moveToPos(index % a.mem_size);
            // cout<<a.currPos()<<"-";
            cout << a.getValue() << ",";
            index++;
        }
        if (!isEmpty())
        {
            // cout<<index<<":";
            a.moveToPos(index % a.mem_size);
            // cout<<a.currPos()<<"-";
            cout << a.getValue();
        }
        cout << ">" << endl;
    }
};