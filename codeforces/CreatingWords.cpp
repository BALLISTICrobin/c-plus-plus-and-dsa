#include<iostream>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int term;
    cin>>term;
    while(term--)
    {
        string s1,s2;
        cin>>s1>>s2;
        char t = s2[0];
        s2[0] = s1[0];
        s1[0] = t;
        cout<<s1<<" "<<s2<<endl;
    }
    
    return 0;
}
