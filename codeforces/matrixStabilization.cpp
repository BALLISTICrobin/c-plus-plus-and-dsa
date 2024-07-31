#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    ll test;
    cin >> test;
    while (test--)
    {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll> > v(n + 1, vector<ll>(m + 1));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> v[i][j];
            }
        }
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                bool strictlyGreater = false;
                bool n1 = true;
                bool n2 = true;
                bool n3 = true;
                bool n4 = true;
                ll maxValue = -1e9;
                if (i + 1 <= n )
                {
                    if(v[i+1][j] < v[i][j])
                    {
                        maxValue = max(maxValue,v[i+1][j]);
                    }
                    else
                    {
                        n1 = false;
                    }
                    
                }
                if(j + 1 <= m)
                {
                    if(v[i][j+1] < v[i][j])
                    {
                        maxValue = max(maxValue,v[i][j+1]);
                    }
                    else
                    {
                        n2 = false;
                    }
                }
                if(i - 1 >= 1)
                {
                    if(v[i-1][j] < v[i][j])
                    {
                        maxValue = max(maxValue,v[i-1][j]);
                    }
                    else
                    {
                        n3 = false;
                    }
                }
                if(j - 1 >= 1)
                {
                    if(v[i][j-1] < v[i][j])
                    {
                        maxValue = max(maxValue,v[i][j-1]);
                    }
                    else
                    {
                        n4 = false;
                    }
                }
                
                strictlyGreater = n1 && n2 && n3 && n4;
                if (strictlyGreater)
                {
                    v[i][j] = maxValue;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
