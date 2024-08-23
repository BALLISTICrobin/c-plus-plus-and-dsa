// Time Complexity: O(n)
// #include<iostream>
// #include<vector>
// #include<algorithm>


// using namespace std;
// typedef long long ll;

// int main(int argc, char const *argv[])
// {
//     ll test;
//     cin>>test;
//     while(test--){
//         ll n;
//         cin>>n;
//         vector<ll> seq;
//         seq.push_back(n);
//         ll a,b;
//         a=n;
//         for(ll i=n-1; i>0; i--){
//             b=i;
//             if((b|a)==n){
//                 seq.push_back(b);
//                 a=b;
//             }
//         }
//         cout<<seq.size()<<endl;
//         while(seq.size()!=0){
//             cout<<seq.back()<<" ";
//             seq.pop_back();
//         }
//         cout<<endl;
//     }
//     return 0;
// }


//time complexity: O(logn)
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ll test;
    cin>>test;
    while (test--)
    {
        ll n;
        cin>>n;
        vector<ll> seq;
        seq.push_back(n);
        for(ll i=0; i<ll(log2(n))+1; i++){
            if((n&(1LL<<i))!=0){
                ll next = n & (~(1LL<<i));
                if(next!=0){
                    seq.push_back(next);
                }
            }
        }
        cout<<seq.size()<<endl;
        while(seq.size()!=0){
            cout<<seq.back()<<" ";
            seq.pop_back();
        }
        cout<<endl;
    }
    
    return 0;
}
