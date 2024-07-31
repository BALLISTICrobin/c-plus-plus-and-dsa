#include <iostream>
#include <iomanip>
using namespace std;

class A
{
    
public:
    int i;
    A()
    {
        cout << "constructor" << endl;
        i =1;
    }
    ~A()
    {
        cout << "destructor" << endl;
    }
    A(const A &obj)
    {
        i = obj.i;
        cout << "copy constructor" << endl;
        i++;
        
    }
    friend A operator+(A b, A a);
};

A operator+(A b, A a)
{
    return a;
}

int main()
{
    A objA;
    A objB = objA + objA;
    cout<<objB.i<<endl;
    cout << "DONE" << endl;
}