#include"dsa_linked_list_singly.cpp"

/*void rmvDuplicates(Node* &head){
    if(head==NULL){
        cout<<"the list is empty"<<endl;
        exit(0);
    }
    else{
    Node *prev = NULL;
    Node *curr = head;
    while(curr!=NULL){
        int data = curr->data;//1
        Node *temp = curr->next;
        while(temp!=NULL){
            
            if(data==temp->data){
                temp = temp->next;
            }
            else{
                
                break;
            }
            
        }
        prev = curr;
        curr=temp;
        prev->next = curr;
        
    }
    }
}*/

//alternative
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
    rmvDuplicates(head);
    displayNodes(head);
    return 0;
}


/*
1->2->2->3->3->3->3->4*/

