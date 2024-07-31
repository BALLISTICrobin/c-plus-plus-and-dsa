#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<algorithm>

#define INF 1e9

using namespace std;


void floyd_warshall(vector<vector<int>> &distMatrix,int n){

    for(int via_city=1; via_city<=n; via_city++){
        for(int i=1; i<=n; i++){
            for(int j=1;j<=n; j++){
                distMatrix[i][j] = min(distMatrix[i][j],distMatrix[i][via_city]+distMatrix[via_city][j]);
            }
        }
    }
}

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first<=b.first;
}

int main(int argc, char const *argv[])
{
    int num_of_cities,num_of_roads;
    cin>>num_of_cities>>num_of_roads;

    unordered_map<int,list<pair<int,int>>> adjList;
    vector<pair<pair<int,int>,int>> edges;
    vector<vector<int>> distMatrix(num_of_cities+1,vector<int>(num_of_cities+1,-1));

    for(int i=0;i<num_of_roads; i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({{u,v},w});
        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
        distMatrix[u][v] = w;
        distMatrix[v][u] = w;
    }


    for(int i=1;i<=num_of_cities;i++){
        for(int j=1;j<=num_of_cities; j++){
            if(i==j)
            distMatrix[i][j]=0;

            else if(distMatrix[i][j] == -1)
            distMatrix[i][j] = INF;
        }
    }

    floyd_warshall(distMatrix,num_of_cities);

    int threshold_cost;
    cin>>threshold_cost;

    vector<pair<int,int>> countCitiesAboveThreshold;

    for(int i=1;i<=num_of_cities; i++){
        int count=0;
        for(int j=0;j<=num_of_cities; j++){
            if(distMatrix[i][j]<=threshold_cost)
            count++;
        }
        countCitiesAboveThreshold.push_back({count,i});
    }

    sort(countCitiesAboveThreshold.begin(),countCitiesAboveThreshold.end(),cmp);

    // for(int i=1;i<=num_of_cities;i++){
    //     for(int j=1;j<=num_of_cities; j++){
    //         cout<<distMatrix[i][j]<<" "; 
    //     }
    //     cout<<endl;
    // }

    int compare = countCitiesAboveThreshold[0].first;
    // cout<<endl;
    for(int i=0;i<num_of_cities; i++){
        // cout<<countCitiesAboveThreshold[i].first<<endl;
        if(countCitiesAboveThreshold[i].first==compare)
        cout<<countCitiesAboveThreshold[i].second<<" ";
    }
    cout<<endl;

    return 0;
}
