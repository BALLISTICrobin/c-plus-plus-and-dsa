#include<iostream>
using namespace std;






class Node{
    int data;
    Node *next;

    public:
    
    Node(int data){
        this->data = data;
        next = NULL;
    }
    friend class Stack;

};


class Stack{
    Node  *head,*tail;


    public:
    Stack(){
        head = tail= NULL;
    }

    void push(int value){
        if(tail==NULL){
            Node *temp = new Node(value);
            head = temp;
            tail=temp;
        }
        else{
            Node *temp = new Node(value);
            tail->next = temp;
            tail = temp;
        }
    }

    void pop(){
        Node *curr = head;
        Node *prev = NULL;
        while(curr!=tail){
            curr = curr->next;
            prev = curr;
        }
        prev->next = NULL;
        tail = prev ;
    }

    void display(){
         Node *curr = head;
        Node *prev = NULL;
        while(curr!=NULL){
            cout<<curr->data<<" ";
            curr = curr->next;
            prev = curr;
        }
        cout<<endl;
    }
    
};

int main(int argc, char const *argv[])
{
    Stack st1;
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    st1.push(5);
    st1.display();
    st1.pop();
    st1.display();
    return 0;
}

