#include <iostream>
using namespace std;

class heap
{
    int *arr;
    int size;
    int mem_size;

public:
    heap()
    {

        cout << "enter memory size: " << endl;
        cin >> mem_size;
        arr = (int *)malloc(mem_size * sizeof(int));
        size = 0;
        arr[size] = -1;
    }

    void reinitialize()
    {
        mem_size = mem_size * 2;
        arr = (int *)realloc(arr, mem_size * sizeof(int));
    }

    // max heap;
    // insertion
    void insert(int value)
    {
        size++;
        arr[size] = value;
        int child_index = size;
        while (child_index > 1)
        {
            int parent_index = child_index / 2;
            if (arr[parent_index] < arr[child_index])
            {
                swap(arr[parent_index], arr[child_index]);
                child_index = parent_index;
            }
            else
                return;
        }
    }

    void Print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // deletion
    void Delete()
    {
        arr[1] = arr[size];
        size--;
        int parent_index = 1;
        while (parent_index < size)
        {

            int left = arr[parent_index * 2];
            int right = arr[parent_index * 2 + 1];
            int larger_index = left > right ? parent_index * 2 : parent_index * 2 + 1;
            if (arr[parent_index] < arr[larger_index])
            {
                swap(arr[parent_index], arr[larger_index]);
                parent_index = larger_index;
            }
            else
                return;
        }
    }
    void Max_heapify(int i)
    {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        if (left <= size && arr[largest] < arr[left])
        {
            largest = left;
        }

        if (right <= size && arr[largest] < arr[right])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            Max_heapify(largest);
        }
    }
    void heapSort()
    {
        int n = size;
        while (n > 1)
        {
            swap(arr[1], arr[n]);
            n--;
            Max_heapify(1);
        }
        // sort(arr,arr+size+1);
    }
    int getSize(){
        return size;
    }
    int top()
    {
        return arr[1];
    }
    int valueAt(int index){
        return arr[index];
    }
};

// build heap using heapify algorithm
void Max_heapify(int *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        Max_heapify(arr, n, largest);
    }
}

// heap sort
void heapSort(int *arr, int n)
{
    while (n > 1)
    {
        swap(arr[1], arr[n]);
        n--;
        Max_heapify(arr, n, 1);
    }
}
// kth smallest term
/*
approach:
1)heap sort
2)arr[K] print
*/

// checking a provided array is binary heap(max) or not
/*
approach:
1) checking complete binary tree
2) checking weather the array support max heap property or not?

how to check cbt?
if any index of the left or right node of binary tree is out of the total count of node
it must not be cbt.

how to check max order property after checking complete binary tree ?
leaf node -> auto heap
only left child(right NULL)->
*/
/*
An Efficient Solution is to compare root only with its children (not all descendants),
if root is greater than its children and the same is true for all nodes,
then tree is max-heap (This conclusion is based on transitive property of > operator, i.e., if x > y and y > z, then x > z).
The last internal node is present at index (n-2)/2 assuming that indexing begins with 0.

Below is the implementation of this solution. */
bool maxOrder(int *arr, int totalNodes)
{
    for (int i = 1; i < totalNodes / 2 + 1; i++)
    {
        // If left child is greater, return false
        // as we traverse upto last internal node, so,at least they have left child(CBT).
        if (arr[2 * i] > arr[i])
            return false;

        // If right child is greater, return false
        if (2 * i + 1 < totalNodes && arr[2 * i + 1] > arr[i])
            return false;
    }
    return true;
}

void checkMaxHeap(int *arr, int size)
{
    if (maxOrder(arr, size))
    {
        cout << "this is a heap" << endl;
    }
    else
        cout << "this is not a heap" << endl;
}

