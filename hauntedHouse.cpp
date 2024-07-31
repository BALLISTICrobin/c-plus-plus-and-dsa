#include<iostream>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
    ll test;
    cin>>test;
    while(test--){
        ll n;
        string bit;
        cin>>n>>bit;
        
        bool isThisZero = true;
            for(ll k =0; k<n; k++)
            {if(bit.at(k)=='1') {isThisZero=false;}}
            

        
        for(ll i=1; i<=n; i++){
            ll swap =0;
            ll count1=0;
            ll j = n-1-i;
            if(isThisZero) {cout<<0<<" ";continue;}
            if(j==-1){
                cout<<-1<<" ";
                break;
            }
            for(;j<n; j++){
                
                if(bit.at(j)=='1'){
                    count1++;
                    swap+=(j-n+1+i);
                }
            }
            if(count1==0){
                cout<<0<<" ";
                continue;
            }
            count1--;
            char *detect = &bit[n-2-i];
            j = n-2-i;
            while(j!=-1 && count1!=0){
                if(*detect=='1'){
                    
                    swap+=count1;
                    count1++;
                }
                else{
                    swap+=count1;
                }
                count1--;
                j--;
                detect--;
            }
            if(count1!=0)
            cout<<-1<<" ";
            else
            cout<<swap<<" ";
        }
        cout<<endl;
    }
    return 0;

}