#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
int main()
{
    ll test;
    cin>>test;
    while(test--){
        ll n,k;
        cin>>n>>k;
        
        vector<ll> v;
        while(n--){
            int value;
            cin>>value;
            v.push_back(value);
        }
        sort(v.begin(),v.end());
        ll count = 0;
        while(true){
            ll diff_ck =0;
            for(auto it = v.begin(); it!=v.end()-1; it++){
                if(*(it+1)-*it>k){
                    v.erase(it);
                    diff_ck++;
                }
            }
        }
    }
    
    return 0;
}
