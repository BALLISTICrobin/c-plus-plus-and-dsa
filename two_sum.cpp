#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int size;
    cin>>size;
    int * arr = new int[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size;j++){
            if((arr[i]+arr[j])==target){
                cout<<i<<" "<<j<<endl;
            }
        }
        
    }
    return 0;
}
