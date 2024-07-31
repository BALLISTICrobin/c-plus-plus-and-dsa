#include<iostream>
using namespace std;

class llist{
int data;
llist *next;
public:
//constructor
llist(int data){
    this->data = data;
    this->next = NULL;
}
friend void insert(llist* &,int,int);
friend void displayNode(llist* &);
friend void deletion(llist* &,int);
};

void insert(llist* &tail, int comp, int value){
    if(tail==NULL){
        llist * temp = new llist(value);
        temp->next = temp;
        tail=temp;
       
    }
    else{
        llist* temp = new llist(value);
        llist* curr= tail;
        while(curr->data!=comp){
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
        

    }
}
void deletion(llist* &tail,int comp){
    llist* curr = tail;
    llist* prev = NULL;
    while(curr->data!=comp){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
    

}

void displayNode(llist* &tail){
    llist* ptr = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail!=ptr);
}

int main(int argc, char const *argv[])
{
    llist* tail = NULL;
    insert(tail,0,1);
    insert(tail,1,2);
    insert(tail,2,3);
    insert(tail,2,69);
    deletion(tail,3);
    deletion(tail,69);
    displayNode(tail);
    return 0;
}


