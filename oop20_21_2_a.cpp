#include<iostream>
using namespace std;

void space(char c){
    cout<<c<<endl;
}

void space(char c, int num=0){
    cout<<c<<" "<<num<<endl;
}

int main(int argc, char const *argv[])
{
    void (*fp)(char);
    fp=space;
    void (*fp2)(char, int);
    fp2=space;
    fp('a');
    // fp2('b');
    
    return 0;
}
