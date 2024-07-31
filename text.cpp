#include<iostream>
#include<fstream>
using namespace std;



int main(int argc, char const *argv[])
{
    /* code */
    ofstream out("hello.txt");
    out<<"hi"<<" "<<420<<endl;;
    out<<"hello"<<" "<<421<<endl;
    return 0;
}