/*
merge two heaps:
1. stores two vectors in an single array
2. then apply heapify algo for the nodes(from n/2 to 1).
*/
void mergeHeaps(int *arr1, int *arr2, int size1, int size2)
{
    int size3 = size1 + size2 + 1;
    int ans[size3];
    ans[0] = -1;
    int k = 1;
    for (int i = 1; i <= size1; i++)
        ans[k++] = arr1[i];
    for (int i = 1; i <= size2; i++)
        ans[k++] = arr2[i];
    int len = k - 1;

    for (int i = len / 2; i > 0; i--)
    {
        Max_heapify(ans, len, i);
    }
    for (int i = 1; i < size3; i++)
        cout << ans[i] << " ";
    cout << endl;
}
/*
minimum cost of ropes:
There are given N ropes of different lengths,
we need to connect these ropes into one rope.
The cost to connect two ropes is equal to sum of their lengths.
The task is to connect the ropes with minimum cost.
Given N size array arr[] contains the lengths of the ropes.
*/
void minHeapify(int *arr, int index, int size)
{
    int mainIndex = index;
    int left = 2 * mainIndex;
    int right = 2 * mainIndex + 1;
    if (left <= size && arr[mainIndex] > arr[left])
        mainIndex = left;
    if (right <= size && arr[mainIndex] > arr[right])
        mainIndex = right;
    if (mainIndex != index)
    {
        swap(arr[mainIndex], arr[index]);
        minHeapify(arr, mainIndex, size);
    }
}
void insert(int *arr, int value, int &size)
{
    size++;
    arr[size] = value;
    int childIndex = size;
    while (childIndex > 1)
    {
        int parent_index = childIndex / 2;
        if (arr[parent_index] > arr[childIndex])
        {
            swap(arr[parent_index], arr[childIndex]);
            childIndex = parent_index;
        }
        else
            break;
    }
}
void Delete(int *arr, int &size)
{
    arr[1] = arr[size];
    size--;
    minHeapify(arr, 1, size);
}
int minCostRopes(int *arr, int &size)
{
    for (int i = size / 2; i > 0; i--)
    {
        minHeapify(arr, i, size);
    }

    int ans = 0;
    while (size > 1)
    {
        int a = arr[1];
        Delete(arr, size);
        int b = arr[1];
        Delete(arr, size);
        int sum = a + b;

        insert(arr, sum, size);
        ans += sum;
    }

    return ans;
}
/*
kth largest sum of sub array

*/
void kthLargestSumOfSubarray(int *arr, int size, int k)
{
    heap hg;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += arr[j];
            hg.insert(sum);
        }
    }
    hg.Print();
    hg.heapSort();
    hg.Print();
    cout<<hg.valueAt(hg.getSize()-k-1)<<endl;
    
}

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false); // Disable synchronization
    std::cin.tie(nullptr);
    // heap h;
    // h.insert(7);
    // h.insert(3);
    // h.insert(16);
    // h.insert(4);
    // h.insert(1);
    // h.insert(9);
    // h.insert(36);
    // h.insert(15);
    // h.Print();
    // h.Delete();

    // h.Print();

    // int arr[6] = {-1, 6, 4, 10, 2, 9};
    // int size = 5;
    // for(int i= size/2; i>0; i--){
    //     Max_heapify(arr,size,i);
    // }

    // for(int i=1; i<=size; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    // heapSort(arr,size);
    // for(int i=1; i<=size; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // int arr[19] = {-1,70,18,50,12,17,2,42,2,2,-42,12,-85,-85,-65,-65,2,2,2};
    // checkMaxHeap(arr,19);
    // int arr1[5] ={-1,10,5,6,2};
    // int len1 = sizeof(arr1)/sizeof(arr1[0]);
    // int arr2[4] ={-1,12,7,9};
    // int len2 = sizeof(arr2)/sizeof(arr2[0]);
    // mergeHeaps(arr1,arr2,len1-1, len2-1);
    // int arr[5]={-1,4,3,2,6};
    // int len = sizeof(arr)/sizeof(arr[0])-1;
    // cout<<"min cost of ropes: "<<minCostRopes(arr,len)<<endl;
    int arr[5] = {1,2,3,4,5};
    kthLargestSumOfSubarray(arr,5,3);

    return 0;
}
