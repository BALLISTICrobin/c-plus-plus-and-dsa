#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef long long ll;

class comparator{
    public:
    bool operator()(pair<pair<ll,ll>,ll> a, pair<pair<ll,ll>,ll> b){
        
        return a.second>b.second;
    }

};

int main(int argc, char const *argv[])
{
    /* code */
    ll test;
    cin>>test;
    while(test--){
        ll h,n;
        cin>>h>>n;
        vector<ll> attack(n);
        vector<ll> coolDown(n);
        for(ll i=0;i<n;i++){
            cin>>attack[i];
        }
        for(ll i=0;i<n;i++){
            cin>>coolDown[i];
        }
        priority_queue<pair<pair<ll,ll>,ll>,vector<pair<pair<ll,ll>,ll> >, comparator> pq;
        for(ll i=0;i<n;i++){
            pq.push(make_pair(make_pair(attack[i],i),coolDown[i]+1));
        }
        ll turn =1;
        for(ll i=0; i<n; i++){
            h= h-attack[i];
            
        }
        //  cout<<h<<endl;
        // turn++;
        while(h>0){
            // cout<<turn<<endl;
            pair<pair<ll,ll>,ll> p = pq.top();
            // cout<<p.first<<" "<<p.second<<endl;
            if(p.second>turn){
                turn = p.second;
            }
            while(p.second==turn){
                // cout<<p.first<<" "<<p.second<<endl;
                h= h-p.first.first;
                pq.pop();
                pq.push(make_pair(p.first,coolDown[p.first.second]+turn));
                p = pq.top();
            }
            // cout<<h<<endl;
        }

        cout<<turn<<endl;

    }
    return 0;
}
