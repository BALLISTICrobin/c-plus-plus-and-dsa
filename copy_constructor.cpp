#include<iostream>
using namespace std;




class A{
    int *i;
    int *j;
    public:
    A(){
        cout<<"default constructor"<<endl;
        
        i = new int(0);
        j = new int(0);
    }
    A(int x, int y){
        cout<<"constructor"<<endl;
        i = new int(x);
        j = new int(y);
    }

    A(const A& original){
        cout<<"copy constructor"<<endl;
        i = new int(*original.i);
        j = new int(*original.j);
    }

    ~A(){
        cout<<"destructor"<<endl;
        delete i;
        delete j;
    }

    A operator=(A obj){
        cout<<"assignment operator"<<endl;
        *this->i = *obj.i;
        *this->j = *obj.j;
        return *this;
    }

    A operator+(A obj){
        cout<<"+ operator overloading"<<endl;
        A temp ;
        *temp.i = *i + *obj.i;
        *temp.j = *j + *obj.j;
        return temp;
    }

    A operator+(int val){
        cout<<"+ int operator overloading "<<endl;
        A temp ;
        *temp.i = *i + val;
        *temp.j = *j + val;
        return temp;
    }

};



int main(int argc, char const *argv[])
{
    A obj1(1,2),obj2(2,3),obj4;
    obj4 = (obj1+(obj2+4)+(-2));
    A obj5 = obj4 + obj1;
    return 0;
}
