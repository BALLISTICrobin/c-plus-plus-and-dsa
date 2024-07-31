#include <iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges; //wt, u, v
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({wt, {u, v}});
    }
    int source;
    cin >> source;
    vector<int> distFromSource(n, 1e8);
    distFromSource[source] = 0;
    vector<int> parent1(n, -1);
    for (int i = 0; i < n - 1; i++) //applying bellman ford
    {
        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (distFromSource[u] != 1e8 && distFromSource[u] + wt < distFromSource[v])
            {
                distFromSource[v] = distFromSource[u] + wt;
                parent1[v] = u;
            }
        }
    }
    int idx;
    vector<int> parent2(n, -1);
    int minimumTime = 1e8;
    for (int i = 0; i < n; i++) //check one by one for all the nodes and find the minimum time
    {
        if (i != source) //cant be applied on source
        {
            vector<int> distFromDestination(n, 1e8);
            distFromDestination[i] = 0;
            for (int j = 0; j < n - 1; j++)
            {
                for (auto it : edges)
                {
                    int wt = it.first;
                    int u = it.second.first;
                    int v = it.second.second;
                    if (distFromDestination[u] != 1e8 && distFromDestination[u] + wt < distFromDestination[v])
                    {
                        distFromDestination[v] = distFromDestination[u] + wt;
                    }
                }
            }
            int time = distFromSource[i] + distFromDestination[source]; //total time 
            if (time < minimumTime)
            {
                minimumTime = time; //if its minumum than previous time then update it
                idx = i; //store the index of the node
            }
        }
    }
    cout << minimumTime << endl;
    cout<<"Paths:"<<endl;
    stack<int> st1; //use stack to print the path in correct order
    int current = idx; //source to destination
    while (current != -1)
    {
        st1.push(current);
        current = parent1[current];
    }
    while (!st1.empty()) //print the path of source to destination
    {
        cout << st1.top();
        if (st1.size() != 1)
        {
            cout << "->";
        }
        st1.pop();
    }
    cout <<" (time: "<<distFromSource[idx]<<")"<<endl;
    vector<int> distFromDestination(n, 1e8);
    distFromDestination[idx] = 0;
    for (int j = 0; j < n - 1; j++) //Apply bellman ford once more inorder to find the path from destination to source
    {
        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (distFromDestination[u] != 1e8 && distFromDestination[u] + wt < distFromDestination[v])
            {
                distFromDestination[v] = distFromDestination[u] + wt;
                parent2[v] = u;
            }
        }
    }
    stack<int> st2;
    int current2 = source;
    while (current2 != -1)
    {
        st2.push(current2);
        current2 = parent2[current2];
    }
    while (!st2.empty()) //print the path from destination to source
    {
        cout << st2.top();
        if (st2.size() != 1)
        {
            cout << "->";
        }
        st2.pop();
    }
    cout <<" (time: "<<distFromDestination[source]<<")"<<endl;
}
