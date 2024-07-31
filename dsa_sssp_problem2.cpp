#include <iostream>
#include <vector>
#include <climits>
#include<algorithm>
using namespace std;

int bellman_ford(int V, vector<vector<int>>& edges, int S,int e) {
		vector<int> dist(V+1, 1e8);
		dist[S] = 0;
		for (int i = 0; i < V - 1; i++) {
			for (auto it : edges) {
				int u = it[0];
				int v = it[1];
				int wt = it[2];
				if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
				}
			}
		}
		// Nth relaxation to check negative cycle
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
				return INT_MAX;
			}
		}


		return dist[e];
	}


int main(int argc, char const *argv[])
{
    int num_of_nodes,num_of_edges;
    cin>>num_of_nodes>>num_of_edges;

    vector<vector<int>> edges(num_of_edges+1,vector<int>(3));
    for(int i=0; i<num_of_edges; i++){
        int a,b,w;
        cin>>a>>b>>w;
        edges.push_back({a,b,w});
    }

    

    int A,B;
    cin>>A>>B;
    int L,H;
    cin>>L>>H;
    int source,destination;
    cin>>source>>destination;

    int calculated_dist_before_addEdge = bellman_ford(num_of_nodes,edges,source,destination);

    int min_dist = INT_MAX;
    int flag=L-1;
    for(int j=L; j<=H; j++){
        edges.push_back({A,B,j});
        int shortest_path = bellman_ford(num_of_nodes,edges,source,destination);
        // cout<<shortest_path<<endl;
        if(min_dist>shortest_path&& shortest_path != INT_MAX){
            flag = j;
            min_dist = shortest_path;
        }
        edges.pop_back();
    }

    if(min_dist==INT_MAX || min_dist==calculated_dist_before_addEdge){
        cout<<"impossible"<<endl;
    }
    else
    cout<<flag<<" "<<min_dist<<endl;
    return 0;
}
