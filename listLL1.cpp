#include <iostream>
using namespace std;
int total_car, total_garage, maxCarPerGar;

class Linkedlist;
class Node
{
    int data;
    Node *next;

public:
    Node() {}

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }

    friend class Linkedlist;
    friend void print(Linkedlist);
    friend void reverseLL(Linkedlist&);
    friend void reArrnage(Linkedlist &);
};

class Linkedlist
{
protected:
    int init_len, curr_pos;
    Node *head, *tail, *trav;

public:
    int  size;
    Linkedlist()
    {

        
        init_len = 0;
        curr_pos = 0;
        head = NULL;
        tail = NULL;
        trav = NULL;
    }

    void init()
    {
        // head = NULL;
        // tail = NULL;

        cin >> size;
        // curr_pos = 1;
        // init_len = 0;
        for (int i = 0; i < size; i++)
        {
            int element;

            cin >> element;
            pushBack(element);
        }
    }
    void pushBack(int item)
    {
        init_len++;
        Node *node = new Node(item);
        // push back

        if (head == NULL)
        {
            head = node;
            tail = node;
        }

        else
        {

            tail->next = node;
            tail = node;
        }
    }

    int insert(int item)

    {

        init_len++;
        Node *node = new Node(item);

        if (head == NULL)
        {
            head = node;
            tail = node;
            return -1;
        }
        if (curr_pos == 0)
        {
            node->next = head;
            head = node;
        }
        else
        {
            Node *curr;
            Node *prev;
            curr = head;
            prev = NULL;
            int count = 1;
            // traversing
            while (count < curr_pos)
            {
                count++;
                prev = curr;
                curr = curr->next;
            }
            if (curr->next == NULL)
            {
                curr->next = node;
                tail = node;
                return -1;
            }
            node->next = curr->next;
            curr->next = node;
        }
        return -1;

        return 0;
    }

    int remove()
    {

        init_len--;
        Node *curr;
        Node *prev;
        curr = head;
        prev = NULL;
        if (curr_pos == 0)
        {
            Node *temp = head;
            head = head->next;

            temp->next = NULL;
            int ret = temp->data;
            // delete temp;
            return ret;
        }
        int count = 0;
        while (count < curr_pos)
        {
            count++;
            prev = curr;
            curr = curr->next;
        }

        if (curr->next == NULL)
        {
            prev->next = curr->next;

            int ret = curr->data;
            tail = curr;
            // delete curr;

            return ret;
        }
        prev->next = curr->next;
        curr->next = NULL;

        int ret = curr->data;
        // delete curr;
        return ret;
    }

    int append(int item)
    {
        init_len++;
        Node *temp = new Node(item);
        tail->next = temp;
        tail = temp;
        return -1;
    }

    int search(int item)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (item == temp->data)
                return 1;
            temp = temp->next;
        }
        return -1;
    }

    int moveToStart()
    {
        curr_pos = 0;
        return -1;
    }

    int moveToEnd()
    {
        curr_pos = init_len - 1;
        return -1;
    }

    int prev()
    {
        curr_pos--;
        // if (curr_pos < 0)
        // {
        //     cout << "curr_pos is not valid";
        //     curr_pos++;
        //     return -1;
        // }
        return -1;
    }

    int Next()
    {
        curr_pos++;

        return -1;
    }

    int length()
    {
        return init_len;
    }
    int currPos()
    {
        return curr_pos;
    }

    int moveToPos(int pos)
    {
        
        curr_pos = pos;
        // if (curr_pos < 0)
        // {
        //     cout << "curr_pos is not valid";
        //     curr_pos = 1;
        //     return -1;
        // }
        // if (curr_pos > init_len-1)
        // {
        //     cout << "the current position is not valid";
        //     curr_pos = 1;
        //     return -1;
        // }
        return -1;
    }

    int getValue()
    {

        trav = head;
        int count = 0;

        while (count < curr_pos)
        {
            count++;
            trav = trav->next;
        }
        return trav->data;
    }
    void Init()
    {
        // size = maxCarPerGar;
        while (getchar() != '\n')
        {

            int car_num;
            cin >> car_num;

            pushBack(car_num);
        }
        // alert = maxCarPerGar + 1;
    }
    int clear()
    {
        head = NULL;
        tail = NULL;
        curr_pos = 0;
        init_len = 0;
        return -1;
    }

    void display()
    {

        trav = head;
        cout << "<";
        int i = 0, count = 0;
        while (trav != NULL)
        {

            if (i == curr_pos)
            {
                count++;
                cout << "|";
            }
            cout << trav->data;
            if (i != (curr_pos - 1))
            {
                cout << ",";
            }
            trav = trav->next;
            i++;
            if (trav->next == NULL)
            {
                if (i == curr_pos && count == 0)
                {
                    cout << "|";
                }
                cout << trav->data;
                break;
            }
        };
        cout << ">" << endl;
    }
    // ~Linkedlist(){
    //     delete []gar;
    // }
    friend void print(Linkedlist);
    friend void reverseLL(Linkedlist&);
    friend void reArrnage(Linkedlist &);

} L;

Linkedlist *gar = new Linkedlist[total_garage * 10];
void print(Linkedlist gar)
{
    Node *temp = gar.head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int pos_min(Linkedlist gar)
{

    if (gar.length() == 0)
        return -1;
    else
    {
        gar.moveToStart();

        int min = gar.getValue();

        int c_pos = 0;
        int index = gar.currPos() + 1;
        gar.Next();
        while (gar.currPos() < gar.length())
        {

            if (gar.getValue() < min)
            {

                min = gar.getValue();
                c_pos = gar.currPos();
            }
            gar.Next();
        }
        return c_pos;
    }
}

int pos_max(Linkedlist gar)
{

    if (gar.length() == maxCarPerGar)
        return -1;
    else if (gar.length() == 0)
    {
        return 0;
    }
    else
    {

        gar.moveToStart();

        int max = gar.getValue();

        int c_pos = 0;
        int index = gar.currPos() + 1;
        gar.Next();
        while (gar.currPos() < gar.length())
        {

            if (gar.getValue() > max)
            {

                max = gar.getValue();
                c_pos = gar.currPos();
            }
            gar.Next();
        }
        return c_pos;
    }
}