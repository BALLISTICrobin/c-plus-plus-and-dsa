#include<iostream>
using namespace std;


class B;

class A{
    public :
    void show(B &obj);

};

class B{
    int x;

    public:
    void setX(int i){x=i;}
    friend void A::show(B &obj);
};

void A::show(B &obj){
    cout<<obj.x<<endl;
}



