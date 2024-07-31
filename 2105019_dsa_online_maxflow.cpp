#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#include<math.h>
#include<algorithm>

using namespace std;
bool BFS(vector<vector<int>> &residualCapacity,vector<int> &parent,int source,int sink){
    bool foundAugapplicantstedPath = false;
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
                    foundAugapplicantstedPath = true;
                    break;
                }
            }
        }
    }
    return foundAugapplicantstedPath;
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
    int applicants,jobs;
    cin>>applicants>>jobs;
    // vector<vector<int>> applicant;
    // vector<vector<int>> job;
    
    
    vector<vector<int>> capacity(applicants+jobs+2,vector<int>(applicants+jobs+2,0));
    getchar();
    for(int i=0; i<jobs; i++){
        //string s;
        // getline(cin,s);
        // // cout<<s<<" ";
        // int j=0;
        // string jobid="";
        // // cout<<jobid<<" ";
        
        // while(s[j]!=' '){
        //     jobid += s[j];
        //     j++;
        // }
        // // cout<<jobid<<" ";
        // int job_id = stoi(jobid);
        // int countSpace =0;
        // for(auto p: s){
        //     if(p==' ')
        //     countSpace++;
        // }
        // int index = jobid.length()+1;
        // for(int m=0; m<countSpace; m++){
        //     string aplId="";
        //     for(; s[index]!=' ' && index<s.length(); index++){
        //         aplId +=s[index];
        //     }
        //     int apl_id = stoi(aplId);
        //     capacity[apl_id][applicants+job_id] = 1;
        //     index++;
        // }

        int jobId,noOfApplicants ;
        cin>>jobId>>noOfApplicants;
        for(int j=0; j<noOfApplicants; j++){
            // cout<<"hi"<<endl;
            int a;
            cin>>a;
            capacity[a][applicants+jobId] = 1;
        }
    }

    
    

    for(int i=1; i<=applicants; i++){
        capacity[0][i] = 1;
    }

    for(int i=applicants+1; i<=applicants+jobs; i++){
        capacity[i][applicants+jobs+1] = 1;
    }

    cout<<Ford_Fulkerson(capacity,0,applicants+jobs+1);
    return 0;
}
