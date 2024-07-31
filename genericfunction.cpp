#include<iostream>
using namespace std;


// This is a function template
template <typename X> void swapargs(X &a, X &b)
{
    X temp;
    temp = a;
    a = b;
    b = temp;
}

template <class type1, class type2>
void myfunc(type1 x, type2 y)
{
    cout << x << ' ' << y << '\n';
}

int main()
{
    // int i = 10, j = 20;
    // double x = 10.1, y = 23.3;
    // char a = 'x', b = 'z';
    // cout << "Original i, j: " << i << ' ' << j << '\n';
    // cout << "Original x, y: " << x << ' ' << y << '\n';
    // cout << "Original a, b: " << a << ' ' << b << '\n';
    // swapargs(i, j); // swap integers 
    // swapargs(x, y); // swap floats 
    // swapargs(a, b); // swap chars
    // cout << "Swapped i, j: " << i << ' ' << j << '\n';
    // cout << "Swapped x, y: " << x << ' ' << y << '\n';
    // cout << "Swapped a, b: " << a << ' ' << b << '\n';


    myfunc(10, "I like C++");
    myfunc(98.6, 19L);
    
    return 0;
}
