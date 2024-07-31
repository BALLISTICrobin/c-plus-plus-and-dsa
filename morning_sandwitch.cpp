#include <iostream>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int b, c, h;
        cin >> b >> c >> h;
        int z = c + h;
        int count = 1;
        b--;
        while (b != 0 && z != 0)
        {
            b--;
            z--;

            count = count + 2;
        }
        cout << count << endl;
    }
    return 0;
}
