#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    ll test;
    cin>>test;
    while(test--){
        ll n,a,b;
        cin>>n>>a>>b;
        ll ans;
        if(b<=a){
            ans = n*a;
        }
        else{
            ll k = b-a;
            if(n<=k){
                ll sum =0;
                ll x = b-n;
                sum = b*(b+1)/2-x*(x+1)/2;
                ans = sum;
            }
            else{
                ll sum2= 0;
                sum2 = b*(b+1)/2 -a*(a+1)/2;
                ans = sum2 + (n-k)*a;
            }

        }
        cout<<ans<<endl;
    }
    return 0;   
}
