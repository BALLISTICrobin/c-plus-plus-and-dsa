#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <limits.h>
#include <algorithm>



using namespace std;

bool BFS(vector<vector<long >> &residualCapacity, vector<long > &parent, long  source, long  sink)
{
    bool foundAugmentedPath = false;
    queue<long > Q;
    vector<long > visited(residualCapacity.size(), 0);
    Q.push(source);
    while (!Q.empty())
    {
        long  u = Q.front();
        Q.pop();
        for (long  v = 1; v < residualCapacity.size(); v++)
        {
            if (visited[v] == 0 && residualCapacity[u][v] > 0)
            {
                parent[v] = u;
                visited[v] = 1;
                Q.push(v);
                if (v == sink)
                {
                    foundAugmentedPath = true;
                    break;
                }
            }
        }
    }
    return foundAugmentedPath;
}
void DFS(vector<vector<long >> residualCapacity, long  s, vector<long > &visitedFromSource)
{
    visitedFromSource[s] = 1;

    for (long  v = 1; v < residualCapacity.size(); v++)
    {
        if (residualCapacity[s][v] > 0 && visitedFromSource[v] == 0)
        {
            DFS(residualCapacity, v, visitedFromSource);
        }
    }
}
long  Ford_Fulkerson(vector<vector<long >> capacity, vector<vector<long >> &residualCapacity, long  s, long  t)
{
    // vector<vector<long >> residualCapacity(capacity.size(),vector<long >(capacity.size(),0));
    for (long  i = 0; i < capacity.size(); i++)
    {
        for (long  j = 0; j < capacity.size(); j++)
        {
            residualCapacity[i][j] = capacity[i][j];
        }
    }
    // cout<<residualCapacity.size()<<endl;
    vector<long > parent(capacity.size(), -1);
    long  maxFlow = 0;
    while (BFS(residualCapacity, parent, s, t))
    {
        long  flow = 1e9;
        long  sink = t;
        while (sink != s)
        {
            long  par = parent[sink];
            flow = min(flow, residualCapacity[par][sink]);
            sink = par;
        }

        maxFlow += flow;

        long  v = t;
        while (v != s)
        {
            long  par = parent[v];
            residualCapacity[par][v] -= flow;
            residualCapacity[v][par] += flow;
            v = par;
        }
    }
    // vector<long > visitedFromSource(capacity.size(), 0);
    // DFS(residualCapacity, s, visitedFromSource);
    // for (long  i = 1; i < residualCapacity.size(); i++)
    // {
    //     if (visitedFromSource[i] == 1)
    //         r.push_back(i);
    //     else
    //         rem.push_back(i);
    // }
    return maxFlow;
}



int main(int argc, char const *argv[])
{
    long n, m;
    cin >> n >> m;
    vector<vector<long >> capacity(n + 1, vector<long >(n + 1, 0));
    vector<vector<long >> resCapacity(n + 1, vector<long >(n + 1, 0));
    unordered_map<long ,list<long >> graph;
    for(long  i=0; i<m; i++){
        long  a,b,c;
        cin>>a>>b>>c;
        capacity[a][b] = c;
        graph[a].push_back(b);
    }

    cout<<Ford_Fulkerson(capacity,resCapacity,1,n)<<endl;
    // cout<<KotivaloComputer(resCapacity,graph,n);
    return 0;
}
