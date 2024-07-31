#include<iostream>
using namespace std;


class A{
    string name;
    int *age;
    public:
    A(){
        name = "";
        age = new int;
    }
    A(string name, int age){
        this->name = name;
        this->age = new int(age);
    }
    ~A(){
        delete age;
    }
    void show(){
        cout<<name<<" "<<*age<<endl;
    }

    A&  operator=(const A& right_operand){
        
        name = right_operand.name;
        delete age;
        age = new int(*right_operand.age);
        return *this;
    }

};


int main(){
    A a1("abc", 10);
    A a2;
    A a3;
    a3 = a2 = a1;
    a2.show();
    a1.show();
    a3.show();
    return 0;
}