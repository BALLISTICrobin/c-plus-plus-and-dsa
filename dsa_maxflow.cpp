#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <limits.h>
#include <algorithm>

using namespace std;

bool BFS(vector<vector<int>> &residualCapacity, vector<int> &parent, int source, int sink)
{
    bool foundAugmentedPath = false;
    queue<int> Q;
    vector<int> visited(residualCapacity.size(), 0);
    Q.push(source);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int v = 1; v < residualCapacity.size(); v++)
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
void DFS(vector<vector<int>> residualCapacity, int s, vector<int> &visitedFromSource)
{
    visitedFromSource[s] = 1;

    for (int v = 1; v < residualCapacity.size(); v++)
    {
        if (residualCapacity[s][v] > 0 && visitedFromSource[v] == 0)
        {
            DFS(residualCapacity, v, visitedFromSource);
        }
    }
}
int Ford_Fulkerson(vector<vector<int>> capacity, vector<vector<int>> &residualCapacity, int s, int t, vector<int> &r, vector<int> &rem)
{
    // vector<vector<int>> residualCapacity(capacity.size(),vector<int>(capacity.size(),0));
    for (int i = 0; i < capacity.size(); i++)
    {
        for (int j = 0; j < capacity.size(); j++)
        {
            residualCapacity[i][j] = capacity[i][j];
        }
    }
    // cout<<residualCapacity.size()<<endl;
    vector<int> parent(capacity.size(), -1);
    int maxFlow = 0;
    while (BFS(residualCapacity, parent, s, t))
    {
        int flow = INT_MAX;
        int sink = t;
        while (sink != s)
        {
            int par = parent[sink];
            flow = min(flow, residualCapacity[par][sink]);
            sink = par;
        }

        maxFlow += flow;

        int v = t;
        while (v != s)
        {
            int par = parent[v];
            residualCapacity[par][v] -= flow;
            residualCapacity[v][par] += flow;
            v = par;
        }
    }
    vector<int> visitedFromSource(capacity.size(), 0);
    DFS(residualCapacity, s, visitedFromSource);
    for (int i = 1; i < residualCapacity.size(); i++)
    {
        if (visitedFromSource[i] == 1)
            r.push_back(i);
        else
            rem.push_back(i);
    }
    return maxFlow;
}

pair<int, int> findNodeWithMaxFlow(unordered_map<int, list<int>> graph, vector<vector<int>> residualCapacity, int source, int sink)
{
    auto it = graph.begin();
    int maxflowThruNode = 0;
    pair<int, int> flow = {0, 0};
    while (it != graph.end())
    {
        int p = it->first;
        
        if (p != source && p != sink)
        {
            // cout<<p<<" ";
            int flowThroughNode = 0;
            for (auto neighbour : graph[p])
            {
                flowThroughNode += residualCapacity[neighbour][p];
            }
            if (flowThroughNode >= maxflowThruNode)
            {
                maxflowThruNode = flowThroughNode;
                flow = {flowThroughNode, p};
            }
        }
        it++;
    }
    
    return flow;
}

int main(int argc, char const *argv[])
{
    int no_of_nodes, no_of_edges;
    unordered_map<int, list<int>> graph;
    cin >> no_of_nodes >> no_of_edges;
    vector<vector<int>> capacity(no_of_nodes + 1, vector<int>(no_of_nodes + 1, 0));
    vector<vector<int>> residualCapacity(capacity.size(), vector<int>(capacity.size(), 0));
    for (int i = 0; i < no_of_edges; i++)
    {
        int u, v, c;

        cin >> u >> v >> c;
        capacity[u][v] = c;
        graph[u].push_back(v);
    }

    int source, sink;
    cin >> source >> sink;
    // cout<<source<<" "<<sink<<" "<<capacity.size()<<endl;
    vector<int> reachedFromSource;
    vector<int> remainingVertices;
    int maxFlow = Ford_Fulkerson(capacity, residualCapacity, source, sink, reachedFromSource, remainingVertices);
    pair<int, int> p = findNodeWithMaxFlow(graph, residualCapacity, source, sink);
    cout <<"part a)"<<endl<< p.second << " " << p.first<<endl;
    cout << "part b)"<<endl<<"[{";
    for (auto vertex : reachedFromSource)
    {
        cout << vertex << ",";
    }
    cout << "},";
    cout << "{";
    for (auto vertex : remainingVertices)
    {
        cout << vertex << ",";
    }
    cout << "}]" << endl;
    cout << maxFlow << endl;

    return 0;
}

/*
A minimum cut can be found after performing a maximum flow computation using the Ford-Fulkerson method.
One possible minimum cut is the following: the set of all the vertices that can be reached from  
s in the residual graph (using edges with positive residual capacity), and the set of all the other vertices.
This partition can be easily found using DFS starting at s .
*/