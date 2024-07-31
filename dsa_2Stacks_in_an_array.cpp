#include<iostream>
using namespace std;

template <class T>
class Stack_2{
    T *arr;
    int top1;
    int top2;
    int size;

    public:
    
    Stack_2(int s){
        
        this->size = s;
        arr = new T[size];
        top1 = -1;
        top2 = size;
    }
    ~Stack_2(){
        delete []arr;
    }
    void push1(T data){
        if((top2-top1)>1){
            arr[++top1] = data;
        }
        
    }
    void push2(T data){
        if((top2-top1)>1){
            arr[--top2] = data;
        }
        
    }

    void pop1(){
        if(top1>=0){
            top1--;
        }
    }

    void pop2(){
        top2++;
    }

    T top_1(){
        return arr[top1];
    }

    T top_2(){
        return arr[top2];
    }

    void display(){
        for(int i=0; i<=top1; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        for(int i=size-1; i>=top2; i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
};


int main(int argc, char const *argv[])
{
    int s;
        cin>>s;
    Stack_2 <int> st1(s);
    st1.push1(1);
    st1.push1(2);
    st1.push1(3);
    st1.push2(9);
    st1.push2(8);
    st1.push2(7);
    st1.display();
    st1.pop1();
    st1.pop2();
    st1.display();
    return 0;
}
