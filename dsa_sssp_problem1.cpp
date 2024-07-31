#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
#include <list>

#define INF INT_MAX

using namespace std;

int dijkstra(int s, int e, int c, priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> &Q,
             unordered_map<int, list<pair<int, int>>> &adjList, int n, int m, vector<int> &price) {
    int dis[1010][1010];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            dis[i][j] = INF;
        }
    }

    dis[s][0] = 0;

    Q.push(make_pair(0, make_pair(s, 0)));

    while (!Q.empty()) {
        pair<int, pair<int, int>> s = Q.top();
        Q.pop();
        if (dis[s.second.first][s.second.second] < s.first) continue;
        dis[s.second.first][s.second.second] = s.first;
        for (auto p : adjList[s.second.first]) {
            int v = p.first, w = p.second;
            for (int i = c - s.second.second; i >= 0 && s.second.second + i - w >= 0; i--){
                if (dis[v][s.second.second + i - w] > s.first + i * price[s.second.first]) {
                    dis[v][s.second.second + i - w] = s.first + i * price[s.second.first];
                    Q.push({s.first + i * price[s.second.first], {v, s.second.second + i - w}});
                }
            }
                
        }
    }

    int ret = INF;
    for (int i = 0; i <= c; i++) ret = min(ret, dis[e][i]);
    return ret;
}

int main(int argc, char const *argv[]) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> Q;
    unordered_map<int, list<pair<int, int>>> adjList;
    vector<int> price_per_liter;

    int num_of_cities, num_of_roads, max_capacity;
    cin >> num_of_cities >> num_of_roads >> max_capacity;

    price_per_liter.resize(num_of_cities + 1); // Resizing the vector

    vector<int> cost(num_of_cities, INF);
    for (int i = 1; i <= num_of_cities; i++) {
        int temp;
        cin >> temp;
        price_per_liter[i] = temp;
    }

    for (int i = 0; i < num_of_roads; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    int source, destination;
    cin >> source >> destination;

    int dist = dijkstra(source, destination, max_capacity, Q, adjList, num_of_cities, num_of_roads, price_per_liter);

    if (dist == INF) {
        cout << "impossible" << endl;
    } else {
        cout << dist << endl;
    }

    return 0;
}
