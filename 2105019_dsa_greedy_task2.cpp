#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class RailwayStation{
    int platform;
    int numOfTrains;
    priority_queue<int,vector<int>,greater<int>> departureTime;
    vector<pair<int,int>> schedule;

    public:
    RailwayStation(int numOfTrains){
        platform=0;
        this->numOfTrains = numOfTrains;
        for(int i=0; i<numOfTrains; i++){
            int start,end;
            cin>>start>>end;
            pair<int,int> time = make_pair(start,end);
            schedule.push_back(time);
        }
    }
    ~RailwayStation(){}

    int findTotalPlatforms(){
        sort(schedule.begin(),schedule.end());
        departureTime.push(schedule.at(0).second);
        platform++;
        for(int i=1; i<numOfTrains; i++){
            if(schedule.at(i).first<=departureTime.top()){
                platform++;
                
            }
            else{
                departureTime.pop();
                
            }
            departureTime.push(schedule.at(i).second);

        }
        return platform;
    }
};

int main(int argc, char const *argv[])

{
    // freopen("in_greedy.txt","r", stdin);
    // freopen("out_greedy.txt","w",stdout);
    int numOfTrains;
    cin>>numOfTrains;
    RailwayStation trainStation(numOfTrains);
    cout<<"Total number of platforms needed: "<<trainStation.findTotalPlatforms()<<endl;
    
    return 0;
}
