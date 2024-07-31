#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int test;
    cin >> test;
    string name = "vika";
    while (test--)
    {
        int n, m;
        cin >> n >> m;
        string text[21];
        for (int i = 0; i < n; i++)
        {
            cin >> text[i];
        }
        int index = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (text[j][i] == name[index])
                {
                    index++;
                    break;
                }
            }
            if (index == 4)
            {
                cout << "yes" << endl;
                break;
            }
        }
        if (index != 4)
        {
            cout << "no" << endl;
        }
    }
    return 0;
}
