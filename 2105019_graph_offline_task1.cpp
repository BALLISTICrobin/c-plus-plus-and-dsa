#include"graph.hpp"

int main(int argc, char const *argv[])
{
    // freopen("graphinput.txt","r",stdin);
    // freopen("graphOutput.txt","w",stdout);
    Graph g;
    
    int numOfVertices,numOfEdges;
    cin>>numOfVertices>>numOfEdges;
    g.setNumOfEdges(numOfEdges);
    g.setNumOfVertices(numOfVertices);
    int edge =0;
    while(edge<numOfEdges){
        int startingVertex,endVertex;
        cin>>startingVertex>>endVertex;
        g.addEdge(startingVertex,endVertex);
        edge++;
    }
    int src,dest;
    cin>>src>>dest;
    pair<pair<bool,int>,stack<int>> res = g.isAnyPathByBFS(src,dest);
    if(res.first.first){
        cout<<res.first.second<<endl;
        while(!res.second.empty()){
            cout<<res.second.top()<<" ";
            res.second.pop();
        }
        cout<<endl;
    }
    else
    cout<<-1<<endl;
    return 0;
}
