#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    ll test;
    cin >> test;
    while(test--){
        ll n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        set<ll> st;
        for(int i=0;i<m;i++){
            ll x;
            cin>>x;
            st.insert(x);
        }
        string c;
        cin>>c;
        vector<char> C(m);
        for(int i=0;i<m;i++){
            C[i] = c[i];
        }
        sort(C.begin(),C.end());
        ll len = st.size();
        int i=0;
        for(auto x:st){
            s[x-1]=C[i];
            i++;
        }
        cout<<s<<endl;

    }    
    return 0;
}
