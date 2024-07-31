#include <iostream>
using namespace std;

class node
{
    int data;
    node *prev;
    node *next;

public:
    node(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
    friend void insertAtFirst(node *&, node *&, int);
    friend void displayNodes(node *);
    friend void insertAtLast(node *&, node *&, int);
    friend void insertAtPos(node *&, node *&, int, int);
    friend void deleteNode(node *&, node *&, int);
    friend void ReverseInKgrps(node *&, node *&, int, int);
};

void insertAtFirst(node *&tail, node *&head, int value)
{
    if (head == NULL)
    {
        node *temp = new node(value);
        head = temp;
        tail = temp;
    }
    else
    {
        node *temp = new node(value);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

//append
void insertAtLast(node *&tail, node *&head, int value)
{
    if (tail == NULL)
    {
        node *temp = new node(value);
        head = temp;
        tail = temp;
    }
    else
    {

        node *temp = new node(value);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

void insertAtPos(node *&head, node *&tail, int pos, int value)
{
    if (pos == 1)
    {
        insertAtFirst(tail, head, value);
    }
    else
    {
        int count = 1;
        node *curr = head;
        node *previous = NULL;
        while (count < pos)
        {
            previous = curr;
            curr = curr->next;
            count++;
        }
        if (curr == NULL)
        {
            insertAtLast(tail, head, value);
            return;
        }
        node *temp = new node(value);
        previous->next = temp;
        temp->prev = previous;
        temp->next = curr;
        curr->prev = temp;
    }
}

void deleteNode(node *&tail, node *&head, int pos)
{
    // deleting first node
   
        node *curr, *previous;
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
                curr->prev = NULL;
                delete curr;
                return;
            }

            previous->next = curr->next;
            curr->next->prev = previous;
            curr->prev = NULL;
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
            head->prev = NULL;
            curr->next = NULL;
            delete curr;
            return;
        }
    }

void displayNodes(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    // node* node1 = new node(10);
    node *head = NULL;
    node *tail = NULL;
    insertAtFirst(tail, head, 11);
    insertAtFirst(tail, head, 12);
    insertAtFirst(tail, head, 13);
    insertAtFirst(tail, head, 14);
    displayNodes(head);

    insertAtLast(tail, head, 9);
    insertAtLast(tail, head, 8);
    insertAtLast(tail, head, 7);
    insertAtLast(tail, head, 6);
    displayNodes(head);

    insertAtPos(head, tail, 4, 89);
    insertAtPos(head, tail, 6, 90);
    displayNodes(head);

    deleteNode(tail, head, 3);
    displayNodes(head);
    deleteNode(tail, head, 1);
    displayNodes(head);
    deleteNode(tail, head, 8);

    displayNodes(head);
    return 0;
}
