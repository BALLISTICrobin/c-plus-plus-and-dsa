#include <iostream>
#include <list>
#include <queue>
#include <map>
#include <vector>

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
            addEdge(node1, node2, 0);
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
        it++;
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
        for (auto i : adj)
        {
            visited[i.first] = false;
        }

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
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    parent[neighbour] = frontNode;
                    q.push(neighbour);
                }
                else if (neighbour != parent[frontNode])
                {
                    return true;
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

    bool isCycle1()
    {
        for (auto i : adj)
        {
            visited[i.first] = false;
        }

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

    bool isCycle2()
    {
        for (auto i : adj)
        {
            visited[i.first] = false;
        }

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
    return 0;
}
