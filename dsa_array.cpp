#include <iostream>
using namespace std;

#define MAXSIZE 100

void insertAtpos(int *arr, int element, int pos, int len)
{
    int i;   
    for (i=len-1; i >= (pos - 1); i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[i] = element;
    return;
}

void remove(int *arr, int len, int pos)
{
    for (size_t i = pos - 1; i < len; i++)
    {
        arr[i] = arr[i + 1];
    }
    return;
}

void sorting(int *arr, int len)
{
    // number of steps
    for (size_t i = 1; i < len; i++)
    {
        // comparison part
        for (size_t j= 0; j < len - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return;
}

void binSearch(int *arr, int len, int element)
{

    int low = 0;
    int high = len - 1;
    int mid = (high + low) / 2;
    while (high >= low)
    {
        if (arr[mid] == element)
        {
            cout << "found" << endl;
            return;
        }
        else if (element > arr[mid])
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
        mid = (high + low) / 2;
    }
    cout << "not found" << endl;
}

void display(int *arr, int len)
{
    for (size_t i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}


int main(int argc, char const *argv[])
{
    int arr[MAXSIZE]={1,2,3,4,5,6,7,8,9};
    int size = 9;

    display(arr, size);
    insertAtpos(arr, 3, 4, ++size);
    display(arr, size);
    remove(arr, --size, 5);
    display(arr, size);
    sorting(arr, size);
    display(arr, size);
    cout << "which element do u want to search?" << endl;
    int find;
    cin >> find;
    binSearch(arr, size, find);
    display(arr, size);

    return 0;
}
