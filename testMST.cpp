#include <iostream>
#include <list>
#include <queue>
#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

class Graph
{
    unordered_map<int, list<pair<int, int>>> adjList;
    int V;
    int E;
    vector<vector<int>> edgeLog;
    vector<int> criticalEdges;
    vector<int> pseudoCriticalEdges;

    list<pair<int, int>> MST;

public:
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
        edgeLog.resize(E, vector<int>(3, 0));
        int index = 0;
        for (int i = 0; i < E; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> temp = {u, v, w};
            edgeLog[index] = temp;
            adjList[u].push_back(make_pair(v, w));
            adjList[v].push_back(make_pair(u, w));
            index++;
        }
    }

    int primsAlgo(int index)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Qp;
        int destination,src;
        if (index != -1)
        {
            destination = edgeLog[index][1];
            src = edgeLog[index][0];
        }

        vector<int> parentP(V, -1);
        vector<int> MSTvisitedP(V, 0);
        Qp.push(make_pair(0, 0));

        int MSTcost = 0;

        while (!Qp.empty())
        {
            pair<int, int> p = Qp.top();
            Qp.pop();

            if (MSTvisitedP[p.second] == 1)
                continue; // if already visited (if already in MST)
            int u = p.second;
            int weight = p.first;
            MSTvisitedP[u] = 1;
            MSTcost += weight;

            if (parentP[u] != -1 && index == -1)
            {
                MST.push_back(make_pair(parentP[u], u));
            }

            for (auto i : adjList[u])
            {
                if (index == -1)
                {
                    if (MSTvisitedP[i.first] == 0)
                    {
                        Qp.push(make_pair(i.second, i.first));
                        parentP[i.first] = u;
                    }
                }
                else
                {
                    if (MSTvisitedP[i.first] == 0 && !((src == u && destination == i.first) || (destination == u && src == i.first)))
                    {
                        Qp.push(make_pair(i.second, i.first));
                        parentP[i.first] = u;
                    }
                }
            }
        }

        return MSTcost;
    }

    bool checkInMst(int index)
    {
        int src = edgeLog[index][0];
        int destination = edgeLog[index][1];
        for (auto i : MST)
        {
            if ((i.first == src && i.second == destination) || (i.first == destination && i.second == src))
            {
                return true;
            }
        }
        return false;
    }

    void checkCriticalAndPseudoCriticalEdges(int cost)
    {
        for (int index = 0; index < E; index++)
        {
            bool CheckInMst = checkInMst(index);
            if (cost < primsAlgo(index) && CheckInMst == true)
            {
                criticalEdges.push_back(index);
            }
            else if (cost == primsAlgo(index) && CheckInMst == true)
            {
                pseudoCriticalEdges.push_back(index);
            }
        }
    }

    void printCriticalAndPseudoCriticalEdges()
    {
        cout << "Critical Edges: [";
        for (auto i : criticalEdges)
        {
            cout << i << " ";
        }
        cout << "]" << endl;
        cout << "Pseudo Critical Edges: [";
        for (auto i : pseudoCriticalEdges)
        {
            cout << i << " ";
        }
        cout << "]" << endl;
    }
};

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges:" << endl;
    cin >> V >> E;
    Graph G(V, E);

    int cost = G.primsAlgo(-1);
    cout << "cost: " << cost << endl;
    G.checkCriticalAndPseudoCriticalEdges(cost);
    G.printCriticalAndPseudoCriticalEdges();
    return 0;
}

