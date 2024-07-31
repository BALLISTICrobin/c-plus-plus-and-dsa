#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int> b;
        for(int i=0; i<n; i++){
            
            int val;
            cin>>val;
            b.push_back(val);
        }
        vector<int> result;
        result.push_back(b[0]);
        int value = b[0];
        for(int i=1; i<n; i++){
            if(b[i]>=value){
                result.push_back(b[i]);
                
            }
            else{
                result.push_back((rand()%b[i])+1);
                result.push_back(b[i]);
            }
            value = b[i];
        }
        cout<<result.size()<<endl;
        for(int i=0; i<result.size(); i++){
            cout<<result.at(i)<<" ";
        }
        cout<<endl;

    }
    return 0;
}
