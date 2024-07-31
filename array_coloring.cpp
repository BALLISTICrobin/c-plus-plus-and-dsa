#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int test;
    cin>>test;
    while (test--)
    {
        int n;
        cin>>n;
        int a[n];
        int count_odd=0;
        for(int i=0; i<n; i++){
            int val;
            cin>>val;
            if(val%2!=0) count_odd++;
            a[i] = val;
        }
        if(count_odd%2!=0){
            cout<<"NO"<<endl;
        }
        else
        cout<<"YES"<<endl;
        
        
    }
    
    return 0;
}
