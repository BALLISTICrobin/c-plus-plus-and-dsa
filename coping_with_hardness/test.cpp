#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

typedef long long ll;

using namespace std;

ll ansFromOriginalInstance = 0;

void solve(vector<ll>& weight, vector<ll>& value, ll n, ll w, ll maxVal, bool is_approximated, double theta = 0.0, double epsilon = 0.0, vector<ll> value2 = vector<ll>()) {

    vector<vector<ll>> dpTable(n + 1, vector<ll>(maxVal + 1, INT_MIN));
    for (ll item = 0; item <= n; item++) {
        dpTable[item][0] = 0;
    }

    for (ll val = 1; val <= maxVal; val++) {
        dpTable[0][val] = INT_MIN;
    }

    vector<vector<vector<ll>>> index(n + 1, vector<vector<ll>>(maxVal + 1, vector<ll>()));
    for (ll item = 1; item <= n; item++) {
        for (ll val = 1; val <= maxVal; val++) {
            if (val < value[item - 1] || dpTable[item - 1][val] >= weight[item - 1] + dpTable[item - 1][val - value[item - 1]]) {
                dpTable[item][val] = dpTable[item - 1][val];
                index[item][val] = index[item - 1][val];
            } else {
                dpTable[item][val] = weight[item - 1] + dpTable[item - 1][val - value[item - 1]];
                index[item][val] = index[item - 1][val - value[item - 1]];
                index[item][val].push_back(item - 1);
            }
        }
    }

    ll ans = INT_MIN;
    int itemIndex, valIndex;
    for (ll item = 0; item <= n; item++) {
        for (ll val = 0; val <= maxVal; val++) {
            if (dpTable[item][val] <= w && ans < val) {
                ans = val;
                itemIndex = item;
                valIndex = val;
            }
        }
    }
    if (!is_approximated) {
        ansFromOriginalInstance = ans;
        cout << "answer: " << ans << endl;
        ll weightSum = 0;
        cout << "indices: ";
        for (ll x : index[itemIndex][valIndex]) {
            weightSum += weight[x];
            cout << x + 1 << " ";
        }
        cout << endl << "used weight: " << weightSum << endl;
    } else {
        cout << "answer of reduced instance: " << ans << endl;
        cout << "Answer of reduced instance multiplied by theta: " << ans * theta << endl;
        cout << "indices: ";
        ll weightSum = 0;
        ll totalValue = 0;
        for (ll x : index[itemIndex][valIndex]) {
            cout << x + 1 << " ";
            weightSum += weight[x];
            totalValue += value2[x];
        }

        cout << "answer of original instance: " << totalValue << endl;
        cout << "used weight: " << weightSum << endl;
        cout << "ratio: " << (double)ansFromOriginalInstance / totalValue << endl;
    }
}

int main() {
    ll n, w;
    cin >> n >> w;

    ll Vmax = 0;

    vector<ll> weight(n), value(n);
    for (ll i = 0; i < n; i++) {
        cin >> value[i] >> weight[i];
        if (value[i] > Vmax) {
            Vmax = value[i];
        }
    }
    cout << "Vmax: " << Vmax << endl;

    ll maxVal = 0;
    for (ll x : value) {
        maxVal += x;
    }
    cout << "original instance: \n";
    solve(weight, value, n, w, maxVal, false);
    vector<double> epsilon = {0.5, 0.2, 0.1, 0.05};
    for (double e : epsilon) {
        cout << "Rounded Instance with Eps: " << e << endl;
        double theta = (e * Vmax) / (2 * n);
        cout << "theta: " << theta << endl;
        vector<ll> roundedValue(n);
        for (ll i = 0; i < n; i++) {
            roundedValue[i] = value[i] / theta;
        }
        ll roundedMaxVal = 0;
        for (ll x : roundedValue) {
            roundedMaxVal += x;
        }

        solve(weight, roundedValue, n, w, roundedMaxVal, true, theta, e, value);
    }
    return 0;
}
