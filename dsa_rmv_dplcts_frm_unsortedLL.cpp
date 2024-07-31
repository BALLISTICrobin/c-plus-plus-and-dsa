//step 1: sort(merge sort) the list
//step 2: use remove duplicates from sorted linked list algorithm
#include"dsa_linked_list_singly.cpp"
//return mid node address
Node *findMid(Node *&head){
    // cout<<"a"<<endl;
    Node *slow = head;
    Node *fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        // cout<<"1"<<endl;
    }
    return slow;

}

//merge two sorted linked lists
Node* merge(Node* &left, Node* &right){
    // cout<<"hello"<<endl;
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
   Node *ans = new Node(-1);
    Node *temp = ans;
    while(left!=NULL && right!=NULL){
        if(left->data>=right->data){
            temp->next = left;
            left = left->next;
            temp = temp->next;
        }
        else{
            temp->next = right;
            right = right->next;
            temp = temp->next;
        }
    }
    while(left!=NULL){
        temp->next = left;
            left = left->next;
            temp = temp->next;
    }
    while(right!=NULL){
        temp->next = right;
            right = right->next;
            temp = temp->next;
    }
    return ans->next;
}

Node* mergeSorts(Node *&head){
    // cout<<"hi"<<endl;
    //base case(if there is none or only one node,we will return)
    if(head==NULL || head->next==NULL)
    return head;

    //recursion part
    Node *mid = findMid(head);
    Node *first = head;
    Node *second = mid->next;
    mid->next = NULL;
    first = mergeSorts(first);
    second = mergeSorts(second);

    //merge 2 sorted linked list
    Node *result = merge(first,second);
    return result;

}
void rmvDuplicates(Node* &head){
    if(head==NULL){
        cout<<"the list is empty"<<endl;
        exit(0);
    }
    else{
    Node *curr = head;
    Node*forward = NULL;
    // int data = curr->data;
     forward=curr->next;
    while(forward!=NULL){
        if(curr->data==forward->data){
            forward = forward->next;
            
        }
        else{
            
            curr = forward;
            forward = forward->next;
        }
        curr->next = forward;
        
        
        
    }
    }
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
        int data;
        cin>>data;
        insertAtTail(head,tail,data);
    }
   head = mergeSorts(head);
    rmvDuplicates(head);
    displayNodes(head);
    return 0;
}
