// #ifndef FIBONACCI_HPP
// #define FIBONACCI_HPP
#include "node.hpp"
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>

const int maximumKey = std::numeric_limits<int>::max();

template <class t = int, class v = int>
class fibonacciHeap
{

    int numOfNodes;
    unordered_map<v, Node<t, v> *> nodePointer;
    Node<t, v> *singleton(t key, v value)
    {
        Node<t, v> *node = new Node(key, value);
        node->next = node;
        node->prev = node;
        return node;
    }
    void removeFromCircularList(Node<t, v> *x)
    {
        if (x->next == x)
            return;
        Node<t, v> *leftSib = x->prev;
        Node<t, v> *rightSib = x->next;
        leftSib->next = rightSib;
        rightSib->prev = leftSib;
        x->next = x->prev = x;
        // cout<<"hi"<<endl;
    }

    void consolidate()
    {
        // cout<<max->key<<endl;
        int sizeOfRootListarray = (int)(log2(numOfNodes) / log2(1.618));
        Node<t, v> **A = new Node<t, v> *[sizeOfRootListarray + 1];
        for (int i = 0; i < sizeOfRootListarray + 1; i++)
        {
            A[i] = nullptr;
        }
        vector<Node<t, v> *> nodeList;
        Node<t, v> *node = max;
        // cout<<node->key<<endl;
        do
        {
            // cout<<node->key<<endl;
            nodeList.push_back(node);
            node = node->next;
        } while (node != max);
        for (Node<t, v> *rootNode : nodeList)
        {

            int d = rootNode->degree;
            // cout<<rootNode->key<<" "<<d<<endl;
            removeFromCircularList(rootNode);
            while (A[d] != nullptr)
            {
                Node<t, v> *tmp = A[d];
                if (rootNode->key < tmp->key)
                {
                    Node<t, v> *temp = rootNode;
                    rootNode = tmp;
                    tmp = temp;
                    // swap(rootNode, tmp);
                }
                addChild(tmp, rootNode);
                // cout<<rootNode->key<<endl;
                A[d] = nullptr;
                d++;
            }
            // cout<<rootNode->key<<" "<<rootNode->degree<<endl;
            A[rootNode->degree] = rootNode;
            max = rootNode;
            // cout<<"robin"<<endl;
        }

        for (int i = 0; i < sizeOfRootListarray + 1; i++)
        {
            //
            if (A[i] != nullptr && A[i] != max)
            {
                merge(A[i], max);
            }
        }
        // cout<<"hello"<<endl;
        Node<t, v> *flag = max;
        Node<t, v> *iter = flag;
        do
        {
            if (iter->key > max->key)
            {
                max = iter;
            }
            iter = iter->next;
        } while (iter != flag);
        delete[] A;
    }

    void unparentAllChild(Node<t, v> *x)
    {
        if (x == nullptr)
            return;
        Node<t, v> *y = x;
        do
        {
            y->parent = nullptr;
            y = y->next;
        } while (y != x);
    }
    void addChild(Node<t, v> *child, Node<t, v> *parent)
    {
        // cout<<child->key<<" "<<parent->key<<endl;
        child->parent = parent;
        // cout<<parent->key<<" "<<parent->degree<<endl;
        parent->child = merge(child, parent->child);

        parent->degree++;

        child->mark = false;
    }
    Node<t, v> *merge(Node<t, v> *node, Node<t, v> *maxNode)
    {
        if (node == nullptr)
            return maxNode;
        if (maxNode == nullptr)
            return node;

        if (node->key > maxNode->key)
        {
            Node<t, v> *temp = maxNode;
            maxNode = node;
            node = temp;
        }
        Node<t, v> *maxNext = maxNode->next;
        Node<t, v> *nodePrev = node->prev;
        maxNode->next = node;
        node->prev = maxNode;
        maxNext->prev = nodePrev;
        nodePrev->next = maxNext;
        return maxNode;
    }
    void cut(Node<t, v> *x, Node<t, v> *y)
    {
        y->child = (x == x->next ? nullptr : x->next);
        removeFromCircularList(x);
        y->degree--;
        merge(x, max);
        x->parent = nullptr;
        x->mark = false;
    }

