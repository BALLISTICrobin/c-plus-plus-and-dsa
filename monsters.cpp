#include<iostream>
#include<utility>
#include<queue>

using namespace std;

int main(int argc, char const *argv[])
{
    int test;
    cin>>test;

    while(test--){
        int n,k;
        cin>>n>>k;
        
        priority_queue<pair<int,int>> q;
        int i=1;
        while(n--){
            int value;
            cin>>value;
            q.push(make_pair(value,i));
            i++;
        }
        while(!q.empty()){
            pair<int,int> z = q.top();
            q.pop();
            z.first = z.first-k;
            if(z.first>0){
                q.push(z);
            }
            else
            {
                cout<<z.second<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
