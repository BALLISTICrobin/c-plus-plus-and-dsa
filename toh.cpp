#include<iostream>
using namespace std;

void TOH(int n, int start, int goal, int buffer){
    if(n==0){
        return;
    }
    else{
        TOH(n-1,start,buffer,goal);
        cout<<"move from "<<start<<"to "<<goal<<endl;
        TOH(n-1,buffer, goal, start);
    }
}


int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int start =1,goal = 3, buffer =2;
    TOH(n,start,goal,buffer);
    return 0;
}
