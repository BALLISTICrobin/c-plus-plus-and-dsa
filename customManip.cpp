#include<iostream>
#include<iomanip>

using namespace std;

ostream& MyStyle(ostream &out){
    out<<setw(10)<<setprecision(5)<<fixed<<internal<<showpos<<hexfloat<<showbase;
    return out;
}

int main(int argc, char const *argv[])
{
    cout<<MyStyle<<log(2)<<endl;
    return 0;
}
