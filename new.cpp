#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int i;
    int *arr = new int[5];
    for( i=0; i<5; i++){
        arr[i]=i+1;
    }
    int j;
    for(j = i; j<200; j++){
        arr[j]=j+1;
    }
    cout<<arr[j];
    return 0;
}
