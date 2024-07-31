#include <iostream>
using namespace std;
#include<stdbool.h>

template <class T>
class Queue
{
    int front, rear;
    T *arr;
    int memory,len;
public:

    int size;
    Queue()
    {
        
        cin>>size>>memory;
        len =0;
        front=-1;
        rear=-1;
        arr = new T[memory];
    }

    void init(){
        int i=0;
        cout<<"element ";
        while(i<size){
            T value;
            cin>>value;
            enqueBack(value);
            i++;
        }
    }

    void enqueBack(T value){
        if(front==0 && rear == memory-1 || rear == (front-1)%(memory-1)){
            cout<<"the queue is full"<<endl;
            exit(0);
        }
        else if(front==-1){
            front=rear =0;
            arr[rear] = value;
            len++;
        }

        else if(rear==memory-1){
            rear =0;
            arr[rear] = value;
            len++;
        }

        else{
            arr[++rear] = value;
            len++;
        }
        
    }

    void enqueFront(T value){
        if(front==0 && rear == memory-1 || rear == (front-1)%(memory-1)){
            cout<<"the queue is full"<<endl;
            exit(0);
        } 

        else if(front==-1){
            front=rear =0;
            arr[rear] = value;
            len++;
        }

        else if(front==0){
            front = memory-1;
            arr[front] = value;
            len++;
        }

        else{
            arr[--front] = value;
            len++;
        }
    }

    T dequeFront(){
        if(front==-1){
            cout<<"the queue is empty";
            exit(0);
        }
        len--;
        if(front == rear){
            T z = arr[front];
            front = rear = -1;
            return z;
        }

        else if(front == memory-1){
            T z = arr[front];
            front = 0;
            return z;
        }

        else{
            T z = arr[front];
            front++;
            return z;
        }
        
    }

    T dequeBack(){
        if(front==-1){
            cout<<"the queue is empty";
            exit(0);
        }
        len--;
        if(front == rear){
            T z = arr[rear];
            front = rear = -1;
            return z;
        }

        else if(rear == 0){
            T z = arr[rear];
            rear = memory-1;
            return z;
        }

        else{
            T z = arr[rear];
            rear--;
            return z;
        }
    }

    T Front(){
        if(front==-1){
            cout<<"the queue is empty";
            exit(0);
        }
        return arr[front];
    }

    T Back(){
        if(rear==-1){
            cout<<"the queue is empty";
            exit(0);
        }
        return arr[rear];
    }

    int length(){
        return len;
    }

    bool isEmpty(){
        if(front==-1 &&rear ==-1){
            return true;
        }
        else
        return false;
    }


    void display(){
        int index = front;
        for(int count =0; count<len; count++){
            cout<<arr[index%memory]<<" ";
            index++;
        }
        cout<<endl;

        
    }
};

// int main(int argc, char const *argv[])
// {
//     Queue<int> q1;
//     q1.init();
//     while(true){
//         cout<<"1.enqueBack"<<endl
//         <<"2.enqueueFront"<<endl
//         <<"3.dequeFront"<<endl
//         <<"4.dequeBack"<<endl
//         <<"5.length"<<endl
//         <<"6.display"<<endl
//         <<"7.front"<<endl
//         <<"8.Back"<<endl
//         <<"9.end"<<endl;

//         int func_num,para;
//         cout<<"enter func_num: ";
//         cin>>func_num;
//         switch (func_num)
//         {
//         case 1:
//             cin>>para;
//             q1.enqueBack(para);
//             break;
//         case 2:
//             cin>>para;
//             q1.enqueFront(para);
//             break;
//         case 3:
//             cout<<q1.dequeFront()<<endl;
//             break;
//         case 4:
//             cout<<q1.dequeBack()<<endl;
//             break;
//         case 5:
//             cout<<q1.length()<<endl;
//             break;

//         case 6:
//             q1.display();
//             break;

//         case 7:
//             cout<<q1.Front()<<endl;
//             break;

//         case 8:
//             cout<<q1.Back()<<endl;
//             break;
//         case 9:

//             exit(0);    
//         default:
//             break;
//         }
//     } 

//     return 0;
// }
