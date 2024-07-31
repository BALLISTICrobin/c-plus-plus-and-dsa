#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a>b;
}

int main(int argc, char const *argv[])
{
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int> v;
        vector<pair<int,int>>res;
        for(int i=0; i<2*n; i++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end(),cmp);
        int count = n;
        auto i = v.begin();
        auto j = v.begin()+count;
        int sum = 0;
        while(count!=1){
            sum+=abs(*(i+1)-*i) + abs(*(j+1)-*j);
            res.push_back({*i,*j});
            i++;
            j++;
            count--;
        }
        res.push_back({*i,*j});
        cout<<sum<<endl;
        for(auto item: res){
            cout<<item.first<<" "<<item.second<<endl;
        }
    }
    
    return 0;
}
