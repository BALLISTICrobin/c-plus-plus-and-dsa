#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, index = 0, maxa, maxb, ans;
        cin >> n;
        int a, b;
        while (n--)
        {
            cin >> a >> b;
            index++;
            if (a <= 10)
            {
                maxa = a;
                maxb = b;
                ans = index;
                break;
            }
        }
        while (n--)
        {
            cin >> a >> b;
            index++;

            if (a<=10 && b > maxb)
            {
                maxb = b;
                ans = index;
            }

           
        }
        cout << ans << endl;
    }

    return 0;
}
