#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
int wt[105], val[105];
long long dp[105][100005];


long long func(int index, int value_left)
{
    if(value_left == 0)
    {
        return 0;
    }
    if(index < 0)
    {
        return 1e5;
    }
    if(dp[index][value_left] != -1)
    {
        return dp[index][value_left];
    }
    long long ans = func(index-1, value_left);
    if(value_left - val[index] >= 0)
    {   
        long long withItem = func(index - 1, value_left - val[index]) + wt[index];
        ans = min(ans, func(index - 1 , value_left - val[index]) + wt[index]);
    }
    return dp[index][value_left] = ans;
}
void getall(int n, int w)
{
    long long max_val = 60000;
    long long c;
    for(long long i = max_val; i >= 0; --i)
    {
        if(func(n-1, i) <= w)
        {
            cout << i << endl;
            c = i;
            break;
        }
    }
    int temp = c;
    vector<int> selectedItems;
    
    for(int i = n-1; i > 0; i--)
    {
        if(dp[i][temp] != dp[i-1][temp])
        {
            selectedItems.push_back(i+1);
            temp -= val[i];
        }
    }
    int nn = 0;
    cout << selectedItems.size() << endl;
    for(int i = 0; i < selectedItems.size(); i++)
    {
        cout << selectedItems[i] << " ";
        nn = nn + val[selectedItems[i]-1];
    }
    //cout << nn << " " << c <<endl;
    if(nn != c)
    {
        cout << "1"<<endl;
    }
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n, w;
    cin >> n >> w;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> val[i] >> wt[i];
        arr[i] = val[i];
    }
    int max = 0;
    for(int i = 0; i < n; i++)
    {
        if(val[i] > max)
        {
            max = val[i];
        }
    }
    //cout << max << endl;
    long long max_val = max * n;
    long long c;
    for(long long i = max_val; i >= 0; --i)
    {
        if(func(n-1, i) <= w)
        {
            cout <<"Answer: "<< i << endl;
            c = i;
            break;
        }
    }
    int temp = c;
    vector<int> selectedItems;
    
    for(int i = n-1; i > 0; i--)
    {
        if(dp[i][temp] != dp[i-1][temp])
        {
            selectedItems.push_back(i+1);
            temp -= val[i];
        }
    }
    int nn = 0;
    int wtsum = 0;
    cout << "Indices: " ;
    for(int i = 0; i < selectedItems.size(); i++)
    {
        cout << selectedItems[i] << " ";
        nn = nn + val[selectedItems[i]-1];
        wtsum = wtsum + wt[selectedItems[i] - 1];
    }
    
    if(nn != c)
    {
        wtsum = wtsum + wt[selectedItems[0]];
        cout << "1"<<endl;
    }
    cout << "Used weight: " << wtsum << endl;
    memset(dp, -1, sizeof(dp));
    // 0.5, 0.2, 0.1, 
    vector<double> epsilon ={0.05};
    for(double ep : epsilon){
        cout << "Rounded Instance with Eps: "<< ep <<endl; 
    long double theta = (ep * max) / (2 * n);
    cout <<"Theta: "<< theta << endl;
    for(int i = 0; i < n; i++)
    {
        val[i] = ceil(val[i]/theta);
    }
    max = 0;
    for(int i = 0; i < n; i++)
    {
        if(val[i] > max)
        {
            max = val[i];
        }
    }
    max_val = n * max;
    for(long long i = max_val; i >= 0; --i)
    {
        if(func(n-1, i) <= w)
        {
            cout <<"Answer of reduced instance: "<< i << endl;
            c = i;
            break;
        }
    }
    cout<<"Answer of reduced instance multiplied by theta: "<< theta*c << endl;
    
    int temp2 = c;
    vector<int> selectedItems2;
    
    int wtsum2 = 0;
    for(int i = n-1; i > 0; i--)
    {
        if(dp[i][temp2] != dp[i-1][temp2])
        {
            selectedItems2.push_back(i+1);
            temp2 -= val[i];
        }
    }
    int nn2 = 0;
    int mm2 = 0;
    
    cout << "Indices: ";
    for(int i = 0; i < selectedItems2.size(); i++)
    {
        cout << selectedItems2[i] << " ";
        nn2 = nn2 + val[selectedItems2[i]-1];
        mm2 = mm2 + arr[selectedItems2[i]-1];
        wtsum2 = wtsum2 + wt[selectedItems2[i]-1];
        
    }
    
    if(nn2 != c)
    {
        wtsum2 = wtsum2 + wt[0];
        mm2 = mm2 + arr[0];
        cout << "1"<<endl;
    }
    cout<<"Answer of original instance(Rounded Up): " << mm2 << endl;
    cout<<"Used weight: "<<wtsum2 <<endl;
    long double r = (theta * c) / mm2;
    cout <<"Ratio: "<< r << endl;
    }
    
}