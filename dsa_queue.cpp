#include<iostream>
using namespace std;
#define MAXSIZE 20
template <class T>
class Queue{
    int top,bottom;
    T q[MAXSIZE];
    public:
    Queue(){
        top=0;
        bottom =0;
    }
    void push(T a){
        if(top==MAXSIZE){
            cout<<"the queue is full"<<endl;
        }
        q[top++]= a;
    }
    
    int pop(){
        if(bottom==top){
            cout<<"the queue is empty"<<endl;
        }
        return q[bottom++];
    }

    int isEmpty(){
        return bottom==top;
    }

    int length(){
        return (top-bottom+1);
    }
};

int main(int argc, char const *argv[])
{
    Queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    cout<<q1.length()<<endl;

    cout<<q1.pop()<<endl;
    if(q1.isEmpty()){
        cout<<"the stack is empty"<<endl;
    }
    else
    cout<<"the stack is not empty"<<endl;
    
    return 0;
}
