#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int size;
    cin>>size;
    int arr[size];
     for (size_t i= 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout<<sizeof(arr) / sizeof(arr[0]);
    return 0;
}
