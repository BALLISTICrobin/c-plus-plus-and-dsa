#include<iostream>
#include<map>
#include<list>
#include<vector>
using namespace std;


int main(int argc, char const *argv[])
{
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int> a,b;
        for(int i=1;i<=n; i++){
            int val;
            cin>>val;
            a.push_back(val);
        }
        
        for(int i=1;i<=n; i++){
            int val;
            cin>>val;
            b.push_back(val);
        }
        // map<int,list<int>> m;
        // for(int i =1; i<n; i++){
        //     for(int j=i+1; j<=n; j++){
        //         if(a.at(i)-a.at(j)>=b.at(i)-b.at(j))
        //         m[i].push_back(j);
        //         else
        //         m[j].push_back(i);
        //     }
        // }
        vector<int> ans;
        for(int i=1; i<=n; i++){
            int count=0;
            for(int j=1; j<=n; j++){
                if(j!=i){
                    if( (a.at(i-1)-a.at(j-1))>=(b.at(i-1)-b.at(j-1)))
                    count++;
                    else
                    break;
                }
            }
            
            if(count==n-1)
            ans.push_back(i);
        }
        
        cout<<ans.size()<<endl;
        for(auto i: ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}
