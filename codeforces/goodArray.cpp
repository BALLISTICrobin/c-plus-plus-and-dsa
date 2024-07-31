#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    ll test;
    cin>>test;
    while(test--){
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(ll i=0; i<n; i++){
            cin>>arr[i];
        }
        ll sum =0;
        ll Max = -1e9;
        ll count=0;
        for(ll i=0; i<n; i++){
            sum+=arr[i];
            Max = max(Max, arr[i]);
            if(Max==sum-Max){
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
