#include<iostream>
using namespace std;
typedef long long int ll;
void sort(ll *a,ll size){
    for(ll i=1;i<size;i++){
        for(ll j=0;j<size-i;j++){
            if(a[j]<a[j+1]){
                ll temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
void check_even(ll* arr,ll size){
    for(ll i=0; i<size; i++){
        if(arr[i]%2!=0){
            ll count=0;
            for(ll j=i+1; j<size; j++){
                
                if((arr[i]-arr[j])%2==0){
                    count++;
                    break;
                }
            }
            if(count==0){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    return;
}

void check_odd(ll* arr,ll size){
    for(ll i=0; i<size; i++){
        if(arr[i]%2==0){
            ll count=0;
            for(ll j=i+1; j<size; j++){
                
                if((arr[i]-arr[j])%2!=0){
                    count++;
                    break;
                }
            }
            if(count==0){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    return;
}


int main(int argc, char const *argv[])
{
    int test;
    cin>>test;
    while(test--){
        ll size;
        cin>>size;
        ll *arr = new ll[size];
        for(ll i=0; i<size; i++){
            cin>>arr[i];
        }
        sort(arr,size);
        if(arr[size-1]%2==0){
            check_even(arr,size);
        }
        else{
            check_odd(arr,size);
        }
    }
    return 0;
}
