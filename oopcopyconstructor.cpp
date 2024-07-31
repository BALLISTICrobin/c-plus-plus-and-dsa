#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class strtype
{
    char *p;

public:
    strtype(char *s);
    ~strtype() { delete[] p; }

    //we need this copy constructor whenever an obbject is copied to another object
    //we should use copy constructor when there is a dynamic memory allocation
    //when we pass any object as pass by value or return an object not as a reference we need to use copy constructor
    //to avoid the matter of copy constructor we can use pass by reference or return reference 
    strtype(const strtype &original) //if we don't use '&',the parameter will be passed as pass by value,in other words there 
                                    //creates a copy of the original object but we still don't create the copy constructor.
                                    //So,it's little bit a logical paradox and throws an error
                                    //again if we don't use const keyword, the original objects which is passed as a reference may change,
                                    //may case trouble.
    {
        int len = strlen(original.p);
        p = new char[len];
        strcpy(p,original.p);
    }
    char *get() { return p; }
};

strtype::strtype(char *s)
{
    int l;

    l = strlen(s) + 1;
    p = new char[l];
    if (!p)
    {
        cout << "Allocation error\n";
        exit(1);
    }
    strcpy(p, s);
}

void show(strtype x)
{
    char *s;

    s = x.get();
    cout << s << endl;
}

int main()
{
    strtype a("HELLO"), b("THERE");

    show(a);
    show(b);
    return 0;
}