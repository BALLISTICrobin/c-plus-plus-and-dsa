#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int* arr = new int[2*n];
    for(int i=0; i<2*n; i++){
        cin>>arr[i];
    }
    int index1 = 0;
    int index2 = n;
    for(int i=0;i<n;i++){
        cout<<arr[index1++]<<" "<<arr[index2++]<<" "; 
    }
    return 0;
}
