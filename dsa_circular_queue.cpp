#include <iostream>
using namespace std;

template <class T>
class Queue
{
    int front, rear;
    T *arr;
    int size,memory,len;
public:
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
            enque(value);
            i++;
        }
    }

    void enque(T value){
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

    T deque(){
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

    T Front(){
        if(front==-1){
            cout<<"the queue is empty";
            exit(0);
        }
        return arr[front];
    }

    int length(){
        return len;
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

int main(int argc, char const *argv[])
{
    Queue<int> q1;
    q1.init();
    while(true){
        cout<<"1.enque"<<endl
        <<"2.deque"<<endl
        <<"3.length"<<endl
        <<"4.display"<<endl
        <<"5.front"<<endl
        <<"6.end"<<endl;

        int func_num,para;
        cout<<"enter func_num: ";
        cin>>func_num;
        switch (func_num)
        {
        case 1:
            cin>>para;
            q1.enque(para);
            break;
        
        case 2:
            cout<<q1.deque()<<endl;
            break;

        case 3:
            cout<<q1.length()<<endl;
            break;

        case 4:
            q1.display();
            break;

        case 5:
            cout<<q1.Front()<<endl;
            break;

        case 6:

            exit(0);    
        default:
            break;
        }
    } 

    return 0;
}
