#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int test;
    cin>>test;
    while(test--){
        int x,y,k;
        cin>>x>>y>>k;
        if(y<=x){
            cout<<x<<endl;
        }

        else{
            if(y-x<=k){
                cout<<y<<endl;
            }
            else{
                cout<<x+k+2*(y-x-k)<<endl;
            }
        }
    }
    
    return 0;
}
