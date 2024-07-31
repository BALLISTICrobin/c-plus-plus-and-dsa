#include"dsa_MSTgraph.cpp"



void generateAllPossibleTrees(int index, int num_of_edges, int no_of_vertices, vector<pair<pair<int,int>,int>>& edges, vector<vector<pair<pair<int,int>,int>>>& all_spanning_trees, vector<pair<pair<int,int>,int>>& possible_tree){
   cout<<index<<endl;
    if(index == num_of_edges){
         if(possible_tree.size() == no_of_vertices-1){
        all_spanning_trees.push_back(possible_tree);
        
    }
    return;
    }
    possible_tree.push_back(edges[index]);
    generateAllPossibleTrees(index+1, num_of_edges, no_of_vertices, edges, all_spanning_trees, possible_tree);
    possible_tree.pop_back();
    generateAllPossibleTrees(index+1, num_of_edges, no_of_vertices, edges, all_spanning_trees, possible_tree);
}

void dfs(int node, unordered_map<int, list<pair<int, int>>>& adjList2, vector<int> &vis) {
    vis[node] = 1;
    for (auto it : adjList2[node]) {
        int adjNode = it.first;
        if (!vis[adjNode]) {
            dfs(adjNode, adjList2, vis);
        }
    }
}

bool isConnected(int no_of_vertices, vector<pair<pair<int,int>,int>>& possible_tree) {
    unordered_map<int, list<pair<int, int>>> adjList2;

    for (int i = 0; i < possible_tree.size(); i++) {
        int u = possible_tree[i].first.first;
        int v = possible_tree[i].first.second;
        int w = possible_tree[i].second;

        adjList2[u].push_back({v, w});
        adjList2[v].push_back({u, w});
    }

    vector<int> vis(no_of_vertices, 0);
    int count = 0;
    for (int i = 0; i < no_of_vertices; i++) {
        if (!vis[i]) {
            count++;
            dfs(i, adjList2, vis);
        }
    }
    if (count == 1) {
        return true; // The graph is connected
    }
    return false; // The graph is not connected
}



int main(int argc, char const *argv[]) {
    int V, E;
    cin >> V >> E;
    
    Graph g(V, E);
    vector<pair<int,int>> MST = g.minSpanningTree();
    int minCost = g.MSTcost;
    cout<<minCost<<endl;

    vector<vector<pair<pair<int,int>,int>>> all_spanning_trees;
    vector<pair<pair<int,int>,int>> possible_tree;
    generateAllPossibleTrees(0, E, V, g.edgeLog, all_spanning_trees, possible_tree);
    
    vector<vector<pair<pair<int,int>,int>>> all_MSTs;
    int serial = 0;
    cout << "MSTs:" << endl;
    // cout<<all_spanning_trees.size()<<possible_tree.size()<<all_MSTs.size()<<endl;
    for(int i = 0; i < all_spanning_trees.size(); i++) {
        int sum = 0;
        for(int j = 0; j < all_spanning_trees[i].size(); j++) {
            sum += all_spanning_trees[i][j].second;
        }
        if(sum == minCost && isConnected(V, all_spanning_trees[i])) {
            all_MSTs.push_back(all_spanning_trees[i]);
            serial++;
            cout << serial << " " << ": " << "[";
            int j;
            for(j = 0; j < all_spanning_trees[i].size() - 1; j++) {
                cout << "[" << all_spanning_trees[i][j].first.first << "," << all_spanning_trees[i][j].first.second << "," << all_spanning_trees[i][j].second << "], ";
            }
            cout << "[" << all_spanning_trees[i][j].first.first << "," << all_spanning_trees[i][j].first.second << "," << all_spanning_trees[i][j].second << "]" << "]" << endl;
        }
    }

    return 0;
}

/*
algorithm:
1. Generate all possible spanning trees(using array subsequence generator)
2. Check if the spanning tree is connected
3. If connected, check if the sum of the weights of the edges is equal to the minimum cost of the MST
4. If yes, then it is an MST
5. Print the MSTs
*/