    void cascading_cut(Node<t, v> *y)
    {
        Node<t, v> *z = y->parent;
        if (z != nullptr)
        {
            if (y->mark == false)
                y->mark = true;
            else
            {
                cut(y, z);
                cascading_cut(z);
            }
        }
    }

    void increaseHelper(Node<t, v> *x, t newkey)
    {
        x->key = newkey;
        Node<t, v> *y = x->parent;
        if (y != nullptr && y->key < x->key)
        {
            cut(x, y);
            cascading_cut(y);
        }
        if (x->key > max->key)
        {
            max = x;
        }
    }
    void printTree(Node<t, v> *node)
    {
        Node<t, v> *startNode = node;
        Node<t, v> *currentNode = startNode;

        do
        {
            std::cout << "(" << currentNode->key << ", " << currentNode->value << ")";
            if (currentNode->child != nullptr)
            {
                std::cout << " -> ";
                printTree(currentNode->child);
            }
            currentNode = currentNode->next;
        } while (currentNode != startNode);
    }

public:
    Node<t, v> *max;
    fibonacciHeap()
    {
        max = nullptr;
        numOfNodes = 0;
    }

    bool empty()
    {
        return max == nullptr;
    }

    void Insert(t key, v value)
    {
        Node<t, v> *node = singleton(key, value);
        nodePointer[value] = node;
        if (max == nullptr)
        {
            max = node;
        }

        else
        {
            max = merge(node, max);
            numOfNodes++;
        }
    }

    pair<t, v> Extract_max()
    {
        if (max == nullptr)
        {
            cout << "the heap is empty" << endl;
            return make_pair(-1, -1);
        }
        else
        {

            Node<t, v> *temp = max;
            unparentAllChild(max->child);
            max = merge(temp->child, temp);
            if (temp == temp->next)
            { // only one node left
                max = nullptr;
            }
            else
            {
                max = temp->next;
            }
            removeFromCircularList(temp);
            if (max != nullptr)
            {
                consolidate();
            }
            numOfNodes--;
            t key = temp->key;
            v value = temp->value;
            delete temp;
            nodePointer[value] = nullptr;
            return make_pair(key, value);
        }
    }
    void IncreaseKey(v value, t key)
    {
        Node<t, v> *node = nodePointer[value];
        increaseHelper(node, key);
    }

    void DeleteKey(v value)
    {
        // cout<<"deleting"<<value<<endl;
        Node<t, v> *node = nodePointer[value];
        if (node == nullptr)
        {
            // cout<<max->key<<endl;
            cout << "no such element exists" << endl;
            return;
        }
        // cout<<node->key<<endl;

        increaseHelper(node, maximumKey);
        Extract_max();
        // cout<<p.first<<" "<<p.second<<endl;
    }
    Node<t, v> *getmax()
    {
        return max;
    }
    //     Tree 1: (55, 3) -> (45, 5), (32, 4)
    // (45, 5) -> (7, 8)
    // Tree 2: (24, 7) -> (5, 10)
    // Tree 3: ……………..
    // Output explanation: The heap contains two trees. The first tree is rooted at (55, 3) (key, value pair) which has two children (45, 5) and (32, 4). The (45, 5) node has one child (7,
    // 8). The second tree is rooted at (24, 7) which has one child (5, 10)
    void printHeap(int serial)
    {
        Node<t, v> *startNode = max;
        if(startNode==nullptr){
            cout<<"heap is empty"<<endl;
            return;
        }
        do
        {
            cout << "TREE " << serial << ":";
            cout << "(" << startNode->key << "," << startNode->value << ") -> ";
            serial++;
            printChild(startNode->child);
            startNode = startNode->next;
        } while (startNode != max);
    }

    void printChild(Node<t, v> *node)
    {
        if (node == nullptr)
        {
            cout << endl;
            return;
        }
        Node<t, v> *startNode = node;
        Node<t, v> *currentNode = startNode;
        do
        {
            cout << "(" << currentNode->key << "," << currentNode->value << ")";
            if (currentNode->next != startNode)
            {
                cout << ",";
            }
            currentNode = currentNode->next;
        } while (currentNode != startNode);
        cout << endl;
        currentNode = startNode;
        do
        {
            if (currentNode->child != nullptr)
            {
                cout << "(" << currentNode->key << "," << currentNode->value << ")->";
                printChild(currentNode->child);
            }
            currentNode = currentNode->next;
        } while (currentNode != startNode);

        // cout << endl;
    }

