#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
    /* code */
    ll test;
    cin>>test;
    while(test--){
        ll n,m;
        cin>>n>>m;
        vector<vector<char> > points(n, vector<char>(m));
        ll h=0,k=0;
        bool flag = false;
        int minCol = m;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cin>>points[i][j];
                if(points[i][j]=='#' && flag == false){
                    k = j+1;
                    flag = true;
                }
                if(points[i][j]=='#' && j<minCol){
                    h = i+1;
                    minCol = j+1;
                }
            }
        }
        cout<<h<<" "<<k<<endl;
    }
    return 0;
}
