#include "dsa_MSTgraph.cpp"

void generateAllPossibleTrees(int index, int num_of_edges, int no_of_vertices, vector<pair<pair<int, int>, int>> &edges, vector<vector<pair<pair<int, int>, int>>> &all_spanning_trees, vector<pair<pair<int, int>, int>> &possible_tree)
{

    if (index == num_of_edges)
    {
        if (possible_tree.size() == no_of_vertices - 1)
        {
            all_spanning_trees.push_back(possible_tree);
        }
        return;
    }
    possible_tree.push_back(edges[index]);
    generateAllPossibleTrees(index + 1, num_of_edges, no_of_vertices, edges, all_spanning_trees, possible_tree);
    possible_tree.pop_back();
    generateAllPossibleTrees(index + 1, num_of_edges, no_of_vertices, edges, all_spanning_trees, possible_tree);
}

void dfs(int node, unordered_map<int, list<pair<int, int>>> adjList2, vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adjList2[node])
    {
        int adjNode = it.first;
        if (!vis[adjNode])
        {
            dfs(adjNode, adjList2, vis);
        }
    }
}

bool isConnectedGraph(int no_of_vertices, const vector<pair<pair<int, int>, int>> &possible_tree)
{
    unordered_map<int, list<pair<int, int>>> adjList2;

    for (const auto &edge : possible_tree)
    {
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;

        adjList2[u].push_back({v, w});
        adjList2[v].push_back({u, w});
    }

    vector<int> vis(no_of_vertices, 0);
    int count = 0;
    for (int i = 0; i < no_of_vertices; ++i)
    {
        if (!vis[i])
        {
            count++;
            dfs(i, adjList2, vis);
        }
    }
    return count == 1;
}

int main(int argc, char const *argv[])
{
    int V, E;

    cin >> V >> E;
    Graph g(V, E);
    vector<pair<int, int>> MST = g.minSpanningTree();
    int minCost = g.MSTcost;
    
    vector<vector<pair<pair<int, int>, int>>> all_spanning_trees;
    vector<pair<pair<int, int>, int>> possible_tree;
    generateAllPossibleTrees(0, E, V, g.edgeLog, all_spanning_trees, possible_tree);

    vector<vector<pair<pair<int, int>, int>>> all_possible_spanning_trees;
    for (int i = 0; i < all_spanning_trees.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < all_spanning_trees[i].size(); j++)
        {
            sum += all_spanning_trees[i][j].second;
        }
        if (sum == minCost)
        {
            all_possible_spanning_trees.push_back(all_spanning_trees[i]);
        }
    }
    vector<vector<pair<pair<int, int>, int>>> all_MSTs;
    vector<int> criticalEdges;
    vector<int> pseudoCriticalEdges;
    
    for(int i = 0; i < all_spanning_trees.size(); i++) {
        int sum = 0;
        for(int j = 0; j < all_spanning_trees[i].size(); j++) {
            sum += all_spanning_trees[i][j].second;
        }
        if(sum == minCost && isConnectedGraph(V, all_spanning_trees[i])) {
            all_MSTs.push_back(all_spanning_trees[i]);
            
        }
    }
    int no_of_MSTs = all_MSTs.size();
    int index=0;
    for (auto edge : g.edgeLog)
    {
        int count = 0;
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;
        for (auto MST : all_MSTs)
        {
            for (auto edge : MST)
            {
                int u1 = edge.first.first;
                int v1 = edge.first.second;
                int w1 = edge.second;
                if ((u == u1 && v == v1) || (u == v1 && v == u1))
                {
                    count++;
                }
            }
        }
        if (count == no_of_MSTs)
        {
            criticalEdges.push_back(index);
        }
        
        else if(count<no_of_MSTs && count>0){
            pseudoCriticalEdges.push_back(index);
        }
        
        index++;
        
    }
    cout<<"Critical Edges:"<<endl;
    cout<<"[";
    for(auto i:criticalEdges){
        cout<<i<<" ";
    }
    cout<<"]"<<endl;
    cout<<"Pseudo Critical Edges:"<<endl;
    cout<<"[";
    for(auto i:pseudoCriticalEdges){
        cout<<i<<" ";
    }
    cout<<"]"<<endl;


    return 0;
}

//write algorithm for finding critical edges and pseudo critical edges


/*
1) finding all MSTS using brute force
2) for each edge 
        i. if the edge is in all MSTs then it is a critical edge
        ii. if the edge is in some MSTs then it is a pseudo critical edge
*/
