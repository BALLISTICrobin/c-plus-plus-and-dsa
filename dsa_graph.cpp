#include <iostream>
#include <list>
#include <queue>
#include <map>
#include <stack>

using namespace std;

class graph
{
    int num_nodes, num_edges;
    map<int, list<int>> adj;
    map<int, bool> visited;
    map<int, int> parent;

public:
    graph()
    {
        cout << "enter total number of nodes and total number of edges: " << endl;
        cin >> num_nodes >> num_edges;

        for (int i = 0; i < num_edges; i++)
        {
            int node1, node2;
            cout << "enter two nodes to create edge: " << endl;
            cin >> node1 >> node2;
            addEdge(node1, node2, true);
        }
    }
    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == false)
        {
            adj[v].push_back(u);
        }
    }

    void Print()
    {
        for (auto it1 : adj)
        {
            cout << it1.first << "->";

            for (auto it2 : it1.second)
            {
                cout << it2 << ",";
            }
            cout << endl;
        }
    }

    void delEdge(int v1, int v2)
    {
        adj[v1].remove(v2);
        adj[v2].remove(v1);
    }

    bool isEdge(int v1, int v2)
    {
        auto it = adj[v1].begin();

        while (it != adj[v1].end())
        {
            if (*it == v2)
            {
                return true;
            }
            it++;
        }
        return false;
    }
    void breadthFirstSearch(vector<int> &ans, int node)
    {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);

            for (auto i : adj[frontNode])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    vector<int> bfs()
    {
        vector<int> ans;
        // for (auto i : adj)
        // {
        //     visited[i.first] = false;
        // }

        // going to every node of graph
        for (int i = 0; i < num_nodes; i++) // use for loop for any disconnected component
        {                                   // no need to use this loop if there is no disconnected component
            if (!visited[i])
            {
                breadthFirstSearch(ans, i);
            }
        }

        return ans;
    }
    void depthFirstSearch(vector<int> &ans, int node)
    {
        ans.push_back(node);
        visited[node] = true;

        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                depthFirstSearch(ans, i);
            }
        }
    }

    vector<int> dfs()
    {
        vector<int> ans;
        for (auto i : adj)
        {
            visited[i.first] = false;
        }
        for (int i = 0; i < num_nodes; i++) // use for loop for any disconnected component
        {                                   // no need to use this loop if there is no disconnected component
            if (!visited[i])
            {
                depthFirstSearch(ans, i);
            }
        }

        return ans;
    }
    bool chkCycleBFS(int src)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto neighbour : adj[frontNode])
            {
                if (visited[neighbour] && neighbour != parent[frontNode])
                {
                    return true;
                }

                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    parent[neighbour] = frontNode;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }

    bool chkCycleDFS(int node, int prnt)
    {
        visited[node] = true;
        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                parent[neighbour] = node;
                bool cycleDetected = chkCycleDFS(neighbour, node);
                if (cycleDetected)
                    return true;
            }
            else if (neighbour != prnt)
            {
                return true;
            }
        }
        return false;
    }

    // undirected graph
    bool isCycle1()
    {

        for (auto i : adj)
        {
            visited[i.first] = false;
        }
        // default - false;

        for (int i = 0; i < num_nodes; i++)
        {
            if (!visited[i])
            {
                bool ans = chkCycleBFS(i);
                if (ans == true)
                    return true;
            }
        }
        return false;
    }

    // undirected graph
    bool isCycle2()
    {
        for (auto i : adj)
        {
            visited[i.first] = false;
        }
        // default - false;

        for (int i = 0; i < num_nodes; i++)
        {
            if (!visited[i])
            {
                bool ans = chkCycleDFS(i, -1);
                if (ans == true)
                    return true;
            }
        }
        return false;
    }
    // cycle detection for directed graph
    bool chkDirCycleDFS(int node, map<int, bool> &dfsCall)
    {
        visited[node] = true;
        dfsCall[node] = true;

        for (int i : adj[node])
        {
            if (!visited[node])
            {
                bool cycle = chkDirCycleDFS(i, dfsCall);
                if (cycle)
                    return cycle;
            }
            else if (dfsCall[node])
            {
                return true;
            }
        }
        dfsCall[node] = false;
        return false;
    }
    bool isCycleDirected()
    {
        map<int, bool> dfsCall;
        for (auto i : adj)
        {
            visited[i.first] = false;
        }
        // default - false;

        for (int i = 0; i < num_nodes; i++)
        {
            if (!visited[i])
            {
                bool ans = chkDirCycleDFS(i, dfsCall);
                if (ans == true)
                    return true;
            }
        }
        return false;
    }

    void topsortDFS(int node, vector<bool> &visited, stack<int> &store)
    {
        visited[node] = true;

        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                topsortDFS(neighbour, visited, store);
            }
        }
        store.push(node);
    }

    vector<int> topSort()
    {

        vector<bool> visitedNode(num_nodes);
        stack<int> store;
        for (auto i : adj)
        {
            visitedNode[i.first] = false;
        }

        for (int i = 0; i < num_nodes; i++)
        {
            if (!visitedNode[i])
            {
                topsortDFS(i, visitedNode, store);
            }
        }

        vector<int> ans;
        while (!store.empty())
        {
            // cout<<store.top()<<" ";
            ans.push_back(store.top());
            store.pop();
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{

    graph g;

    g.Print();
    cout << "which edge u want to delete? " << endl;
    int node1, node2;
    cin >> node1 >> node2;
    g.delEdge(node1, node2);
    g.Print();
    cout << "check edge: " << endl;
    cin >> node1 >> node2;
    if (g.isEdge(node1, node2))
        cout << "exist" << endl;
    else
        cout << "doesn't exist" << endl;
    vector<int> traversedNodes;
    traversedNodes = g.bfs();
    cout << "bfs traversal: " << endl;
    for (auto i : traversedNodes)
    {
        cout << i << " ";
    }
    cout << endl;
    traversedNodes = g.dfs();
    cout << "dfs traversal: " << endl;
    for (auto i : traversedNodes)
    {
        cout << i << " ";
    }
    cout << endl;

    if (g.isCycle1())
    {
        cout << "this graph has cycle" << endl;
    }
    else
        cout << "there is no cycle in this graph" << endl;
     if (g.isCycle2())
    {
        cout << "this graph has cycle" << endl;
    }
    else
        cout << "there is no cycle in this graph" << endl;
    if (g.isCycleDirected())
    {
        cout << "this graph has cycle" << endl;
    }
    else
        cout << "there is no cycle in this graph" << endl;

    vector<int> topsort;
    topsort = g.topSort();
    for (auto i : topsort)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

//pre and post time in dfs traversal
/*#include <bits/stdc++.h>
using namespace std;

// Variable to keep track of time
int Time = 1;

// Function to perform DFS starting from node u
void dfs(int u, vector<vector<int>> aList,
					vector<int> &pre,
					vector<int> &post,
					vector<int> &vis)
{
	
	// Storing the pre number whenever
	// the node comes into recursion stack
	pre[u] = Time;

	// Increment time
	Time++;
	vis[u] = 1;
	
	for(int v : aList[u])
	{
		if (vis[v] == 0)
			dfs(v, aList, pre, post, vis);
	}

	// Storing the post number whenever
	// the node goes out of recursion stack
	post[u] = Time;
	Time++;
}

// Driver Code
int main()
{
	
	// Number of nodes in graph
	int n = 6;

	// Adjacency list
	vector<vector<int>> aList(n + 1);
	
	vector<int> pre(n + 1);
	vector<int> post(n + 1);

	// Visited array
	vector<int> vis(n + 1);

	// Edges
	aList[1].push_back(2);
	aList[2].push_back(1);
	aList[2].push_back(4);
	aList[4].push_back(2);
	aList[1].push_back(3);
	aList[3].push_back(1);
	aList[3].push_back(4);
	aList[4].push_back(3);
	aList[3].push_back(5);
	aList[5].push_back(3);
	aList[5].push_back(6);
	aList[6].push_back(5);

	// DFS starting at Node 1
	dfs(1, aList, pre, post, vis);

	// Number of nodes in graph
	for(int i = 1; i <= n; i++)
		cout << "Node " << i << " Pre number "
			<< pre[i] << " Post number "
			<< post[i] << endl;

	return 0;
}

*/
/*
scc kosaraju algo see in babbar video
*/