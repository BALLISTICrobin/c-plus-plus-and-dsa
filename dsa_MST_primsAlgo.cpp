#include<iostream>
#include<list>
#include<queue>
#include<climits>
#include<unordered_map>
#include<vector>
using namespace std;

class Graph {
    unordered_map<int, list<pair<int, int>>> adjList;
    int V;
    int E;
    vector<int> parent;
    vector<int> MSTvisited;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    list<pair<int,int>> MST;

public:
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        parent.resize(V, -1);
        MSTvisited.resize(V, 0);

        for(int i = 0; i < E; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adjList[u].push_back(make_pair(v, w));
            adjList[v].push_back(make_pair(u, w));
        }
    }

    list<pair<int,int>> minSpanningTree() {
        Q.push(make_pair(0, 0));
        parent[0] = -1;
        MSTvisited[0] = 0;
        int cost=0;
        for(int i = 1; i < V; i++) {
            Q.push(make_pair(INT_MAX, i));
            parent[i] = -1;
            MSTvisited[i] = 0;
        }

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
        cout<<"cost: "<<cost<<endl;
        return MST;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges:" << endl;
    cin >> V >> E;
    Graph g(V, E);
    list<pair<int,int>> MST = g.minSpanningTree();
    for(auto i: MST) {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
