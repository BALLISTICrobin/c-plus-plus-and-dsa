#include<iostream>
using namespace std;

class Base1{
    int data1;

    public:

    Base1(int a){
        data1 = a;
        cout<<"constructor for base1 is called"<<endl;
    }

    void displayBase1(){
        cout<<data1<<endl;
    }
};

class Base2{
    int data2;

    public:

    Base2(int a){
        data2 = a;
        cout<<"constructor for base2 is called"<<endl;
    }

    void displayBase2(){
        cout<<data2<<endl;
    }
};

class Derived: public Base1, public virtual Base2{
    int derived1,derived2;

    public:
    Derived(int a,int b, int c, int d):Base1(a),Base2(b){
        derived1 = c;
        derived2 = d;
        cout<<"constructor for derived class is called"<<endl;
    }

    void displayDerived(){
        cout<<derived1<<endl<<derived2<<endl;
    }
};

int main(int argc, char const *argv[])
{
    Derived obj(1,2,3,4);
    obj.displayBase1();
    obj.displayBase2();
    obj.displayDerived();
    return 0;
}
