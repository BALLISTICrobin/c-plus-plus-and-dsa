#include"listLL1.cpp"

void reverseLL(Linkedlist &L){
    Node *prev = NULL;
    Node *curr = L.head;

    while(curr!=NULL){
        
        Node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;

    } 
    Node * temp = L.head;
    L.head = L.tail;
    L.tail = temp;
}

int main(int argc, char const *argv[])
{
    Linkedlist L1;
    L1.init();
    
    //reverse the linked list
    reverseLL(L1);
    L1.display();
    return 0;
}

/*problem::
1->2->3->4
4->3->2->1*/

