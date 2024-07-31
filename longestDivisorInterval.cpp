#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        long long int value;
        cin >> value;

        // priority_queue<int, vector<int>, greater<int>> store;
        // priority_queue<int> interval;

        int count = 0;
        int max_count = 0;
        // store.push(-1);
        for (int i = 1; i <= 100000; i++)
        {
            if (value % i == 0)
            {
               count++;
            }
            else
            {
                if(count>max_count)
                max_count = count;

                count = 0;
            }
        }
        cout<<max_count<<endl;
        

       
    }

    return 0;
}
/*1
2
3
6
4
22
3
1
2
3
6
4
22
3*/