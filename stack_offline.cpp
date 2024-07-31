#include <iostream>
#include <cstdlib>
#include <stdbool.h>
using namespace std;

template <class T>
class STACK
{
    T parameter;
    T *s;
    int len, top, memory;
    bool in;

public:
STACK(){
    top = 0;
    memory = 100;
    in = false;
    s = (T *)malloc(memory * sizeof(T));
}
    STACK(int a, int b)
    {
        memory = a;
        len = b;
        in = true;
        s = (T *)malloc(memory * sizeof(T));
        top = 0;
        for (int i = 0; i < len; i++)
        {
            T val;
            cin >> val;
            push(val);
        }
    }

    void push(T value)
    {
        if (top >= len && in==true)
            len++;
        if (top == memory)
        {
            memory *= 2;
            s = (T *)realloc(s, memory * sizeof(T));
        }
        s[top++] = value;
    }

    T pop()
    {
        if (top == 0 && in==true)
        {
            cout << "the stack is empty" << endl;
            exit(0);
        }
        else if(in==true)
        len--;
        // else if (top == 0 && in==false){
        //     return '0';
        // }
        return s[--top];
    }
    int length()
    {
        return top;
    }
    T topValue()
    {
        if (top == 0 && in ==true)
        {
            cout << "the stack is empty" << endl;
            exit(0);
        }
        // else if (top == 0 && in==false){
        //     return '0';
        // }
        return s[top - 1];
    }
    void clear()
    {
        // if (top == 0)
        // {
        //     cout << "the stack is empty" << endl;
        //     return;
        // }
        top = 0;
    }
    bool isEmpty()
    {
        if (top == 0)
            return true;
        else
            return false;
    }
    void display()
    {
        int i;
        cout << "<";
        for (i = 0; i < top - 1; i++)
        {
            cout << s[i] << ",";
        }
        if (i == top - 1)
        {
            cout << s[i];
        }
        cout << ">" << endl;
        ;
    }
    void para()
    {
        cin >> parameter;
    }
    T getPara()
    {
        return parameter;
    }
};

