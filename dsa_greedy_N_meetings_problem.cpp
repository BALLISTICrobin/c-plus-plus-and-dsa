#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    vector<pair<int, int>> meetings;
    int numOfMeetings;
    cin >> numOfMeetings;

    while(numOfMeetings--) {
        int start, end;
        cin >> start >> end;
        meetings.push_back(make_pair(start, end)); 
    }

    sort(meetings.begin(), meetings.end(), cmp);

    int counter = 1;
    vector<int> result;
    result.push_back(1);
    
    int end = meetings[0].second; 
    for (int i = 1; i < meetings.size(); i++) {
        if (meetings[i].first > end) {
            counter++;
            end = meetings[i].second;
            result.push_back(i + 1);
        }
    }

    cout << "number of meetings: " << counter << endl;
    cout << "list of meetings: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
