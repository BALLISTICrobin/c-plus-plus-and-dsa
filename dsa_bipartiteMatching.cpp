#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#include<math.h>
#include<algorithm>

using namespace std;
bool BFS(vector<vector<int>> &residualCapacity,vector<int> &parent,int source,int sink){
    bool foundAugmentedPath = false;
    queue<int> Q;
    vector<int> visited(residualCapacity.size(),0);
    Q.push(source);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int v =1; v<residualCapacity.size(); v++){
            if(visited[v]==0 && residualCapacity[u][v]>0){
                parent[v] = u;
                visited[v] = 1;
                Q.push(v); 
                if(v==sink)
                {
                    foundAugmentedPath = true;
                    break;
                }
            }
        }
    }
    return foundAugmentedPath;
}

int Ford_Fulkerson(vector<vector<int>> capacity,int s, int t){
    vector<vector<int>> residualCapacity(capacity.size(),vector<int>(capacity.size(),0));
    for(int i=0; i<capacity.size(); i++){
        for(int j=0; j<capacity.size(); j++){
            residualCapacity[i][j] = capacity[i][j];
        }
    }
    // cout<<residualCapacity.size()<<endl;
    vector<int> parent(capacity.size(),-1);
    int maxFlow = 0;
    while(BFS(residualCapacity,parent,s,t)){
        int flow = INT_MAX;
        int sink = t;
        while(sink!=s){
            int par = parent[sink];
            flow = min(flow, residualCapacity[par][sink]);
            sink = par;
        }

        maxFlow += flow;

        int v = t;
        while(v!=s){
            int par = parent[v];
            residualCapacity[par][v] -= flow;
            residualCapacity[v][par] +=flow;
            v = par;
        }
    }
   
    return maxFlow;

}
int main(int argc, char const *argv[])
{
    int men,women;
    cin>>men>>women;
    vector<vector<int>> man;
    vector<vector<int>> woman;
    for(int i=0; i<men; i++){
        int height,age,devorcedStat;
        cin>>height>>age>>devorcedStat;
        vector<int> manStat;
        manStat.push_back(height);
        manStat.push_back(age);
        manStat.push_back(devorcedStat);
        man.push_back(manStat);
    }

    for(int i=0; i<women; i++){
        int height,age,devorcedStat;
        cin>>height>>age>>devorcedStat;
        vector<int> womanStat;
        womanStat.push_back(height);
        womanStat.push_back(age);
        womanStat.push_back(devorcedStat);
        woman.push_back(womanStat);
    }

    vector<vector<int>> capacity(men+women+2,vector<int>(men+women+2,0));

    for(int i=0; i<men; i++){
        for(int j=0; j<women; j++){
            if(abs(man[i][0]-woman[j][0])<=10 && abs(man[i][1]-woman[j][1])<=5 && man[i][2]==woman[j][2])
            capacity[i+1][men+j+1] = 1;
        }
    }

    for(int i=1; i<=men; i++){
        capacity[0][i] = 1;
    }

    for(int i=men+1; i<=men+women; i++){
        capacity[i][men+women+1] = 1;
    }

    cout<<Ford_Fulkerson(capacity,0,men+women+1);
    return 0;
}
