#include<iostream>
using namespace std;

class A{
    int a;
    public:
        // A(){
        //     a = 0;
        // }
        void setA(int a){
            this->a = a;
        }
        int getA(){
            return a;
        }
};

int main(int argc, char const *argv[])
{
    A a;
    A *p = new A();
    p->setA(5);
    cout<<p->getA()<<endl;
    a.setA(10);
    cout<<a.getA()<<endl;
    return 0;
}
