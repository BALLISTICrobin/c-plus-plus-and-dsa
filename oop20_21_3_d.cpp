#include<iostream>
#include<iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    cout<<setiosflags(ios::left)<<setprecision(3)<<fixed<<setfill('%')<<setw(9)<<123.45678;
    return 0;
}
