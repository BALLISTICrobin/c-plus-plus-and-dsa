#include <iostream>
#include<unordered_map>
#include<queue>
#include<list>
#include<algorithm>
using namespace std;

void dijkstra(int V, unordered_map<int,list<pair<int,int>>> adjList,vector<int> &total_pay, int S)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    total_pay[S] = 0;
    pq.push({0, S});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        for (auto it : adjList[node])
        {
            int v = it.first;
            int w = it.second;
            if (dis + w < total_pay[v])
            {
                total_pay[v] = dis + w;
                pq.push({dis + w, v});
            }
        }
    }

    
}

int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    vector<int> tax(n+1,0);
    for(int i=1; i<=n; i++){
        int a;
        cin>>a;
        tax[i] =a;
    }

    unordered_map<int,list<pair<int,int>>> adjList;
    for(int j=0; j<m; j++){
        int a,b;
        cin>>a>>b;
        adjList[a].push_back({b,tax[b]});
        adjList[b].push_back({a,tax[a]});
    }
    vector<int> total_pay(n+1,1e9);
    dijkstra(n,adjList,total_pay,1);
    cout<<total_pay[n]<<endl;
    return 0;
}
