#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    friend void insertAtFirst(Node *&, Node *&, int);
    friend void displayNodes(Node *);
    friend void insertAtTail(Node *&, Node *&, int);
    friend void insertAtMiddle(Node *&, Node *&, int, int);
    friend void deleteNode(Node *&, Node *&, int);
    friend Node *ReverseInKgrps(Node *&, int);
    friend void rmvDuplicates(Node *&);
    friend Node *mergeSorts(Node *&);
    friend Node *findMid(Node *&head);
    friend Node *merge(Node *&, Node *&);
    friend Node *reverse(Node *&);
    friend bool checkPalindrome(Node *&);
    friend void recur_reverse(Node *&, Node *, Node *);
};

void insertAtFirst(Node *&head, Node *&tail, int value)
{
    // creating a new node
    Node *tempNode = new Node(value);
    if (head == NULL)
    {
        head = tempNode;
        tail = tempNode;
    }
    else
    {
        tempNode->next = head;
        head = tempNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int value)
{
    // creating a new node
    Node *tempNode = new Node(value);
    if (tail == NULL)
    {
        head = tempNode;
        tail = tempNode;
    }
    tail->next = tempNode;
    tail = tempNode;
}

void insertAtMiddle(Node *&tail, Node *&head, int pos, int value)
{
    // inserting at 1st pos
    if (pos == 1)
    {
        insertAtFirst(head, tail, value);
        return;
    }
    Node *ptr = head;
    int count = 1;
    while (count < pos - 1)
    {
        ptr = ptr->next;
        count++;
    }
    // inserting at last pos
    if (ptr == NULL)
    {
        insertAtTail(head, tail, value);
        return;
    }
    Node *tempNode = new Node(value);
    Node *temp = ptr->next;
    ptr->next = tempNode;
    tempNode->next = temp;
}

void deleteNode(Node *&tail, Node *&head, int pos)
{
    Node *curr, *previous;
        curr = head;
        previous = NULL;
        int count = 1;
        while (count < pos)
        {
            previous = curr;
            curr = curr->next;
            count++;
        }
        if (previous != NULL)
        {
            if (curr->next == NULL)
            {
                tail = previous;
                previous->next = NULL;
                
                delete curr;
                return;
            }

            previous->next = curr->next;
            
            delete curr;
            return;
        }
        else if (curr->next == NULL && previous == NULL)
        {
            delete curr;
            head = tail = NULL;
            return;
        }
        else
        {
            
            head = curr->next;
            
            curr->next = NULL;
            delete curr;
            return;
        }
}

void displayNodes(Node *nd)
{
    while (nd)
    {
        cout << nd->data <<" ";
        nd = nd->next;
    }
    cout<<endl;
}

// int main(int argc, char const *argv[])
// {
//    Node *node1 = new Node(10);
//    Node *head = node1;
//    Node *tail = node1;
//    insertAtFirst(head,tail,11);
//    insertAtFirst(head,tail,12);
//    insertAtFirst(head,tail,13);
//    insertAtFirst(head,tail,14);
//    insertAtFirst(head,tail,15);
//    insertAtFirst(head,tail,16);
// displayNodes(head);
//     insertAtTail(head,tail,9);
//     insertAtTail(head,tail,8);
//     insertAtTail(head,tail,7);
// displayNodes(head);
//     insertAtMiddle(tail,head,4,1);
//     insertAtMiddle(tail,head,6,3);
//     insertAtMiddle(tail,head,1,-5);
//     insertAtMiddle(tail,head,15,89);
//     displayNodes(head);
//     deleteNode(tail,head,8);
//     displayNodes(head);
//     deleteNode(tail,head,13);
//    displayNodes(head);

//     return 0;
// }
