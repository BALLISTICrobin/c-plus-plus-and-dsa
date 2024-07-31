#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <climits>
using namespace std;

class Graph
{
    int numOfNodes, numOfEdges;
    map<int, list<int>> adjList;

public:
    void setNumOfEdges(int value)
    {
        this->numOfEdges = value;
    }
    void setNumOfVertices(int value)
    {
        this->numOfNodes = value;
    }
    void addEdge(int vertex1, int vertex2)
    {
        adjList[vertex1].push_back(vertex2);
    }

    void bfs(vector<int> &visited, vector<int> &parent, int vertex1)
    {
        queue<int> q;
        visited[vertex1] = true;
        q.push(vertex1);
        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            for (auto neighbour : adjList[frontNode])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    parent[neighbour] = frontNode;
                    visited[neighbour] = true;
                }
            }
        }
    }
    pair<pair<bool, int>, stack<int>> isAnyPathByBFS(int startingVertex, int endingVertex)
    {
        vector<int> visited(numOfNodes + 1, false);
        vector<int> parent(numOfNodes + 1, -1);
        stack<int> path;
        pair<pair<bool, int>, stack<int>> ans;
        bfs(visited, parent, startingVertex);
        if (visited[endingVertex])
        {
            int current = endingVertex;

            while (current != -1)
            {
                path.push(current);
                current = parent[current];
            }
            ans = make_pair(make_pair(true, path.size() - 1), path);
        }
        else
        {
            ans = make_pair(make_pair(false, INT_MAX), path);
        }
        return ans;
    }
    void dfs(vector<int> &visited, vector<int> &parent, int vertex1)
    {
        visited[vertex1] = true;
        for (auto neighbour : adjList[vertex1])
        {
            if (!visited[neighbour])
            {
                parent[neighbour] = vertex1;
                dfs(visited, parent, neighbour);
            }
        }
    }
    pair<pair<bool, int>, stack<int>> isAnyPathByDFS(int startingVertex, int endingVertex)
    {
        vector<int> visited(numOfNodes + 1, false);
        vector<int> parent(numOfNodes + 1, -1);
        stack<int> path;
        pair<pair<bool, int>, stack<int>> ans;
        dfs(visited, parent, startingVertex);
        if (visited[endingVertex])
        {
            int current = endingVertex;

            while (current != -1)
            {
                path.push(current);
                current = parent[current];
            }
            ans = make_pair(make_pair(true, path.size() - 1), path);
        }
        else
        {
            ans = make_pair(make_pair(false, INT_MAX), path);
        }
        return ans;
    }
};
#endif