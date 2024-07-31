#include<iostream>
#include"dsa_linked_list_singly.cpp"
using namespace std;

Node* ReverseInKgrps(Node* &head,int k){
    if(head == NULL) {
        return NULL;
    }
    
    //step1: reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count= 0;
    
    while( curr != NULL && count < k ) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    //step2: Recursion dekhlega aage ka 
    if(next != NULL) {
        head -> next = ReverseInKgrps(next,k);
    }
    
    //step3: return head of reversed list
    return prev;
   
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    Node *tail = NULL;
    int group,numOfElement;
    cin>>numOfElement>>group;
    for(int i=0; i<numOfElement; i++){
        int data;
        cin>>data;
        insertAtTail(head,tail,data);
    }
    
    head = ReverseInKgrps(head,group);
    displayNodes(head);
    return 0;
}

/*problem::
1->2->3->4
2->1->4->3*/