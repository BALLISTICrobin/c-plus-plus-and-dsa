#include"dsa_linked_list_singly.cpp"
#include<stdbool.h>

Node* findMid(Node* &head){
    Node *slow = head;
    Node *fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
//to transfer the head to ta last of the linked list
void recur_reverse(Node *&head,Node *curr,Node *prev){
    if(curr==NULL){
        head = prev;
        return;
    }
   
   Node *forward = curr->next;
    curr->next = prev;
    
    recur_reverse(head,forward,curr);
    return;

}
Node* reverse(Node* &head){
    Node *curr =head;
    Node *prev = NULL;
    Node *forward = NULL;
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;

    }
    return prev;

    //----using recursion-----
    // Node *curr = head;
    // Node* prev = NULL;
    // recur_reverse(head,curr,prev);
    // return head;



}


bool checkPalindrome(Node* &head){
    
    Node*mid = findMid(head);
    
    Node *temp = reverse(mid->next);
    Node *curr = head;
    while(curr!=NULL && temp!=NULL){
        if(curr->data!=temp->data){
            return false;
        }
        curr = curr->next;
        temp = temp->next;
        
    }
    return true;
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    Node *tail = NULL;
    int numOfElements;
    cout<<"enter number of elements: "<<endl;
    cin>>numOfElements;
    cout<<"elements "<<endl;
    for(int i=0;i<numOfElements; i++){
        int value;
        cout<<"data "<<i+1<<" ";
        cin>>value;
        insertAtTail(head,tail,value);
    }
    
if(checkPalindrome(head)){
    cout<<"palindrome"<<endl;
}

else{
    cout<<"not palindrome"<<endl;
}
    //displayNodes(head);
    return 0;
}