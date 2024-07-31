#include <iostream>
#include <list>
#include <queue>
#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

class Graph {

public:
    unordered_map<int, list<pair<int, int>>> adjList;
    int V;
    int E;
    vector<int> parent;
    vector<int> MSTvisited;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    vector<pair<int,int>> MST;
    int MSTcost;
    vector<pair<pair<int,int>,int>> edgeLog;


    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        parent.resize(V+1, -1);
        MSTvisited.resize(V+1, 0);

        
        for(int j =0; j<V; j++){
            int a;
            cin>>a;
            adjList[0].push_back({j+1, a});

        }

        for(int i = 0; i < E; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edgeLog.push_back(make_pair(make_pair(u,v),w));
            adjList[u].push_back(make_pair(v, w));
            adjList[v].push_back(make_pair(u, w));
        }
    }

    vector<pair<int,int>> minSpanningTree() {
        Q.push(make_pair(0, 0));
        
        int cost=0;
        

        while(!Q.empty()) {
            pair<int,int> p = Q.top();
            Q.pop();
            if(MSTvisited[p.second] == 1) continue; // if already visited (if already in MST)
            int u = p.second;
            int weight = p.first;
            MSTvisited[u] = 1;
            cost += weight;
            if(parent[u] != -1) {
                MST.push_back(make_pair(parent[u], u));
            }
            for(auto i: adjList[u]) {
                if(MSTvisited[i.first] == 0) {
                    Q.push(make_pair(i.second, i.first));
                    parent[i.first] = u;
                }
            }
        }
        MSTcost=cost;
        return MST;
    }


};


int main(int argc, char const *argv[])
{
    int v, e;
    cin>>v>>e;
    Graph g(v,e);
    g.minSpanningTree();
    cout<<g.MSTcost<<endl;
    return 0;
}
