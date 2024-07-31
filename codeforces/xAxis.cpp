#include<iostream>

typedef long long ll;
using namespace std;

int findMid(int a,int b,int c){
    if(a>b){
        if(b>c){
            return b;
        }else if(a>c){
            return c;
        }else{
            return a;
        }
    }else{
        if(a>c){
            return a;
        }else if(b>c){
            return c;
        }else{
            return b;
        }
    }
}
int main(int argc, char const *argv[])
{
    int test;
    cin>>test;
    while(test--){
        int a,b,c;
        cin>>a>>b>>c;
        int mid = findMid(a,b,c);
        int sum=0;
        sum = (mid-a)>0?(sum+(mid-a)):(sum+(a-mid));
        sum = (mid-b)>0?(sum+(mid-b)):(sum+(b-mid));
        sum = (mid-c)>0?(sum+(mid-c)):(sum+(c-mid));
        cout<<sum<<endl;
    }

    return 0;
}
