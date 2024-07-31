#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}

void findMaxActivities(vector<pair<int,int>> v){
    int n = v.size();
    int i=0;
    cout<<v[i].first<<" "<<v[i].second<<endl;
    for(int j=1; j<n; j++){
        if(v[j].first >= v[i].second){
            cout<<v[j].first<<" "<<v[j].second<<endl;
            i = j;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    vector<pair<int,int>> v;
    cin>>n;
    for(int i=0; i<n; i++){
        int s,e;
        cin>>s>>e;
        v.push_back(make_pair(s,e));
    }
    sort(v.begin(),v.end(),cmp);
    findMaxActivities(v);

    return 0;
}
