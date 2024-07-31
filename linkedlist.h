#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node()
    {
        next = NULL;
    }
    
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Linkedlist
{
protected:
    int init_len, curr_pos;
    Node<T> *head, *tail, *trav;

public:
    int size;

    Linkedlist()
    {
        init_len = 0;
        curr_pos = 0;
        head = NULL;
        tail = NULL;
        trav = NULL;
    }
    

    void init()
    {
        cin >> size;

        for (int i = 0; i < size; i++)
        {
            T element;
            cin >> element;
            pushBack(element);
        }
    }

    void pushBack(T item)
    {
        init_len++;
        Node<T> *node = new Node<T>(item);

        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    // void insert(T item)
    // {
    //     init_len++;
    //     Node<T> *node = new Node<T>(item);

    //     if (head == NULL)
    //     {
    //         head = node;
    //         tail = node;
    //     }
    //     else if (curr_pos == 0)
    //     {
    //         node->next = head;
    //         head = node;
    //     }
    //     else
    //     {
    //         Node<T> *curr = head;
    //         Node<T> *prev = NULL;
    //         int count = 0;

    //         while (count < curr_pos)
    //         {
    //             count++;
    //             prev = curr;
    //             curr = curr->next;
    //         }

    //         node->next = curr;
    //         prev->next = node;
    //     }
    // }

    T remove()
    {

        Node<T> *curr = head;
        Node<T> *prev = NULL;
        T ret;

        if (curr_pos == 0)
        {
            head = head->next;
            ret = curr->data;
        }
        // else
        // {
        //     int count = 0;

        //     while (count < curr_pos)
        //     {
        //         count++;
        //         prev = curr;
        //         curr = curr->next;
        //     }

        //     prev->next = curr->next;
        //     ret = curr->data;
        // }

        // if (curr == tail)
        //     tail = prev;

        delete curr;
        init_len--;
        return ret;
    }

    void append(T item)
    {
        init_len++;
        Node<T> *temp = new Node<T>(item);

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void moveToStart()
    {
        curr_pos = 0;
    }

    void moveToEnd()
    {
        curr_pos = init_len - 1;
    }

    void prev()
    {
        if (curr_pos > 0)
            curr_pos--;
    }

    void Next()
    {
        if (curr_pos < init_len - 1)
            curr_pos++;
    }

    int length()
    {
        return init_len;
    }

    int currPos()
    {
        return curr_pos;
    }

    void moveToPos(int pos)
    {
        if (pos >= 0 && pos < init_len)
            curr_pos = pos;
    }

    T getValue()
    {
        if(curr_pos==0){
            return head->data;
        }
        else if(curr_pos==init_len-1){
            return tail->data;
        }
        // else{
            // Node<T> *curr = head;
        // int count = 0;

        // while (count < curr_pos)
        // {
        //     count++;
        //     curr = curr->next;
        // }

        // return curr->data;
        // }
        return head->data;
        
    }

    void clear()
    {
        /*
        order of 1
        head =NULL;
        tail= NULL*/
        while (head != NULL)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }

        tail = NULL;
        init_len = 0;
        curr_pos = 0;
    }

    void display()
    {
        Node<T> *temp = head;
        cout << "<";

        while (temp != NULL && temp->next != NULL )
        {
            cout << temp->data;
            cout << ",";
            temp = temp->next;
        }
        if(temp!=NULL){
             cout << temp->data;
        }
        cout<< ">" << endl;
    }
};
#endif // LINKEDLIST_H
