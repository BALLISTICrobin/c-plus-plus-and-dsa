#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int test;
    cin>>test;
    while(test--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a+b>=10){
            cout<<"YES"<<endl;
        }
        else if(b+c>=10){
            cout<<"YES"<<endl;
        }
        else if(c+a>=10){
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
