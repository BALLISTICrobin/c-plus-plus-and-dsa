
#include <iostream>
using namespace std;

int unboundedKnapsack(int W, int n,vector<int>val, vector<int> wt)
{

    int dp[W + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i <= W; i++)
        for (int j = 0; j < n; j++)
            if (wt[j] <= i)
                dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);

    return dp[W];
}


int main()
{
    int n;
    cin>>n;
    vector<int> weight;
    vector<int> price;
    for(int i=0;i<n; i++){
        int w,p;
        cin>>w>>p;
        weight.push_back(w);
        price.push_back(p);
    }
    int maxW;
    cin>>maxW;

    cout << unboundedKnapsack(maxW, n, price,weight);

    return 0;
}
