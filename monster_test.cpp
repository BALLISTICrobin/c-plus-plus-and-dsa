#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Custom comparator for the priority queue to get the largest health first
struct CompareMonster {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first)
            return a.second > b.second; // Smaller index comes first if health is equal
        return a.first < b.first; // Larger health comes first
    }
};

// Function to find the order in which monsters die
vector<int> findMonsterOrder(int n, int k, vector<int>& healthPoints) {
    vector<int> deathOrder;
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareMonster> pq;

    // Push all monsters into the priority queue
    for (int i = 0; i < n; ++i) {
        pq.push(make_pair(healthPoints[i], i + 1));
    }

    while (!pq.empty()) {
        int damage = min(k, pq.top().first); // Calculate the damage dealt by the ability
        vector<pair<int, int>> temp; // Temporary storage for monsters whose health has changed

        while (!pq.empty() && pq.top().first <= damage) {
            temp.push_back(pq.top()); // Store monsters whose health is less than or equal to damage
            pq.pop();
        }

        if (!pq.empty()) {
            pair<int, int> topMonster = pq.top();
            pq.pop();
            topMonster.first -= damage; // Update the health after damage
            temp.push_back(topMonster); // Push the updated monster back into the temporary storage
        }

        // Push the monsters back into the priority queue (with updated health)
        for (const auto& monster : temp) {
            if (monster.first > 0) {
                pq.push(monster);
                deathOrder.push_back(monster.second); // Store the index of the dying monster
            }
        }
    }

    return deathOrder;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> healthPoints(n);

        for (int i = 0; i < n; ++i) {
            cin >> healthPoints[i];
        }

        vector<int> deathOrder = findMonsterOrder(n, k, healthPoints);

        // Print the order in which monsters die for this test case
        for (int i = 0; i < n; ++i) {
            cout << deathOrder[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