    fibonacciHeap<t, v> &meldHelper(fibonacciHeap<t, v> &heap1, fibonacciHeap<t, v> &heap2)
    {
        
        if (heap1.max == nullptr)
        {
            heap1.max = heap2.max;
        }
        else if (heap2.max != nullptr)
        {
            heap1.max = heap1.merge(heap1.max, heap2.max);
        }
        heap1.numOfNodes += heap2.numOfNodes;
        for (auto it : heap2.nodePointer)
        {
            heap1.nodePointer[it.first] = it.second;
        }
        heap2.max = nullptr;
        heap2.numOfNodes = 0;
        return heap1;
    }
};
template <class t = int, class v = int>
fibonacciHeap<t, v> &make_heap()
{
    return *(new fibonacciHeap<t, v>());
}

template <class t = int, class v = int>
bool is_empty(fibonacciHeap<t, v> &heap)
{
    return heap.empty();
}

template <class t = int, class v = int>
void insert(fibonacciHeap<t, v> &heap, t key, v value)
{
    heap.Insert(key, value);
}

template <class t = int, class v = int>
pair<t, v> extract_max(fibonacciHeap<t, v> &heap)
{
    return heap.Extract_max();
}

template <class t = int, class v = int>
void increase_key(fibonacciHeap<t, v> &heap, v Value, t newkey)
{
    heap.IncreaseKey(Value, newkey);
}
template <class t = int, class v = int>
void Delete(fibonacciHeap<t, v> &heap, v value)
{
    heap.DeleteKey(value);
}
template <class t = int, class v = int>
fibonacciHeap<t, v> &meld(fibonacciHeap<t, v> &heap1, fibonacciHeap<t, v> &heap2)
{
    return heap1.meldHelper(heap1, heap2);
}
template <class t = int, class v = int>
pair<t, v> find_max(fibonacciHeap<t, v> &heap)
{
    if (heap.max == nullptr)
    {
        cout << "the heap is empty" << endl;
        return make_pair(-1, -1);
    }
    return make_pair(heap.max->key, heap.max->value);
}

template <class t = int, class v = int>
void print(fibonacciHeap<t, v> &heap)
{
    heap.printHeap(1);
}

int main(int argc, char const *argv[])
{
    fibonacciHeap<int, int> heap = make_heap<int, int>();
    insert(heap, 39, 1);
    insert(heap, 40, 2);
    insert(heap, 2, 3);
    insert(heap, 14, 4);
    insert(heap, 69, 5);
    print(heap);
    pair<int, int> p = extract_max(heap);
    cout << p.first << " " << p.second << endl;
    print(heap);
    insert(heap, 100, 6);
    insert(heap, 200, 7);
    insert(heap, 300, 8);

    insert(heap, 400, 9);
    insert(heap, 500, 10);
    insert(heap, 600, 11);
    print(heap);
    p = extract_max(heap);
    cout << p.first << " " << p.second << endl;
    print(heap);
    Delete(heap, 11);

    p = extract_max(heap);
    cout << p.first << " " << p.second << endl;

    fibonacciHeap<int, int> heap2 = make_heap<int, int>();
    insert(heap2, 50, 12);
    insert(heap2, 60, 13);
    insert(heap2, 700, 14);
    insert(heap2, 80, 15);
    insert(heap2, 90, 16);
    p=extract_max(heap2);
    cout << p.first << " " << p.second << endl;
    fibonacciHeap<int, int> newheap = meld(heap, heap2); // meld to heap1

    p = extract_max(newheap);
    cout << p.first << " " << p.second << endl;
    increase_key(newheap, 15, 1000);
    p = extract_max(newheap);
    cout << p.first << " " << p.second << endl;
    print(newheap);
    Delete(newheap,13);
    increase_key(newheap,3,200);
    print(newheap);
    return 0;
}
