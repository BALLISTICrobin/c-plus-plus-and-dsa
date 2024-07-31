#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
typedef long long ll;

using namespace std;

ll ansFromoriginalInstance = 0;

void solve(vector<ll> weight, vector<ll> value, ll n, ll w, ll maxVal, bool is_approximated, double theta = 0.0, double epsilon = 0.0, vector<ll> value2 = vector<ll>())
{

    vector<vector<ll>> dpTable(n + 1, vector<ll>(maxVal + 1,1e15));
    for (ll item = 0; item <= n; item++)
    {
        dpTable[item][0] = 0;
    }

    for (ll value = 1; value <= maxVal; value++)
    {
        dpTable[0][value] = 1e18;
    }
    vector<vector<vector<ll>>> index(n + 1, vector<vector<ll>>(maxVal + 1, vector<ll>()));
    for (ll item = 1; item <= n; item++)
    {
        for (ll val = 1; val <= maxVal; val++)
        {
            if(val-value[item]>=0){
            if (dpTable[item - 1][val] < weight[item] + dpTable[item - 1][val - value[item]])
            {
                dpTable[item][val] = dpTable[item - 1][val]; // without considering the current item
                index[item][val] = index[item - 1][val];
            }
            else
            {
                dpTable[item][val] = weight[item] + dpTable[item - 1][val - value[item]]; // considering the current item
                index[item][val].push_back(item);
                index[item][val].insert(index[item][val].end(), index[item - 1][val - value[item]].begin(), index[item - 1][val - value[item]].end());
            }
            }
            else
            {
                dpTable[item][val] = dpTable[item - 1][val]; // without considering the current item
                index[item][val] = index[item - 1][val];
            }
        }
    }

    ll ans;
    bool flag =false;
    int itemIndex, valIndex;
    for (ll item = n-1; item >=0; item--)
    {
        for (ll val = maxVal; val>=0; val--)
        {
            if (dpTable[item][val] <= w)
            {
                    ans = val;
                    itemIndex = item;
                    valIndex = val;
                    flag = true;
                    break;
            }
        }
        if(flag==true)
        break;
    }
    if (is_approximated != true)
    {
        ansFromoriginalInstance = ans;
        std::cout << "answer: " << ans << endl;
        ll weightSum = 0;
        std::cout << "indices: ";
        for (ll x : index[itemIndex][valIndex])
        {
            weightSum += weight[x];
            std::cout << x + 1 << " ";
        }
        std::cout << endl
                  << "used weight: " << weightSum << endl;
    }

    else
    {
        cout << "answer of reduced instance: " << ans << endl;
        cout << "Answer of reduced instance multiplied by theta: " << ans * theta << endl;
        cout << "indices: ";
        ll weightSum = 0;
        ll totalValue = 0;
        for (ll x : index[itemIndex][valIndex])
        {
            std::cout << x + 1 << " ";
            weightSum += weight[x];
            totalValue += value2[x];
        }

        cout << "answer of original instance: " << totalValue << endl;
        cout << "used weight: " << weightSum << endl;
        cout << "ratio: " << (double)ansFromoriginalInstance / totalValue << endl;
    }
}

int main(int argc, char const *argv[])
{
    ll n, w;
    cin >> n >> w;

    ll Vmax = 0;

    vector<ll> weight(n), value(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> value[i] >> weight[i];
        if (value[i] > Vmax)
            Vmax = value[i];
    }
    cout<<"Vmax: "<<Vmax<<endl;

    ll maxVal = 0;
    for (ll x : value)
        maxVal += x;
    cout << "original instance: \n";
    solve(weight, value, n, w, maxVal, false);
    //0.5, 0.2,0.1,0.05 
    vector<double> epsilon = {0.5, 0.2,0.1,0.05};
    for (double e : epsilon)
    {
        cout << "Rounded Instance with Eps: " << e << endl;
        double theta = (e * Vmax) /(2*n);
        cout << "theta: " << theta << endl;
        vector<ll> roundedValue(n);
        for (ll i = 0; i < n; i++)
        {
            roundedValue[i] = ceil(value[i] / theta); ;
        }
        ll roundedMaxVal = 0;
        for (ll x : roundedValue)
            roundedMaxVal += x;

        solve(weight, roundedValue, n, w, roundedMaxVal, true, theta, e, value);
    }
    return 0;
}
