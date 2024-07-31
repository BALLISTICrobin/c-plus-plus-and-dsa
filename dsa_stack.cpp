#include<iostream>
using namespace std;
// #define MAXSIZE 20

template<typename T>
class STACK{
int top;
T *s;
int MAXSIZE;
public:
STACK(int size){
    MAXSIZE = size;
    top=-1;
    s = new T[size];
}

void push(T a){
    if(top==MAXSIZE-1){
        cout<<"the stack is full"<<endl;
        return;
    }
s[++top] = a;
}

void pop(){
    if(top<0){
        cout<<"the stack is empty"<<endl;
       
    }
    top--;
}

int isEmpty(){
    return top == -1;
}

void display(){
    for(int i=0;i<=top; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}

T Top(){
    return s[top];
}

int size(){
    return top+1;
}
 

};

// int main(int argc, char const *argv[])
// {
//     STACK s1(20);
    
//         s1.push(1);
//         s1.push(2);
//         s1.push(3);
//         s1.push(4);
   

//     cout<<s1.pop()<<endl;
//     cout<<s1.pop()<<endl;
//     if(s1.isEmpty()){
//         cout<<"the stack is empty"<<endl;
//     }
//     else
//     cout<<"the stack is not empty"<<endl;


//     return 0;
// }
