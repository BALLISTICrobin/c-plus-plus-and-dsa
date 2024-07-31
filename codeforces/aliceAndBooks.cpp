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
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(ll i=0;i<n;i++){
            cin>>v[i];
        }
        ll ans = 0;
        ll ans1 = v[n-1];
        ll max =0;
        for(ll i=n-2;i>=0;i--){
            if(v[i]>max){
                max = v[i];
            }
        }
        cout<<max+ans1<<endl;
    }
    return 0;
}
