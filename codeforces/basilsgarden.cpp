#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
    ll test;
    cin>>test;
    while(test--){
        ll n;
        cin>>n;
        vector<ll> h(n);
        vector<ll> t(n);
        for(ll i=0; i<n; i++){
            cin>>h[i];
        }

        for(ll i=n-1; i>=0; i--){
            if(i==n-1)
            t[i] = h[i];

            else if(h[i]<=h[i+1]){
                t[i] = t[i+1] +1;
            }
            else{
                t[i] = max(h[i], t[i+1]+1);
            }
        }
        cout<<t[0]<<endl;

    }
    return 0;
}
