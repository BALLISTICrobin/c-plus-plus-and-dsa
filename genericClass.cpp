#include<iostream>
using namespace std;

const int SIZE = 10;
template <class AType>
class atype
{
    AType a[SIZE];

public:
    atype()
    {
        int i;
        for (i = 0; i < SIZE; i++)  a[i] = i;
    }
    AType &operator[](int i);
};

// Provide range checking for atype.
template <class AType>
AType &atype<AType>::operator[](int i)
{
    if (i < 0 || i > SIZE - 1)
    {
        cout << "\nIndex value of ";
        cout << i << " is out-of-bounds.\n";
        exit(1);
    }
    return a[i];
}


int main()
{
    atype<int> intob; // integer array 
    atype<double> doubleob; // double array 
    int i;
    cout << "Integer array: ";
    for (i = 0; i < SIZE; i++) intob[i] = i+1;
    for (i = 0; i < SIZE; i++)
        cout << intob[i] << "  ";
    cout << '\n';
    cout << "Double array: ";
    for (i = 0; i < SIZE; i++)
        doubleob[i] = (double)i / 3;
    for (i = 0; i < SIZE; i++)
        cout << doubleob[i] << "  ";
    cout << '\n';
    intob[12] = 100; // generates runtime error
    return 0;
}