/*
#include "dsa_MSTgraph.cpp"

// Renamed function for generating spanning trees
void generateSpanningTrees(int index, int num_of_edges, int no_of_vertices, const vector<pair<pair<int, int>, int>>& edges, vector<vector<pair<pair<int, int>, int>>>& all_spanning_trees, vector<pair<pair<int, int>, int>>& possible_tree) {
    if (index == num_of_edges) {
        if (possible_tree.size() == no_of_vertices - 1) {
            all_spanning_trees.push_back(possible_tree);
        }
        return;
    }
    possible_tree.push_back(edges[index]);
    generateSpanningTrees(index + 1, num_of_edges, no_of_vertices, edges, all_spanning_trees, possible_tree);
    possible_tree.pop_back();
    generateSpanningTrees(index + 1, num_of_edges, no_of_vertices, edges, all_spanning_trees, possible_tree);
}

// Renamed function to check if a graph is connected
bool isConnectedGraph(int no_of_vertices, const vector<pair<pair<int, int>, int>>& possible_tree) {
    unordered_map<int, list<pair<int, int>>> adjList2;
    
    for (const auto& edge : possible_tree) {
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;
        
        adjList2[u].push_back({v, w});
        adjList2[v].push_back({u, w});
    }

    vector<int> vis(no_of_vertices, 0);
    int count = 0;
    for (int i = 0; i < no_of_vertices; ++i) {
        if (!vis[i]) {
            count++;
            dfs(i, adjList2, vis);
        }
    }
    return count == 1;
}

int main(int argc, char const* argv[]) {
    int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;
    
    Graph g(num_vertices, num_edges);
    vector<pair<int, int>> MST = g.minSpanningTree();
    int minCost = g.MSTcost;

    vector<vector<pair<pair<int, int>, int>>> all_spanning_trees;
    vector<pair<pair<int, int>, int>> possible_tree;
    generateSpanningTrees(0, num_edges, num_vertices, g.edgeLog, all_spanning_trees, possible_tree);

    vector<vector<pair<pair<int, int>, int>>> all_possible_spanning_trees;
    for (const auto& tree : all
*/


/*
kruskals algo:
// C++ program for the above approach 

#include <bits/stdc++.h> 
using namespace std; 

// DSU data structure 
// path compression + rank by union 
class DSU { 
	int* parent; 
	int* rank; 

public: 
	DSU(int n) 
	{ 
		parent = new int[n]; 
		rank = new int[n]; 

		for (int i = 0; i < n; i++) { 
			parent[i] = -1; 
			rank[i] = 1; 
		} 
	} 

	// Find function 
	int find(int i) 
	{ 
		if (parent[i] == -1) 
			return i; 

		return parent[i] = find(parent[i]); 
	} 

	// Union function 
	void unite(int x, int y) 
	{ 
		int s1 = find(x); 
		int s2 = find(y); 

		if (s1 != s2) { 
			if (rank[s1] < rank[s2]) { 
				parent[s1] = s2; 
			} 
			else if (rank[s1] > rank[s2]) { 
				parent[s2] = s1; 
			} 
			else { 
				parent[s2] = s1; 
				rank[s1] += 1; 
			} 
		} 
	} 
}; 

class Graph { 
	vector<vector<int> > edgelist; 
	int V; 

public: 
	Graph(int V) { this->V = V; } 

	// Function to add edge in a graph 
	void addEdge(int x, int y, int w) 
	{ 
		edgelist.push_back({ w, x, y }); 
	} 

	void kruskals_mst() 
	{ 
		// Sort all edges 
		sort(edgelist.begin(), edgelist.end()); 

		// Initialize the DSU 
		DSU s(V); 
		int ans = 0; 
		cout << "Following are the edges in the "
				"constructed MST"
			<< endl; 
		for (auto edge : edgelist) { 
			int w = edge[0]; 
			int x = edge[1]; 
			int y = edge[2]; 

			// Take this edge in MST if it does 
			// not forms a cycle 
			if (s.find(x) != s.find(y)) { 
				s.unite(x, y); 
				ans += w; 
				cout << x << " -- " << y << " == " << w 
					<< endl; 
			} 
		} 
		cout << "Minimum Cost Spanning Tree: " << ans; 
	} 
}; 

// Driver code 
int main() 
{ 
	Graph g(4); 
	g.addEdge(0, 1, 10); 
	g.addEdge(1, 3, 15); 
	g.addEdge(2, 3, 4); 
	g.addEdge(2, 0, 6); 
	g.addEdge(0, 3, 5); 

	// Function call 
	g.kruskals_mst(); 

	return 0; 
}

*/