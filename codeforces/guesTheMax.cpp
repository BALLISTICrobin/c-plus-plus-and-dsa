#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
typedef long long ll;

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
        ll Min=1e9;
        ll ans=0;
        for(ll i=0;i<n-1;i++){
            ans=max(v[i],v[i+1]);
            Min=min(ans,Min);
        }
        cout<<Min-1<<endl;
    }
    return 0;
}
