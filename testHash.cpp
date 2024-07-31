#include <iostream>
#include <string>
using namespace std;

int main()
{
    // string k = "hello";
    // char *key = (char *)k.c_str();
    const char *str = "Hello, World!";
    unsigned long hash = 5381; // Initial value recommended by djb2
    int c;

    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    cout << hash << endl;

    string key = "hello world";

    long long hashVal = 0;

    for (long long i = 0; i < key.length(); i++)
        hashVal = 37 * hashVal + key[i];

   cout<< hashVal;

    return 0;
}
