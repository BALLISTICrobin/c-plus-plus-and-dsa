#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <sstream>
#include <string>
using namespace std;
class stronglyConnectedCompound
{
    map<int, set<int>> adjList, adj_transpose;
    vector<bool> visited;
    vector<int> scc;
    stack<int> topOrder;
    map<char, bool> result;
    vector<list<int>> compound;
    bool satisfiable = true;
    int clauseNo;

public:
    stronglyConnectedCompound(int value)
    {
        clauseNo = value;
    }
    void addClause(int a, bool aBool, int b, bool bBool)
    {
        int x = a;
        int not_x = a + 1;
        int y = b;
        int not_y;
        if (y != 0)
        {
            not_y = b + 1;
        }

        if (y == 0 && aBool == false)
        {
            adjList[not_x].insert(x);
            adj_transpose[x].insert(not_x);
        }
        else if (y == 0 && aBool == true)
        {
            adjList[x].insert(not_x);
            adj_transpose[not_x].insert(x);
        }

        else if (aBool == false && bBool == false)
        {
            adjList[not_x].insert(y);
            adjList[not_y].insert(x);
            adj_transpose[y].insert(not_x);
            adj_transpose[x].insert(not_y);
        }
        else if (aBool == false && bBool == true)
        {
            adjList[not_x].insert(not_y);
            adjList[y].insert(x);
            adj_transpose[not_y].insert(not_x);
            adj_transpose[x].insert(y);
        }
        else if (aBool == true && bBool == false)
        {
            adjList[x].insert(y);
            adjList[not_y].insert(not_x);
            adj_transpose[y].insert(x);
            adj_transpose[not_x].insert(not_y);
        }
        else if (aBool == true && bBool == true)
        {
            adjList[x].insert(not_y);
            adjList[y].insert(not_x);
            adj_transpose[not_y].insert(x);
            adj_transpose[not_x].insert(y);
        }
    }
    void dfs(int listElement, vector<bool> &visited)
    {
        visited[listElement] = true;
        for (auto neighbour : adjList[listElement])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, visited);
            }
        }
        topOrder.push(listElement);
    }
    void topSort()
    {
        vector<bool> visited(100, false);
        // dfs(adjList.begin()->first,visited);
        for (auto element : adjList)
        {
            if (!visited[element.first])
            {
                dfs(element.first, visited);
            }
        }
    }
    void dfsForScc(int listElement, list<int> &comp, int k)
    {
        // visited[listElement] = true;
        scc[listElement] = k;
        comp.push_back(listElement);

        for (auto neighbour : adj_transpose[listElement])
        {

            if (scc[neighbour] == -1)
            {
                dfsForScc(neighbour, comp, k);
            }
        }
    }
    bool satSolve()
    {
        topSort();

        int k = 1;
        scc.assign(100, -1);
        while (!topOrder.empty())
        {
            int element = topOrder.top();
            topOrder.pop();
            if (scc[element] == -1)
            {
                list<int> comp;

                dfsForScc(element, comp, k);
                // for(auto i:comp){
                //     cout<<i<<",";
                // }
                // cout<<endl;
                k++;
                compound.push_back(comp);
            }
        }

        // check satisfiability
        if (checkSatisfiable() == false)
        {
            return false;
        }
        else
        {
            truthValueAssignment();
            return true;
        }
    }
    bool checkSatisfiable()
    {
        for (int i = 1; i <= 52; i += 2)
        {
            if (scc.at(i) != -1)
            {
                if (scc.at(i) == scc.at(i + 1))
                    return false;
            }
        }
        return true;
    }
    void truthValueAssignment()
    {
        for (int i = 1; i <= 52; i += 2)
        {
            if (scc.at(i) != -1)
            {
                if (scc.at(i) < scc.at(i + 1))
                    result['a' + (i - 1) / 2] = false;
                else
                    result['a' + (i - 1) / 2] = true;
            }
        }
    }
    void printTruthValues()
    {
        for (auto i : result)
        {
            cout << i.first <<" "<< (i.second ? "true" : "false") << endl;
            
        }
    }
    // void printAdjListTranspose()
    // {
    //     for (auto i : adj_transpose)
    //     {
    //         cout << i.first << ":";
    //         for (auto j : i.second)
    //         {
    //             cout << j << ",";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
};

int main(int argc, char const *argv[])
{
    freopen("in99_.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int numOfClauses;
    // cout << "enter total number of clauses: ";
    cin >> numOfClauses;
    cin.ignore();
    stronglyConnectedCompound scc(numOfClauses);

    while (numOfClauses--)
    {
        string clause;
        getline(cin, clause);
        int len = clause.length();
        stringstream ss(clause);
        vector<int> value(2, 0);
        vector<bool> inverse(2, false);
        string operand;
        int x = 0;
        while (ss >> operand)
        {
            if (operand.length() == 1)
            {
                value[x] = 2 * (operand.at(0) - 'a') + 1;
                inverse[x] = false;
            }
            else if (operand.length() == 2)
            {
                value[x] = 2 * (operand.at(1) - 'a') + 1;
                inverse[x] = true;
            }
            // cout<<value[x]<<endl;
            x++;
        }

        scc.addClause(value[0], inverse[0], value[1], inverse[1]);
    }
    // scc.printAdjListTranspose();
    if (scc.satSolve())
    {
        scc.printTruthValues();
    }
    else
        cout << "no assignment is possible" << endl;

    return 0;
}